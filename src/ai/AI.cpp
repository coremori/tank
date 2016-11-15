/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 10, 2016, 5:00 PM
 *
 * Part of tank 
 */
#include "AI.h"
#include "engine.h"

namespace ai {
    AI::AI(state::State* state, int character) {
        this->state = state;
        this->character = character;
    }

    
    AI::~AI (){
        
    };
};