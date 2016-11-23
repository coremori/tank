// Generated by dia2code
#ifndef AI__EVOLVEDAI__H
#define AI__EVOLVEDAI__H

#include "engine/CommandSet.h"
#include "state/State.h"

namespace ai {
  class DistanceUtility;
  class AI;
}

#include "DistanceUtility.h"
#include "AI.h"

namespace ai {

  /// class EvolvedAI - Abstract class having the DistanceUtility
  class EvolvedAI : public ai::AI {
    // Associations
    // Attributes
  protected:
    DistanceUtility distanceUtility;
    engine::CommandSet* commands;
    // Operations
  public:
    EvolvedAI (state::State* state, int character);
    virtual void run (engine::CommandSet& commands) = 0;
    void nextOrientation ();
    void shot ();
  };

};

#endif
