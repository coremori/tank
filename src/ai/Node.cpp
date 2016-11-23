/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 23, 2016, 1:59 PM
 *
 * Part of tank */


#include "Node.h"

namespace ai{

    Node * const Node::getChild(size_t i) {
        return children[i];
    }
        
    const size_t Node::getChildCount() {
        return children.size();
    }
        
    const int Node::getScore() {
        return Score;
    }
    
    void Node::setScore(int score) {
        this->Score = score;
    }



}


/*
int ApplyAction(Node* node){
    if(node.depth == dephtmax){
        evaluate score
        return score;
    }
    else
    {
        int max = -5000;
        for(int i = 0; i<3 ; i++){
            crée le child et l'ajoute au tableau
        state.aplly next suivant i applique action nécésaire pour passé à cet état là
        
        crée fils : si i = 0 move gauche, i =2 move droite...
        
        
        if(ApplyAction(nextChild) > max)
            max = renovie;
        state.undo  //on repasse à l'état de départ
        }
    }
}   
        
     
renvoyer le node pour avoir la liste des actions a effectuer
        
        
coder une fonction tir
        
fonction eval score 
 * 
 */
        
Node* Gardener::createChild(Node* node){
    children.push_back(new Node());
    return child;
}        
        
