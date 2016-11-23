/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 23, 2016, 1:59 PM
 *
 * Part of tank */


#include "Node.h"

namespace ai{

    Node * const Node::getChild(size_t i) {
        return child[i];
    }
        
    const size_t Node::getChildCount() {
        return child.size();
    }
        
    const int Node::getScore() {
        return Score;
    }
    
    void Node::setScore(int score) {
        this->Score = score;
    }



}

/*press ctrl+space for create function define in .h*/
ApplyAction(Node* node){
    if(node.depth == dephtmax){
        evaluate score}
    else
    {
        for(int i = 0; i<3 ; i++){
            crée le child et l'ajoute au tableau
        state.aplly next suivant i applique action nécésaire pour passé à cet état là
        
        crée fils : si i = 0 move gauche, i =1 move droite...
        
        
        ApplyAction(nextChild);
        state.undo  //on repasse à l'état de départ
        }
    }
}   
        
        
        