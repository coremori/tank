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

namespace client{

    /*Pilote::Pilote(engine::Engine* engine) { //: state(state::State()), engine(&state)
        this->engine = engine;
        
    }*/
    Pilote::Pilote() : engine(&state){
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
        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            engine.update();
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

