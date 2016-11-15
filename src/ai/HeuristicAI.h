// Generated by dia2code
#ifndef AI__HEURISTICAI__H
#define AI__HEURISTICAI__H

#include "engine/CommandSet.h"
#include "state/State.h"

namespace ai {
  class AI;
}

#include "AI.h"
#include "Orientation.h"

namespace ai {

  /// class HeuristicAI - 
  class HeuristicAI : public ai::AI {
    // Associations
    ai::Orientation orientation;
    // Attributes
  public:
    engine::CommandSet* commands;
    // Operations
  public:
    HeuristicAI (state::State* state, int character);
    void run (engine::CommandSet& commands);
    void choice ();
    void nextOrientation ();
    int directionOtherChar ();
    int distanceOtherChar ();
    void shot ();
    void move (bool esquive);
    bool touchable ();
  };

};

#endif
