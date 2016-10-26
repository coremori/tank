// Generated by dia2code
#ifndef ENGINE__ACTIONMOVE__H
#define ENGINE__ACTIONMOVE__H

#include "../state.h"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class ActionMove - 
  class ActionMove : public engine::Action {
    // Attributes
  protected:
    int dx;
    int dy;
    int character;
    // Operations
  public:
    ActionMove (int dx, int dy, int character);
    void apply (state::State* s);
    void undo (state::State* s);
  };

};

#endif
