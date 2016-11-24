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

namespace ai{

    TreeAI::TreeAI(state::State* state, int character) : EvolvedAI(state,character){
        
        state::State* t = new state::State();
        t->load("res/Levels/level1.txt");
        slaveGardener = new Gardener(5,t);
    }


    void TreeAI::run (engine::CommandSet& commands){
        this->commands = &commands;
        root = new Node();
        root->score = 0;
        slaveGardener->setStart();
        Node* toDo = slaveGardener->ApplyActionMax(root);
        shot();
        nextOrientation();
        if(toDo->choiceMove[0] == 0){
            this->commands->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
        }
        else if(toDo->choiceMove[0] == 2){
            this->commands->add(new engine::MoveCommand(character,8,0));
            //command move to the right
        }
    }
    


}