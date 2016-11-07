#ifndef ENGINE__RULER__H
#define ENGINE__RULER__H

#include "../state.h"

namespace engine {
  class ActionListTurn;
  class CommandSet;
  class Engine;
}

#include "ActionListTurn.h"

namespace engine {

  /// class Ruler - //crée les actions à partir des commandes : aller à droite tourne le char vers la droite et bouge à droite (2 actions donc)
  class Ruler {
    // Associations
    // Attributes
  protected:
    ActionListTurn* actions;
    state::State* state;
    CommandSet* cmd;
    Engine* engine;
    // Operations
  public:
    Ruler (Engine* engine);
    void setCommandSet (CommandSet* const cmd);
    void setActions (ActionListTurn* const actions);
    void apply ();
    void setState (state::State* s);
  };

};

#endif
