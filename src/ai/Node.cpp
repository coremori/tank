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

  
        
Node* Gardener::createChild(Node* node){
    children.push_back(new Node());
    return child;
}        
        