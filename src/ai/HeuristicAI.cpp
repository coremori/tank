/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 15, 2016, 10:06 AM
 *
 * Part of tank */


#include "HeuristicAI.h"
#include "state/Tank.h"
#include "engine/Engine.h"
#include "engine/EndTurnCommand.h"
#include "engine/DirectionCommand.h"
#include "engine/MoveCommand.h"
#include "engine/ShotCommand.h"

namespace ai{

    HeuristicAI::HeuristicAI(state::State* state, int character) : AI(state,character){}
    
    
    
    
    
    
    
    
    void HeuristicAI::choice() {
        
            
    }

    
    
    
    
    
    
    
    int HeuristicAI::directionOtherChar() {
        int other = (character)? 0:1;
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(other));
        return tank->getOrientation();
    }
    
    
    
    
    
    
    
    
    int HeuristicAI::distanceOtherChar() { //renvoie la distance entre les deux tanks
        int other = (character)? 0:1;
        return state->getMobile(other)->getX()-state->getMobile(character)->getX(); 
    }
    
    
    
    
    
    
    
    
    
    
    void HeuristicAI::move(bool esquive) {
        int other;
            if(character==1)
                other = 0;
            else
                other = 1;
        state::Tank* othertank = dynamic_cast<state::Tank*>(state->getMobile(other));
        int distance = distanceOtherChar();
        
        if(esquive){//on fuit
            if(((othertank->getOrientation() == state::right_up) && (distance==-10 ))||  ((othertank->getOrientation() == state::left_up) && (distance!=10 )))
            {
                commands->add(new engine::MoveCommand(character,-8,0));
            }
            else if((othertank->getOrientation() == state::left_up) && (distance==10))
            {
                commands->add(new engine::MoveCommand(character,8,0));
            }    
        }
        else if(distance>=0||distance != 10){//on se rapproche si le missile n'est pas à porter
            commands->add(new engine::MoveCommand(character,8,0));
        }
        else if(distance<=0||distance != -10){
            commands->add(new engine::MoveCommand(character,-8,0));
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    void HeuristicAI::nextOrientation() {
        if(touchable()){
            if(distanceOtherChar() < 0)
                commands->add(new engine::DirectionCommand(character,state::left_up));
            else
                commands->add(new engine::DirectionCommand(character,state::right_up));
            //else if(distanceOtherChar()==0)
                //si ils sont au même endroit, on fait un suicide?
        }        
        else{
            if(distanceOtherChar() < 0)
                commands->add(new engine::DirectionCommand(character,state::left_down));
            else
                commands->add(new engine::DirectionCommand(character,state::right_down));
        }
    }
    
    
    
    
    
    
    
    
    
    
    void HeuristicAI::run(engine::CommandSet& commands) {
        this->commands = &commands;
        shot();
        move(false);
    }

    
    
    
    
    
    
    
    
    
    void HeuristicAI::shot() {
        if(touchable())
            commands->add(new engine::ShotCommand(character,10));
    }

    
    
    
    
    
    
    
    
    
    bool HeuristicAI::touchable() {
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character));
        int distance = distanceOtherChar()/8;
        if(distance==10 || distance==-10 )//si on vise en haut
        {
            return true;
        }
        else
        {
            int other;
            if(character==1)
                other = 0;
            else
                other = 1;
            
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
            if (distance == 0)//si pas de mur touché
                return true;
            else
                return false;
        }
        
        /*
        if(tank->getOrientation()==state::right_up && distance==10 )//si on vise en haut
        {
            return true;
        }
        else if(tank->getOrientation()==state::left_up && distance==-10)//si on vise en haut
        {
            return true;
        }
        else
        {
            int other;
            if(character==1)
                other = 0;
            else
                other = 1;
            
            if(!(((tank->getY()-state->getMobile(other)->getY())<=16) && ((tank->getY()-state->getMobile(other)->getY())>=0)))
                return false;
            int x = tank->getX()/8;
            int y = tank->getY()/8;
            
            if(tank->getOrientation()==state::right_down && distance>=0)
            {
                while(distance>=1 && (state->getGrid().isSpace(x,y)))
                {
                    x +=8;
                    distance --;                
                }

            }
            else if(tank->getOrientation()==state::left_down && distance<=0)
            {
                while(distance<=1 && (state->getGrid().isSpace(x,y)))
                {
                    x-=8;
                    distance ++;                
                }
            }
            if (distance == 0)//si pas de mur touché
                return true;
            else
                return false;
        }*/
    }
}
