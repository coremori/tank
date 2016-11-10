// Generated by dia2code
#ifndef ENGINE__ACTIONLISTTURN__H
#define ENGINE__ACTIONLISTTURN__H

#include <vector>
#include "state/State.h"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class ActionListTurn - List of a turn's action
  class ActionListTurn {
    // Associations
    // Attributes
  protected:
    std::vector<Action*> actions;
    state::State* state;
    // Operations
  public:
    ActionListTurn (state::State* s);
    ~ActionListTurn ();
    void apply ();
    void undo ();
    void addAction (Action* a);
    void clear ();
  };

};

#endif
