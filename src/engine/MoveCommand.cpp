/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 7:16 PM
 *
 * Part of tank */

#include "Command.h"
#include "CommandCategory.h"
#include "MoveCommand.h"

namespace engine{
    
    MoveCommand::MoveCommand(int c, int xmove, int ymove) {//(num character, X, Y))
        //xmove and ymove are in pixels
        //c est le numero du perso
        character = c;
        Xmove = xmove;
        Ymove = ymove;
    };
    
    int MoveCommand::getCharacter() const {
        return character;
    }
    
    int MoveCommand::getCategory() const {
        return MOVE_CATEGORY;
    };

    int MoveCommand::getXmove() const {
        return Xmove;
    }

    int MoveCommand::getYmove() const {
        return Ymove;
    }


}
/*press ctrl+space for create function define in .h*/