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
        command = new engine::CommandSet();
        command_waiting = new engine::CommandSet();
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
            already = 1;
        }
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        rendu = new PiloteSFML(&state, &engine, character, this);      
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
        
       
        sf::Http::Request request;
        sf::Http::Response response;

                
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Welcome >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        std::cout << "                    Command for moving : left - right                   " << std::endl;
        std::cout << "                    Command changing direction :  " << std::endl;
        std::cout << "                               q : left:  " << std::endl;
        std::cout << "                               z : left-up:  " << std::endl;
        std::cout << "                               d : right:  " << std::endl;
        std::cout << "                               e : right-up:  " << std::endl;
        std::cout << "                    Command for shot : space  " << std::endl;
        std::cout << "                    Command for AI only : p  " << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if(command_waiting->get(engine::MODE_CATEGORY)){
                commands_mutex.lock();
                engine::ModeCommand* modeCmd = dynamic_cast<engine::ModeCommand*>(command_waiting->get(engine::MODE_CATEGORY));
                
                if(modeCmd->getMode()==engine::AI){
                    engine.setMode(engine::AI);
                    already = already ? 0:1;
                    engine::CommandSet* s = command;
                    command = command_waiting;
                    s->clear();
                    command_waiting = s;
                    while(!postCommand(character));
                    waitGetCommand(character,character);
                }
                commands_mutex.unlock();
                
            }
            if(engine.getCharTurn()==character && engine.getMode()==engine::play){
                
                if(command_waiting->get(engine::END_CATEGORY)){
                commands_mutex.lock();
                engine::CommandSet* s = command;
                command = command_waiting;
                s->clear();
                command_waiting = s;
                commands_mutex.unlock();
                while(!postCommand(character)){
                        std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    };
                command->clear();
                already = already ? 0:1;
                waitGetCommand(character,character);
                } 
            }  else if (engine.getMode() != engine::Finish){
                
                if(already != engine.getCharTurn()){
                    if(getCommand(engine.getCharTurn(),character))
                        already = already ? 0:1;
                }
            }
            
            timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
            engine.update(timeNow,500);
            
        }
        
        
        
        
        
        //<<<<<<<<<<<<<<<<< remove from server
        sf::Http::Request requestDelete;
        requestDelete.setMethod(sf::Http::Request::Delete);
        character ?  requestDelete.setUri("user/1"):requestDelete.setUri("user/0");  
        response = http.sendRequest(requestDelete);
        
        if(response.getStatus()!=204){
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
        if(characterAsked == 1 && characterSender == 0){
            request.setUri("game/0/1");
        } else if(characterAsked == 1 && characterSender == 1){
            request.setUri("game/1/1");
        } else if(characterAsked == 0 && characterSender == 0){
            request.setUri("game/0/0");
        } else if(characterAsked == 0 && characterSender == 1){
            request.setUri("game/1/0");
        }

        sf::Http::Response response = http.sendRequest(request);

        if(response.getStatus() !=  200){
            return false;//impossible de récupérer les commandes
        }
        
        Json::Reader jsonReader;
        Json::Value jsonIn;
        
        if (!jsonReader.parse(response.getBody(),jsonIn))
                std::cout << "Données invalides: "+jsonReader.getFormattedErrorMessages() << std::endl;
        //player = jsonIn["character"].asInt();
        int player = jsonIn["Character"].asInt();
        if(jsonIn["Xmove"].asInt()){
            engine.addCommand(new engine::MoveCommand(player,jsonIn["Xmove"].asInt(),jsonIn["Ymove"].asInt()));
            
        }
        
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
                    already = character ? 0:1;
                    break;
                case 3:
                    engine.addCommand(new engine::ModeCommand(engine::replay));
                    break;
                default:
                    engine.addCommand(new engine::ModeCommand(engine::play));
                    break;
            }
        }
           
        engine.addCommand(new engine::EndTurnCommand(player));
        return true;
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
        characterSender ? request.setUri("game/1"):request.setUri("game/0");

        
        Json::Value jsonOut;

        jsonOut["Character"] = characterSender;
        
        if(command->get(engine::VIEW_CATEGORY))
        {
            engine::DirectionCommand* dcmd = dynamic_cast<engine::DirectionCommand*>(command->get(engine::VIEW_CATEGORY));
            jsonOut["Direction"] = dcmd->getDirection();
        }

        if(command->get(engine::MOVE_CATEGORY))
        {
            engine::MoveCommand* move = dynamic_cast<engine::MoveCommand*>(command->get(engine::MOVE_CATEGORY));            
            jsonOut["Xmove"] = move->getXmove();
            jsonOut["Ymove"] = move->getYmove();
        }

        if(command->get(engine::SHOT_CATEGORY))//Shot command
        {
            engine::ShotCommand* shot = dynamic_cast<engine::ShotCommand*>(command->get(engine::SHOT_CATEGORY));
            jsonOut["PowerShot"] = shot->getPower();
        }   

        if(command->get(engine::MODE_CATEGORY))
        {
            engine::ModeCommand* modeCmd = dynamic_cast<engine::ModeCommand*>(command->get(engine::MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            jsonOut["Mode"] =  modeCmd->getMode();
        }
        
        request.setBody(jsonOut.toStyledString());
        sf::Http::Response response = http.sendRequest(request);
       
        if(response.getStatus() == 204)
            return true;
        return false;
    }


    
    void Pilote::addCommand (engine::Command* command){
        commands_mutex.lock();
        this->command_waiting->add(command);
        commands_mutex.unlock();
    }
    
    
    
    
    
    
}

