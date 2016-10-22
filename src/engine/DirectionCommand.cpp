
#include "engine.h"

namespace engine {


    DirectionCommand::DirectionCommand (int c, state::Orientation d){
        character = c;
        direction = d;
    };
    
    int DirectionCommand::getCategory () const{
        return MAIN_CATEGORY;
    };
    
    CommandTypeId DirectionCommand::getTypeId () const{
        return DIRECTION;
    };
    
    int DirectionCommand::getCharacter () const{
        return character;
    };
    
    state::Orientation DirectionCommand::getDirection () const{
        return direction;
    };
  

};

