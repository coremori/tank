// Generated by dia2code
#ifndef STATE__STATEEVENT__H
#define STATE__STATEEVENT__H

#include "state/StateEvent.h"

namespace state {
  class State;
  class StateObserver;
}

#include "StateEventId.h"
#include "StateObserver.h"

namespace state {

  /// class StateEvent - 
  class StateEvent {
    // Associations
    state::StateEventId id;
    // Attributes
  public:
    const State* s;
    // Operations
  public:
    StateEvent (const State* s, StateEventId id);
    bool operator== (StateEventId id) const;
    bool operator!= (StateEventId id) const;
  };

};

#endif