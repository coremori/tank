/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 8, 2016, 4:33 PM
 *
 * Part of tank */


#include "ActionShot.h"
#include "state/Tank.h"
#include "state/ElementEvent.h"
#include "state/ProjectileEvent.h"
#include "state/Obstacle.h"

namespace engine{

    ActionShot::ActionShot(int character, int characterTarget, int damage, int xImpact, int yImpact, int yMax, bool displayPv) {
        this->character = character;
        this->characterTarget = characterTarget;
        this->damage = damage;
        this->xImpact = xImpact;
        this->yImpact = yImpact;
        this->yMax = yMax;
        this->displayPv = displayPv;
        
    }
    
    void ActionShot::apply(state::State* s) {//apply the action
        if(characterTarget>=0)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(characterTarget));
            tank->setPv(tank->getPv()-damage);
        }
        state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(character));
        if((xImpact-tank->getX())>0){
           s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX()+8,tank->getY()-7,xImpact,yImpact, true, yMax)));
        }
        else
        {
            s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX()-8,tank->getY()-7,xImpact,yImpact, false, yMax)));
        }
            
        return;
    }
    
    
    void ActionShot::undo(state::State* s) {
        if(characterTarget>=0)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(characterTarget));
            tank->setPv(tank->getPv()+damage);
        }
    }

}
/*press ctrl+space for create function define in .h*/