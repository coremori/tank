/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 22, 2016, 10:33 PM
 *
 * Part of tank 
 */
#include "Gardener.h"
#include "Node.h"
#include "state/Tank.h"
#include "engine/ShotCommand.h"
#include "engine/DirectionCommand.h"
#include "engine/MoveCommand.h"
#include <cstddef>


namespace ai{
    Gardener::Gardener (int depthMax, state::State* state){
        this->depthMax = depthMax;
        this->state->copy(*state);//on stocke une copie qu'on pourra facilement modifié
        
        
        this->commandsTest = new engine::CommandSet();
        
        
        
        
    }
    
    
    
    int Gardener::minimax_rec (Node* Node){
        return 45;
    }
    
    /*
    int Gardener::minimax_rec_max (Node* Node){
        if(Node->getScore() != 0){
            return Node->getScore();
        }
        int max = 0;
        Node* child;
        for(size_t i = 0; i<Node->child.size() ; i++){
            child = Node->child[i];
            int value = minimax_rec_min(child);
            if(value > max)
                max = value;
        }
        return max;
    }
    
    int Gardener::minimax_rec_min (Node* Node){
        if(Node->Score != 0)
            return Node->Score;
        int min = 0;
        for(size_t i = 0; i<Node->child.size() ; i++){
            Node* child = Node->child[i];
            int value = minimax_rec_max(child);
            if(value < min)
                min = value;
        }
        return min;
    }
    
    */
    


    void Gardener::evaluateScore(Node* node) {
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character));
        int pvMe = tank->getPv(); // pv de notre joueur
        tank = dynamic_cast<state::Tank*>(state->getMobile(character?0:1));
        int pvOther = tank->getPv(); // pv du joueur adverse
        int score = 0;
        if(pvOther == 0){
            score += 1000;
        }
        else if(pvMe == 0){
            score -= 1000;
        }
        
        score += (ActualpvOther - pvOther) + (pvMe - ActualpvMe);
        
        node->setScore(score);  
    }
   

    
   
   //utilisable

    void Gardener::shot(int character) {
        if(distanceUtility.inMissileFireRange() || distanceUtility.inShellFireRange(state,character))
            commandsTest->add(new engine::ShotCommand(character,10));
    }

    void Gardener::nextOrientation(int character) {
        if(distanceUtility.inMissileFireRange()){
            if(distanceUtility.getDistance() < 0)
                commandsTest->add(new engine::DirectionCommand(character,state::left_up));
            else
                commandsTest->add(new engine::DirectionCommand(character,state::right_up));
                
            //else if(distanceOtherChar()==0)
                //si ils sont au même endroit, on fait un suicide?
        }        
        else if(distanceUtility.inShellFireRange(state,character))
        {
            if(distanceUtility.getDistance() < 0)
                commandsTest->add(new engine::DirectionCommand(character,state::left_down));
            else
                commandsTest->add(new engine::DirectionCommand(character,state::right_down));
        }
    }
    
    
    void Gardener::createChild (Node* Node) {
        ai::Node* newNode = new ai::Node();
        newNode->depth = Node->depth;
        newNode->score = 0;
        Node->children.push_back(newNode);
            nodeWarehouse.push_back(newNode);
    }
            
    
    Node* Gardener::ApplyActionMax(Node* node) {
        if(node->depth == depthMax){
            evaluateScore(node);
            return node;
        }
        else{
            character = character?0:1;
            Node* maxNode = NULL;
            Node* examNode = NULL;
            for(int i = 0; i<3 ; i++){
                createChild(node);
                nodeWarehouse.back()->choiceMove = i;
                
                if(i==0){
                    commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
                }
                else if(i==1){
                    //commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command do nothing
                }
                else if(i==2){
                    commandsTest->add(new engine::MoveCommand(character,8,0));
                    //command move to the right
                }
                    
            //state.apply next suivant i applique action nécésaire pour passé à cet état là
                shot(character);
                nextOrientation(character);
                
                engine::ActionListTurn* tour = new engine::ActionListTurn(state);
                tour->notify = false;
                action.push_back(tour);
        
                ruler->setActions(tour);
                ruler->implementeRules();
                ruler->apply();
                
                examNode = ApplyActionMin(nodeWarehouse.back());
                if(maxNode == NULL)
                    maxNode = examNode;
                else if(examNode->score > maxNode->score)
                    maxNode = examNode;
                
              //on repasse à l'état de départ
                ruler->setActions(action.back());
                ruler->undo();
                action.pop_back();
            }
            return maxNode;
        }
    }
    
    Node* Gardener::ApplyActionMin(Node* node) {
        if(node->depth == depthMax){
            evaluateScore(node);
            return node;
        }
        else{
            character = character?0:1;
            Node* minNode = NULL;
            Node* examNode = NULL;
            for(int i = 0; i<3 ; i++){
                createChild(node);
                nodeWarehouse.back()->choiceMove = i;
                
                if(i==0){
                    commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
                }
                else if(i==1){
                    //commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command do nothing
                }
                else if(i==2){
                    commandsTest->add(new engine::MoveCommand(character,8,0));
                    //command move to the right
                }
                    
            //state.apply next suivant i applique action nécésaire pour passé à cet état là
                shot(character);
                nextOrientation(character);
                
                engine::ActionListTurn* tour = new engine::ActionListTurn(state);
                tour->notify = false;
                action.push_back(tour);
        
                ruler->setActions(tour);
                ruler->implementeRules();
                ruler->apply();
                
                examNode = ApplyActionMin(nodeWarehouse.back());
                
                if(minNode == NULL)
                    minNode = examNode;
                else if(examNode->score > minNode->score)
                    minNode = examNode;
                
                
              //on repasse à l'état de départ
                
                ruler->setActions(action.back());
                ruler->undo();
                action.pop_back();
            }
            return minNode;
        }
    }
}