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

namespace client{

    Pilote::Pilote(engine::Engine* engine) { //: state(state::State()), engine(&state)
        this->engine = engine;
        
    }
        
    void Pilote::run() {//thread for the engine
        
        // toutes les 50 ms
        while(engine->getMode()!=engine::close)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            engine->update();
        }
    }
}

