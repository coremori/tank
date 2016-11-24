/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 9, 2016, 5:38 PM
 *
 * Part of tank */


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

    /*Pilote::Pilote(engine::Engine* engine) { //: state(state::State()), engine(&state)
        this->engine = engine;
        
    }*/
    Pilote::Pilote() : engine(&state){
        
        
        command.push_back(new engine::CommandSet());
        command.push_back(new engine::CommandSet());
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        rendu = new PiloteSFML(&state, &engine);
            
            
    }
        
    void Pilote::launch() {//launch the thread for the engine and the rendu
        state.load("res/Levels/level1.txt");
        rendu->createMenu();
        std::thread t1(&Pilote::runRender,this);// the thread for the rendu run in PiloteSFML.display()
        std::thread t2(&Pilote::runEngine,this); // launch run() de l'objet courant (this)*/
        t2.join();
        t1.join();
    }
        
    void Pilote::runEngine() {//thread for the engine
        
        // toutes les 50 ms
        int64_t timeNow;
        std::vector<ai::AI*> ai;
        ai.push_back(new ai::TreeAI(&state,0));
        ai.push_back(new ai::DumbAI(&state,1));
        int alreadyplay = 1;
        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if(engine.getMode()==engine::AI && alreadyplay!=engine.getCharTurn()){
                ai[engine.getCharTurn()]->run(*command[engine.getCharTurn()]);
                engine.takeCommands(command[engine.getCharTurn()]);
                alreadyplay = engine.getCharTurn();
            }
            else if(engine.getMode()==engine::play && engine.getCharTurn()==1){
                    ai[1]->run(*command[1]);
                    engine.takeCommands(command[1]);
            }
            timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
            engine.update(timeNow,500);
        }
    }
        
    void Pilote::runRender() {//thread for the rendu
        // toutes les 50 ms
        while(engine.getMode()!=engine::close)
        {
            rendu->applyChange();
            rendu->display();
            rendu->eventUp();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

}

