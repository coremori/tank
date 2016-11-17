/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 17, 2016, 9:39 AM
 *
 * Part of tank */


#include "DistanceUtility.h"
#include "AI.h"
#include "state/Tank.h"

namespace ai{

    DistanceUtility::DistanceUtility() {
        distance = 0;
    }

    int DistanceUtility::getDistance() const {
        /*Return the distance calculate previously
         *For updating it, use updateDistance()
         */
        return distance;
    }

    
    void DistanceUtility::updateDistance(state::State* state, int character) {
        /*update the X distance between the two players
         * The value are negative for player at the left side, positive at the right side
         */
        int other = (character)? 0:1;
        distance = state->getMobile(other)->getX()-state->getMobile(character)->getX(); 
    }
    
    
    
    bool DistanceUtility::inMissileFireRange() const {
        /*Return true if fire a missile will impact the otherplayer
         * */ 
        if(distance==80 || distance==-80 )//si on vise en haut - à modifier lorsque la puissance de tir sera intégrée
        {
            return true;
        }
        return false;
    }
    
    
    bool DistanceUtility::inShellFireRange(state::State* state, int CharShoting) const {
        /*Return true if fire a shell will impact the otherplayer
         *The shell is shot by CharShoting
         * */ 
        int character = CharShoting;
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character));
        int distance = this->distance/8;        
        int other = (character)? 0:1;
        if(!(((tank->getY()-state->getMobile(other)->getY())<=16) && ((tank->getY()-state->getMobile(other)->getY())>=0)))
            return false;
            
        int x = tank->getX()/8;
        int y = tank->getY()/8;

        if(distance>=0)
        {
            while(distance>=1 && (state->getGrid().isSpace(x,y)))
            {
                x ++;
                distance --;                
            }

        }
        else if(distance<0)
        {
            while(distance<=1 && (state->getGrid().isSpace(x,y)))
            {
                x--;
                distance ++;                
            }
        }
        return not(distance); //si pas de mur touché (donc cible atteinte)
    }

}