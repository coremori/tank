// Generated by dia2code
#ifndef AI__TREEAI__H
#define AI__TREEAI__H

#include "state/State.h"
#include "engine/CommandSet.h"

namespace ai {
  class EvolvedAI;
  class Gardener;
}

#include "EvolvedAI.h"
#include "Gardener.h"

namespace ai {

  /// class TreeAI - 
  class TreeAI : public ai::EvolvedAI {
    // Associations
    // Operations
  public:
    TreeAI (state::State* state, int character);
    void run (engine::CommandSet& commands);
  };

};

#endif
