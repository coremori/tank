
#include "engine.h"

namespace engine {


    DirectionCommand::DirectionCommand (int c, int /*state::Orientation*/ d){
        character = c;
        direction = d;
    };
    
    int DirectionCommand::getCharacter () const{
        return character;
    };
    
    int /* state::Orientation */ DirectionCommand::getDirection () const{
        return direction;
    };
    
    int DirectionCommand::getCategory () const{
        return VIEW_CATEGORY;
    };
  

};

