// Generated by dia2code
#ifndef ENGINE__ACTION__H
#define ENGINE__ACTION__H

#include "state/State.h"

namespace engine {

  /// class Action - API of the differents action - Apply() for doing the action - Undo() for undo the action
  class Action {
    // Operations
  public:
    Action ();
    virtual void apply (state::State* s) = 0;
    virtual void undo (state::State* s) = 0;
  };

};

#endif
