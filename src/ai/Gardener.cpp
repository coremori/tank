/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 22, 2016, 10:33 PM
 *
 * Part of tank 
 */
#include "Gardener.h"

namespace ai{
    Gardener::Gardener (int depthMax, state::State* state){
        this->depthMax = depthMax;
        this->state->copy(*state);//on stocke une copie qu'on pourra facilement modifié
        for(int j = 1; j<depthMax; j++)//à chaque profondeur
            for(int i = 0; i<(4^(j)); i++)// on crée 4 node pour chaque de la couche d'avant
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
        for(size_t i = 0; i<Node->child.size() ; i++){
            Node* child = Node->child[i];
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


