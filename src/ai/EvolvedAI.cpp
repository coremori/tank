/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 17, 2016, 2:02 PM
 *
 * Part of tank */


#include "EvolvedAI.h"

namespace ai{
    EvolvedAI::EvolvedAI(state::State* state, int character) : AI(state,character){}
    
    
    
        
    
    
    
    void EvolvedAI::nextOrientation() {//determine the next orientation
        if(distanceUtility.inMissileFireRange()){
            if(distanceUtility.getDistance() < 0)
                commands->add(new engine::DirectionCommand(character,state::left_up));
            else
                commands->add(new engine::DirectionCommand(character,state::right_up));
                
            //else if(distanceOtherChar()==0)
                //si ils sont au même endroit, on fait un suicide?
        }        
        else if(distanceUtility.inShellFireRange(state,character))
        {
            if(distanceUtility.getDistance() < 0)
                commands->add(new engine::DirectionCommand(character,state::left_down));
            else
                commands->add(new engine::DirectionCommand(character,state::right_down));
        }
    }
    
    
    
    
    
    
    void EvolvedAI::shot() {//if we can shot the other player, we do it
        if(distanceUtility.inMissileFireRange() || distanceUtility.inShellFireRange(state,character))
            commands->add(new engine::ShotCommand(character,10));
    }
}