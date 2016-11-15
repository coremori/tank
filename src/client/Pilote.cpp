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
        rendu->setEngine(&engine);
        std::thread t1(&PiloteRendu::display,rendu);// the thread for the rendu run in PiloteSFML.display()
        std::thread t2(&Pilote::run,this); // launch run() de l'objet courant (this)*/
        t2.join();
        t1.join();
    }
        
    void Pilote::run() {//thread for the engine
        
        // toutes les 50 ms
        while(engine.getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            engine.update();
        }
    }
}

