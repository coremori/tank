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


#include <iostream>

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
    
    void ActionShot::apply(state::State* s, bool notify) {//apply the action
        if (notify)
            std::cout << "character "<<character ;

        
        state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(character));
        if (yMax==-1)
        {
            
            if (notify==true){
                std::cout << " tire un obus ";
                if ((xImpact-tank->getX())>0)
                    s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX()+8,tank->getY()-7,xImpact,yImpact, true, yMax)));
                else
                    s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX()-8,tank->getY()-7,xImpact,yImpact, false, yMax)));
            }
        }
        else
        {
            
            if (notify==true){
                std::cout << " tire un missile ";
                if ((xImpact-tank->getX())>0)
                    s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX(),tank->getY()-16,xImpact,yImpact, true, yMax)));
                else
                    s->getMobiles().notifyObserver(*(new state::ProjectileEvent(tank->getX(),tank->getY()-16,xImpact,yImpact, false, yMax)));
            }
        }
        if (characterTarget>=0)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(characterTarget));
            tank->setPV(tank->getPV()-damage);
                if (notify==true){
                    s->getMobiles().notifyObserver(*(new state::StateEvent(s,state::Pv_Changed)));
                    std::cout << "et touche Tank "<< characterTarget << " qui prend "<<damage<<" dégats " ;
                }
                
        }
        if (notify)
            std::cout << std::endl;
        
    }
    
    
    
    
    
    
    void ActionShot::undo(state::State* s) {
        if (characterTarget>=0)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(s->getMobile(characterTarget));
            tank->setPV(tank->getPV()+damage);
        }
    }

}
