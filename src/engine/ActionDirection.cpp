/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 3, 2016, 3:34 PM
 *
 * Part of tank */


#include "ActionDirection.h"
#include "../state/Tank.h"

namespace engine {
    
    ActionDirection::ActionDirection(state::Orientation direction, int character) {
        this->Newdirection = direction;
        this->character = character;
    };
    
    void ActionDirection::apply(state::State* s) {
        state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(character));
        OldDirection = tank->getOrientation();
        tank->setOrientation(Newdirection);
        //s->getMobile(character)->setX(s->getMobiles().get(character)->getX()+dx);
        //s->getMobile(character)->setY(s->getMobiles().get(character)->getY()+dy);
        s->getMobiles().notifyObserver(character);
    }
    
    void ActionDirection::undo(state::State* s) {
        state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(character));
        tank->setOrientation(OldDirection);
        //s->getMobile(character)->setX(s->getMobiles().get(character)->getX()+dx);
        //s->getMobile(character)->setY(s->getMobiles().get(character)->getY()+dy);
        s->getMobiles().notifyObserver(character);
    }

}