/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 10, 2016, 3:32 PM
 *
 * Part of tank */


#include "EndTurnCommand.h"
#include "CommandCategory.h"

namespace engine{

    EndTurnCommand::EndTurnCommand(int c) {
        this->character = c;
    }
        
    int EndTurnCommand::getCategory() const {
        return END_CATEGORY;
    }
        
    int EndTurnCommand::getCharacter() const {
        return character;
    }



}

/*press ctrl+space for create function define in .h*/