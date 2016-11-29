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
#include "state/State.h"
#include "engine/Ruler.h"
#include <cstddef>


namespace ai{
    Gardener::Gardener (int depthMax, const state::State* state){
        this->depthMax = depthMax;
        
        this->state = new state::State();
        this->state->load("res/Levels/level1.txt");//on stocke une copie qu'on pourra facilement modifié
        //la copie veut pas donc chargement brutal
        
       
        this->ruler = new engine::Ruler();
        
        ruler->setState(this->state);
        
        this->commandsTest = new engine::CommandSet();
        this->ruler->setCommandSet(commandsTest);
        
        character = 0;
        
        
    }
    
            
    Node* Gardener::Start() {
        /* Calculate the best move 
         * Use the minimax Recursion algorithme
         */
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character));
        ActualpvDif  = tank->getPv(); // pv de notre joueur
        tank = dynamic_cast<state::Tank*>(state->getMobile(character?0:1));
        ActualpvDif  -= tank->getPv(); // pv du joueur adverse
        //distanceUtility.updateDistance(state,character);
        Node* root = new Node();
        root->score = 0;
        root->depth = 0;
        return ApplyActionMax(root);
    }

    
 

    




    void Gardener::evaluateScore(Node* node) {
        /* Score given by :
         * score += (other injurie) - (my injurie )
         * score += 1000 if victory
         * score -= 1000 if lost
         */
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
        
        score += ActualpvDif - pvOther + pvMe;
        
        node->score = score;  
    }
   


    void Gardener::shot(int character) {
        /* If we can impact the other, we shot
         */
        if(distanceUtility.inMissileFireRange() || distanceUtility.inShellFireRange(state,character))
            commandsTest->add(new engine::ShotCommand(character,10));
    }

    void Gardener::nextOrientation(int character) {
        /* Create the command for the best next orientation
         * Orientation selected is the greatest damage 
         */
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
        /* Create a children of Node
         */
        ai::Node* newNode = new ai::Node();
        newNode->depth = Node->depth+1;
        newNode->score = 0;
        Node->children.push_back(newNode);
            nodeWarehouse.push_back(newNode);
    }
            
    
    Node* Gardener::ApplyActionMax(Node* node) {
        /* Part of the Minimax algorithme
         * return the node if we are at the maximum depth
         * else
         * Create the children of the node 
         * Calculate and return the maximun score of the children
         *
         */
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
                if(i==0){
                    nodeWarehouse.back()->choiceMove.push_back(left);
                    commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
                }
                else if(i==1){
                    nodeWarehouse.back()->choiceMove.push_back(noMove);
                    //commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command do nothing
                }
                else if(i==2){
                    nodeWarehouse.back()->choiceMove.push_back(right);
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
                commandsTest->clear();
                //ruler->apply();
                
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
        /* Part of the Minimax algorithme
         * return the node if we are at the maximum depth
         * else
         * Create the children of the node 
         * Calculate and return the minimum score of the node's children
         *
         */
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
                
                if(i==0){
                    nodeWarehouse.back()->choiceMove.push_back(left);
                    commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command move to the left
                }
                else if(i==1){
                    nodeWarehouse.back()->choiceMove.push_back(noMove);
                    //commandsTest->add(new engine::MoveCommand(character,-8,0));
                    //command do nothing
                }
                else if(i==2){
                    nodeWarehouse.back()->choiceMove.push_back(right);
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
                //ruler->apply();
                
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
    
    
    void Gardener::changeMobile(state::ElementList* mobile) {
        state->getMobiles().copy(*mobile);
    }

}