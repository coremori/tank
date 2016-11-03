
#include "engine.h"

namespace engine {


    DirectionCommand::DirectionCommand (int c, state::Orientation d){
        character = c;
        direction = d;
    };
    
    int DirectionCommand::getCharacter () const{
        return character;
    };
    
    state::Orientation DirectionCommand::getDirection () const{
        return direction;
    };
    
    int DirectionCommand::getCategory () const{
        return VIEW_CATEGORY;
    };
  

};

