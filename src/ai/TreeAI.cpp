/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 23, 2016, 4:27 PM
 *
 * Part of tank 
 */
#include "TreeAI.h"

namespace ai{

    void run (engine::CommandSet& commands){
        
    }
    
    void HeuristicAI::run(engine::CommandSet& commands) {//determine the command played by the AI
        this->commands = &commands;
        distanceUtility.updateDistance(state,character);
        nextOrientation();
        shot();
        choice();
        commands.add(new engine::EndTurnCommand(character));
    }
    
        void DumbAI::run (engine::CommandSet& commands){//choix aléatoire
        //int character = 1;
        srand (time(NULL));
        switch(rand() % 10){
            case 0: 
                commands.add(new engine::MoveCommand(character,8,0));
                break;
            case 1:
                commands.add(new engine::MoveCommand(character,-8,0));
                break;
            case 2:
                commands.add(new engine::DirectionCommand(character,state::right_up));
                break;
            case 3 :
                commands.add(new engine::DirectionCommand(character,state::left_up));
                break;
            case 4:
                commands.add(new engine::DirectionCommand(character,state::left_down));
                break;
            case 5:
                commands.add(new engine::DirectionCommand(character,state::right_down));
                break;
            default : 
                commands.add(new engine::ShotCommand(character,10));
                break;
        }
        commands.add(new engine::EndTurnCommand(character));//passer au tour suivant : n'oublions pas !
    }

}