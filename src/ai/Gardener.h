// Generated by dia2code
#ifndef AI__GARDENER__H
#define AI__GARDENER__H

#include <vector>
#include "engine/ActionListTurn.h"
#include "state/State.h"
#include "engine/Ruler.h"
#include "engine/CommandSet.h"

namespace ai {
  class DistanceUtility;
  class Node;
}

#include "DistanceUtility.h"

namespace ai {

  /// class Gardener - 
  class Gardener {
    // Attributes
  public:
    DistanceUtility distanceUtility;
    std::vector<engine::ActionListTurn*> action;
  protected:
    std::vector<Node*> nodeWarehouse;
    int depthMax;
    state::State* state;
    engine::Ruler* ruler;
    int character;
    int ActualpvMe;
    int ActualpvOther;
    engine::CommandSet* commandsTest;
    // Operations
  public:
    Gardener (int depthMax, state::State* state);
    int minimax_rec (Node* Node);
    int minimax_rec_max (Node* Node);
    int minimax_rec_min (Node* Node);
    void createChild (Node* Node);
    void evaluateScore (Node* node);
    void shot (int character);
    void nextOrientation (int character);
    Node* ApplyActionMax (Node* node);
    Node* ApplyActionMin (Node* node);
    void setStart ();
  };

};

#endif
