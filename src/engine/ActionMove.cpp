#include "ActionMove.h"
#include "../state.h"

#include <iostream>
namespace engine {

    ActionMove::ActionMove (int dx, int dy, int character){
        this->dx = dx;
        this->dy = dy;
        this->character = character;
    };
    
    void ActionMove::apply (state::State* s,bool notify){
        //next position is actual + (dx,dy))
        s->getMobile(character)->setX(s->getMobiles().get(character)->getX()+dx);
        s->getMobile(character)->setY(s->getMobiles().get(character)->getY()+dy);
        if (notify==true){
            s->getMobiles().notifyObserver(character);
            std::cout << "character "<<character<<" bouge vers + ("<<dx/8<<","<<dy/8<<")" << std::endl;
        }
    };
    
    void ActionMove::undo (state::State* s){
        //next position is actual - (dx,dy))
        s->getMobile(character)->setX(s->getMobile(character)->getX()-dx);
        s->getMobile(character)->setY(s->getMobile(character)->getY()-dy);
    };
  
};