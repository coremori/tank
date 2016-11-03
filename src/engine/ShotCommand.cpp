#include "ShotCommand.h"
#include "CommandCategory.h"

namespace engine{
    
    ShotCommand::ShotCommand (int c, int p){
        character = c;
        power = p;
    }
    
    int ShotCommand::getCharacter () const{
        return character;
    }
    
    int ShotCommand::getPower () const{
        return power;
    }
    
    int ShotCommand::getCategory () const{
        return SHOT_CATEGORY;
    }
}