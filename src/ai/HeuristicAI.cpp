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


#include "DistanceUtility.h"


namespace ai{
    
    
    HeuristicAI::HeuristicAI(const state::State* state, int character) : EvolvedAI(state,character){}
    
    
    
    
    
    
    
    
    void HeuristicAI::choice() {//choice to attack or defend move
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character)->clone());
        int other = (character)? 0:1;
        state::Tank* othertank = dynamic_cast<state::Tank*>(state->getMobile(other)->clone());

        if(tank->getPv()<=30 && othertank->getPv()>30)
            move(true);
        else
            move(false);
    }    
    
    
    
    
    
    
    void HeuristicAI::move(bool esquive) {
        /* move for use missile or escape
         * if esquive == true then the next move will be to evade the maximun damage
         * else it will be to use the missile
         */ 
        int distance = distanceUtility.getDistance()/8;
        if(esquive){//on fuit
            if(distance == -9 || distance == -10|| distance == 11)//partir vers la gauche est plus rapide (et choix pour le centre)
                commands->add(new engine::MoveCommand(character,-8,0));
            else if( distance == 9 || distance == 10 || distance == -11 )//partir vers la droite est plus rapide (et choix pour le centre)
                commands->add(new engine::MoveCommand(character,8,0));
        }
        else if((distance>-10 && distance<0) || distance > 10)
        {
            commands->add(new engine::MoveCommand(character,8,0));
        }
        else if((distance<10 && distance>0) || distance<-10){//on se rapproche si le missile n'est pas à porter
            commands->add(new engine::MoveCommand(character,-8,0));
        }
    }
        
    
    
    
    
    
    
    void HeuristicAI::run(engine::CommandSet& commands) {
        /* Determine the command played by the AI
         * Use nextOrientation() and shot() for doing the greatest damage to the other player
         * Use choice() to determine the best next move
         * */
        this->commands = &commands;
        distanceUtility.updateDistance(state,character);
        nextOrientation();
        shot();
        choice();
        commands.add(new engine::EndTurnCommand(character));
    }
}
