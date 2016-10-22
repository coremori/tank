
#include "ActionMove.h"
#include "../state.h"

namespace engine {

  
    ActionMove::ActionMove (int dx, int dy, int character){
        this->dx = dx;
        this->dy = dy;
        this->character = character;
    };
    
    void ActionMove::apply (state::State* s){
        //next position is actual + (dx,dy))
        s->getMobile(character)->setX(s->getMobile(character)->getX()+dx);
        s->getMobile(character)->setY(s->getMobile(character)->getY()+dy);
    };
    void ActionMove::undo (state::State* s){
        //next position is actual - (dx,dy))
        s->getMobile(character)->setX(s->getMobile(character)->getX()-dx);
        s->getMobile(character)->setY(s->getMobile(character)->getY()-dy);
    };
  
};