/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 22, 2016, 10:33 PM
 *
 * Part of tank 
 */
#include "Gardener.h"
#include "Node.h"

namespace ai{
    Gardener::Gardener (int depthMax, state::State* state){
        this->depthMax = depthMax;
        this->state->copy(*state);//on stocke une copie qu'on pourra facilement modifié
        for(int j = 1; j<depthMax; j++)//à chaque profondeur
            for(int i = 0; i<(3^(j)); i++)// on crée 4 node pour chaque de la couche d'avant
                nodeWarehouse.push_back(new Node());
    }
    
    
    
    void Gardener::Evaluate (){
        
    }
    
    int Gardener::bestMove (){
        return 0;
    }
    int Gardener::minimax_rec (Node* Node){
        
    }
    
    
    int Gardener::minimax_rec_max (Node* Node){
        if(Node->Score != 0)
            return Node->Score;
        int max = 0;
        Node * child;
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

    
   
 /*    
    int character;
    Engine* engineTest;
    cuurent ActualpvMe;
    cureent ActualpvOther;
  */  
    

    void Gardener::evaluateScore(Node* node) {
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character));
        int pvMe = tank->getPv(); // pv de notre joueur
        state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(character?0:1));
        int pvOther = tank->getPv(); // pv du joueur adverse
        int score = 0;
        if(pvOther == 0){
            score += 1000;
        }
        else if(pvMe == 0){
            score -= 1000;
        }
        
        score += (ActualpvOther - pvOther) + (pvMe - ActualpvMe);
        
        node->Score = score;  
    }
    
    
    
   //utilisable
    shot(){
        if(distanceUtility.inMissileFireRange() || distanceUtility.inShellFireRange(state,character))
            engineTest.add(new engine::ShotCommand(character,10));
    };
    
    nextOrientation(){
        if(distanceUtility.inMissileFireRange()){
            if(distanceUtility.getDistance() < 0)
                engineTest.add(new engine::DirectionCommand(character,state::left_up));
            else
                engineTest.add(new engine::DirectionCommand(character,state::right_up));
                
            //else if(distanceOtherChar()==0)
                //si ils sont au même endroit, on fait un suicide?
        }        
        else if(distanceUtility.inShellFireRange(state,character))
        {
            if(distanceUtility.getDistance() < 0)
                engineTest.add(new engine::DirectionCommand(character,state::left_down));
            else
                engineTest.add(new engine::DirectionCommand(character,state::right_down));
        }
    };
    
    void ApplyAction(Node* node){
        
        if(node.depth == depthmax){
            evaluateScore(node);    
        }
        else{

            for(int i = 0; i<3 ; i++){
                node->child.push_back(createChild(node));
                
                if(i==0){
                    //command move to the left
                }
                else if(i==1){
                    //command do nothing
                }
                else if(i==2){
                    //command move to the right
                }
                    
            //state.apply next suivant i applique action nécésaire pour passer à cet état là
            ruler->implementesRules();
            ruler->apply();

            ApplyAction(node->child.back());
            ruler->undo();  //on repasse à l'état de départ
            }
        }
    } 
    

}

Node* Gardener::createChild(Node* node){
    children.push_back(new Node());
    return child;
}      

