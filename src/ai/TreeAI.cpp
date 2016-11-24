/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 23, 2016, 4:27 PM
 *
 * Part of tank 
 */
#include "TreeAI.h"
#include "Node.h"
#include "engine/MoveCommand.h"
#include "state/State.h"
#include "engine/EndTurnCommand.h"

namespace ai{

    TreeAI::TreeAI(state::State* state, int character) : EvolvedAI(state,character){
        const int depthmax = 3;
        slaveGardener = new Gardener(depthmax,state);
    }


    void TreeAI::run (engine::CommandSet& commands){
        /* Create the best command for the turn
         * Use Gardener for choising the move
         * The shot and orientation action are chosen by functions shot() and nextOrientation from EvolvedAI class
         */
        this->commands = &commands;
        distanceUtility.updateDistance(state,character);
        
        slaveGardener->changeMobile(&state->getMobiles());
        Node* toDo = slaveGardener->Start();
        shot();
        nextOrientation();
        if(toDo->choiceMove[0] == left){
            this->commands->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
        }
        else if(toDo->choiceMove[0] == right){
            this->commands->add(new engine::MoveCommand(character,8,0));
            //command move to the right
        }
        this->commands->add(new engine::EndTurnCommand(character));
    }
    


}