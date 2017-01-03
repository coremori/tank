/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 9, 2016, 5:38 PM
 *
 * Part of tank */

 /// class Pilote - Run the engine and rendu thread


#include "Pilote.h"
#include "engine/Engine.h"
#include "engine/EngineMode.h"
#include <chrono>
#include <ctime>
#include <thread>
#include "PiloteSFML.h"
#include "ai/AI.h"
#include "ai/HeuristicAI.h"
#include "ai/DumbAI.h"
#include "ai/TreeAI.h"
#include <SFML/Network.hpp>

#include <json/json.h>

#include <iostream>

#include "engine.h"

namespace client{

    
    
    Pilote::Pilote() : engine(&state){
        /* Create the engine from the state
         * Create the CommandSet for the Ai in this computer (Will be taking the CommandSet from the server in the next upgrade)
         */
        command.push_back(new engine::CommandSet());
        command.push_back(new engine::CommandSet());
        http.setHost("http://localhost",8080);
        sf::Http::Request request;
        request.setMethod(sf::Http::Request::Get);
        request.setUri("user");

        sf::Http::Response response = http.sendRequest(request);
        
        if(response.getStatus() != 200){
            std::cout << "Server answers for taking character number Error : " << response.getStatus() << std::endl;
            std::cout << "status: " << response.getStatus() << std::endl;
            std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
            std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
            std::cout << "body: " << response.getBody() << std::endl;
        } else {
        
            Json::Reader jsonReader;
            Json::Value jsonIn;

            if (!jsonReader.parse(response.getBody(),jsonIn))
                    std::cout << "Données invalides: "+jsonReader.getFormattedErrorMessages() << std::endl;
            character = jsonIn["character"].asInt();
        }
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        rendu = new PiloteSFML(&state, &engine,command[0], character, this);      
    }
    
   
    
    
        
    void Pilote::launch() {
        /* Launch the thread for the engine and the render
         * Load the level for the state
         * Create the render Menu
         */
        state.load("res/Levels/level1.txt");
        rendu->createMenu();
        std::thread t1(&Pilote::runRender,this);// the thread for the rendu run in PiloteSFML.display()
        std::thread t2(&Pilote::runEngine,this); // launch run() de l'objet courant (this)*/
        t2.join();
        t1.join();
    }
     
    
    
    
    
    void Pilote::runEngine() {
        /* Thread for the engine
         * Create the Ai for AI mode
         * Every 50ms check the commandSet and update the state
         * */
        int64_t timeNow;
        std::vector<ai::AI*> ai;
        ai.push_back(new ai::HeuristicAI(&state,0));
        ai.push_back(new ai::TreeAI(&state,1));
        //int alreadyplay = 1;
        
        //<<<<<<<<<<<<<<<<<<<<<<<<<<< enregistrer le joueur puis le delete to do
       
        sf::Http::Request request;
        sf::Http::Response response;
        
        
        //std::cout << player << std::endl;
        
        command[0]->add(new engine::MoveCommand(this->character,-8,0));
        
        postCommand(0);
                
                
        getCommand(0,0);

        
        std::cout << "Command for moving : left - right  " << std::endl;
        std::cout << "Command changing direction :  " << std::endl;
        std::cout << "q : left:  " << std::endl;
        std::cout << "z : left-up:  " << std::endl;
        std::cout << "d : right:  " << std::endl;
        std::cout << "e : right-up:  " << std::endl;
        std::cout << "Command for shot : space  " << std::endl;
        std::cout << "Command for ai only : p  " << std::endl;
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< a changer 
        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            
            //if(engine.getMode()==engine::AI && alreadyplay!=engine.getCharTurn()){
                /* In AI mode, and the ai chosen is the Ai who doesn't play the turn before
                 * run create the ai's command list 
                 * takeCommand send these command to the engine (it will be the same for the command from the server)
                 * update the ai to use next turn
                 */
            /*    ai[engine.getCharTurn()]->run(*command[engine.getCharTurn()]);
                engine.takeCommands(command[engine.getCharTurn()]);
                alreadyplay = engine.getCharTurn();
            }
            else if(engine.getMode()==engine::play && engine.getCharTurn()==1){
                * In play mode, this is the ai turn
                *
                *ai[1]->run(*command[1]);
                engine.takeCommands(command[1]);
            }*/
            if(engine.getCharTurn()==character){
                if(command[0]->get(engine::END_CATEGORY)){
                commands_mutex.lock();
                postCommand(character);
                commands_mutex.unlock();
                waitGetCommand(character,character);
                } 
            } else {
                getCommand(character ? 0:1,character);
            }
            
            timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
            engine.update(timeNow,500);
            
        }
        
        
        
        
        
        //<<<<<<<<<<<<<<<<< remove from server
        sf::Http::Request requestDelete;
        requestDelete.setMethod(sf::Http::Request::Delete);
        character ?  requestDelete.setUri("user/1"):requestDelete.setUri("user/0");  
        response = http.sendRequest(requestDelete);
        
        if(response.getStatus()!=200){
            std::cout << "Error delete : " << std::endl;
            std::cout << "status: " << response.getStatus() << std::endl;
            std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
            std::cout << "body: " << response.getBody() << std::endl;
        }
        
        
    }
      
    
    
    
    void Pilote::runRender() {
        /* Thread for the rendu
         * Every 50ms : 
         * Update the change in the state
         * Draw the new display
         * check if a key was pressed
         * */
        while(engine.getMode()!=engine::close)
        {
            rendu->applyChange();
            rendu->display();
            rendu->eventUp();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

        
    bool Pilote::getCommand(int characterAsked, int characterSender) {// direction a faire
        /* Ask the server the command for characterAsked
         * If it can't return false*/
        sf::Http::Request request;
        request.setMethod(sf::Http::Request::Get);
        request.setUri("game");

        sf::Http::Response response = http.sendRequest(request);
        
        
        std::cout << "status: " << response.getStatus() << std::endl;
        std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
        std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
        std::cout << "body: " << response.getBody() << std::endl;
        
        if(response.getStatus() !=  200){
            return false;//impossible de récupérer les commandes
        }
        
        Json::Reader jsonReader;
        Json::Value jsonIn;
        
        if (!jsonReader.parse(response.getBody(),jsonIn))
                std::cout << "Données invalides: "+jsonReader.getFormattedErrorMessages() << std::endl;
        //player = jsonIn["character"].asInt();
        int player = jsonIn["character"].asInt();
        
        if(jsonIn["Xmove"].asInt())
            engine.addCommand(new engine::MoveCommand(player,jsonIn["Xmove"].asInt(),jsonIn["Ymove"].asInt()));
        
        if(jsonIn["Direction"].asInt()){
            switch(jsonIn["Direction"].asInt()){
                case 1:
                    engine.addCommand(new engine::DirectionCommand(player,state::left_down));
                    break;
                case 2:
                    engine.addCommand(new engine::DirectionCommand(player,state::left_up));
                    break;
                case 3:
                    engine.addCommand(new engine::DirectionCommand(player,state::right_down));
                    break;
                case 4:
                    engine.addCommand(new engine::DirectionCommand(player,state::right_up));
                    break;
            }
        }

        if(jsonIn["PowerShot"].asInt())
            engine.addCommand(new engine::ShotCommand(player,jsonIn["PowerShot"].asInt()));
        
        if(jsonIn["Mode"].asInt()){
            switch(jsonIn["Mode"].asInt()){
                case 1:
                    engine.addCommand(new engine::ModeCommand(engine::play));
                    break;
                case 2:
                    engine.addCommand(new engine::ModeCommand(engine::AI));
                    break;
                case 3:
                    engine.addCommand(new engine::ModeCommand(engine::replay));
                default:
                    engine.addCommand(new engine::ModeCommand(engine::play));
                    break;
            }
        }
   /*     if(jsonIn["Mode"].asInt())
            engine.addCommand(new engine::ModeCommand(jsonIn["Mode"].asInt()));
    */       
        engine.addCommand(new engine::EndTurnCommand(this->character));
        return true;;
    }
       
        
    void Pilote::waitGetCommand(int characterAsked, int characterSender) {
        /* Ask the server the command for characterAsked
         * Wait until the server give the command*/
        while(!getCommand(characterAsked,characterSender))
        {
     
        }
    }

    
    
    bool Pilote::postCommand(int characterSender) {
        /* Post the command create by characterSender to the server
         * return false if the server refuse them
         */
        
        sf::Http::Request request;
        request.setMethod(sf::Http::Request::Post);
        request.setUri("game");

        
        Json::Value jsonOut;

        jsonOut["Character"] = characterSender;
        
        if(command[0]->get(engine::VIEW_CATEGORY))
        {
            engine::DirectionCommand* dcmd = dynamic_cast<engine::DirectionCommand*>(command[0]->get(engine::VIEW_CATEGORY));
            jsonOut["Direction"] = dcmd->getDirection();
        }

        if(command[0]->get(engine::MOVE_CATEGORY))
        {
            engine::MoveCommand* move = dynamic_cast<engine::MoveCommand*>(command[0]->get(engine::MOVE_CATEGORY));            
            jsonOut["Xmove"] = move->getXmove();
            jsonOut["Ymove"] = move->getYmove();
        }

        if(command[0]->get(engine::SHOT_CATEGORY))//Shot command
        {
            engine::ShotCommand* shot = dynamic_cast<engine::ShotCommand*>(command[0]->get(engine::SHOT_CATEGORY));
            jsonOut["PowerShot"] = shot->getPower();
        }   

        if(command[0]->get(engine::MODE_CATEGORY))
        {

            engine::ModeCommand* modeCmd = dynamic_cast<engine::ModeCommand*>(command[0]->get(engine::MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            jsonOut["Mode"] =  modeCmd->getMode();
        }
        
        request.setBody(jsonOut.toStyledString());
        sf::Http::Response response = http.sendRequest(request);
        
        
        std::cout << "status: " << response.getStatus() << std::endl;
        
        if(response.getStatus() == 204)
            return true;
        return false;
    }


    
    void Pilote::addCommand (engine::Command* command){
        commands_mutex.lock();
        this->command[0]->add(command);
        commands_mutex.unlock();
    }
    
    
    
    
    
    
}

