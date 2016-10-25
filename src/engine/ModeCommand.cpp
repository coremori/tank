/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 4:35 PM
 *
 * Part of tank */


#include "ModeCommand.h"
#include "CommandCategory.h"

namespace engine {

    ModeCommand::ModeCommand(EngineMode mode) {
        this->mode = mode;
    }
    
    int ModeCommand::getCategory() const {
        return MODE_CATEGORY;
    }

    EngineMode ModeCommand::getMode() const {
        return mode;
    }

}
/*press ctrl+space for create function define in .h*/