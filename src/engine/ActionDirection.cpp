/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 3, 2016, 3:34 PM
 *
 * Part of tank */


#include "ActionDirection.h"
#include "../state/Tank.h"
#include "../state/Orientation.h"

#include <iostream>


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
        
        std::cout << "character "<<character<<" regarde vers" ;
        switch(Newdirection){
            case state::left_down:
                std::cout << " gauche bas" << std::endl;
                break;
            case state::left_up:
                std::cout << " gauche haut" << std::endl;
                break;
            case state::right_down:
                std::cout << " droite bas" << std::endl;
                break;
            case state::right_up:
                std::cout << " droite haut" << std::endl;
                break;
        }
    }
    
    void ActionDirection::undo(state::State* s) {
        state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(character));
        tank->setOrientation(OldDirection);
        //s->getMobile(character)->setX(s->getMobiles().get(character)->getX()+dx);
        //s->getMobile(character)->setY(s->getMobiles().get(character)->getY()+dy);
        s->getMobiles().notifyObserver(character);
    }

}