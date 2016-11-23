/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 21, 2016, 2:02 PM
 *
 * Part of tank */


#include "SearchTree.h"

namespace ai{

    SearchTree::SearchTree() {
    }
        
    
    
    void SearchTree::createTree(std::vector<Node*>& NodeWarehouse, Node* fromNode) {
        for(unsigned int j = 0; j<NodeWarehouse.size(); j++)
            
            for(int i = 0; i<(4^(j)); i++)
                NodeWarehouse.push_back(new Node());
    }


}
/*press ctrl+space for create function define in .h*/