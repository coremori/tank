// Generated by dia2code
#ifndef AI__GARDENER__H
#define AI__GARDENER__H

#include <vector>
#include "state/State.h"
#include "engine/Ruler.h"
#include "engine/CommandSet.h"
#include "engine/ActionListTurn.h"
#include "state/ElementList.h"

namespace ai {
  class Node;
  class DistanceUtility;
}

#include "DistanceUtility.h"
#include "Node.h"

namespace ai {

  /// class Gardener - Create, fill the move Tree and calculate the best value to do
  class Gardener {
    // Associations
    // Attributes
  protected:
    std::vector<Node*> nodeWarehouse;
    int depthMax;
    state::State* state;
    engine::Ruler* ruler;
    int character;
    engine::CommandSet* commandsTest;
    DistanceUtility distanceUtility;
    std::vector<engine::ActionListTurn*> action;
    int ActualpvDif;
    // Operations
  public:
    Gardener (int depthMax, const state::State* state);
    Node* Start ();
    void changeMobile (state::ElementList* mobile);
  protected:
    void createChild (Node* Node);
    void evaluateScore (Node* node);
    void shot (int character);
    void nextOrientation (int character);
    Node* ApplyActionMax (Node* node);
    Node* ApplyActionMin (Node* node);
  };

};

#endif
