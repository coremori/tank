// Generated by dia2code
#ifndef AI__NODE__H
#define AI__NODE__H

#include <vector>

namespace ai {
  class Node;
}

#include "Move.h"

namespace ai {

  /// class Node - Node of the move Tree "\n"// Contain the node's depth , children and score
  class Node {
    // Associations
    // Attributes
  public:
    std::vector<Node*> children;
    int score;
    int depth;
    std::vector<Move> choiceMove;
  };

};

#endif