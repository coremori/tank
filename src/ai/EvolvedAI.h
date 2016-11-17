// Generated by dia2code
#ifndef AI__EVOLVEDAI__H
#define AI__EVOLVEDAI__H

#include "state/State.h"
#include "engine/CommandSet.h"

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
    // Operations
  public:
    EvolvedAI (state::State* state, int character);
    virtual void run (engine::CommandSet& commands) = 0;
  };

};

#endif