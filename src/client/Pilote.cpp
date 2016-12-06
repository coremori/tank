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

namespace client{

    
    
    Pilote::Pilote() : engine(&state){
        /* Create the engine from the state
         * Create the CommandSet for the Ai in this computer (Will be taking the CommandSet from the server in the next upgrade)
         */
        command.push_back(new engine::CommandSet());
        command.push_back(new engine::CommandSet());
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        rendu = new PiloteSFML(&state, &engine);      
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
        int alreadyplay = 1;
        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if(engine.getMode()==engine::AI && alreadyplay!=engine.getCharTurn()){
                /* In AI mode, and the ai chosen is the Ai who doesn't play the turn before
                 * run create the ai's command list 
                 * takeCommand send these command to the engine (it will be the same for the command from the server)
                 * update the ai to use next turn
                 */
                ai[engine.getCharTurn()]->run(*command[engine.getCharTurn()]);
                engine.takeCommands(command[engine.getCharTurn()]);
                alreadyplay = engine.getCharTurn();
            }
            else if(engine.getMode()==engine::play && engine.getCharTurn()==1){
                /* In play mode, this is the ai turn
                 */
                ai[1]->run(*command[1]);
                engine.takeCommands(command[1]);
            }
            timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
            engine.update(timeNow,500);
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

    
    
    
    
    
    
    
    
    
    
}

