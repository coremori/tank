// Generated by dia2code
#ifndef STATE__STATEEVENT__H
#define STATE__STATEEVENT__H

#include "State.h"

namespace State {

  /// class StateEvent - 
  class StateEvent : public State::ListEven {
    // Associations
    // Attributes
  public:
    const State state;
    // Operations
  public:
    void StateEvent (const Stade& s, StateEventId id);
    virtual ~StateEvent ();
    virtual StateEvent* const clone ();
    bool const operator== (StateEvenId id);
    bool const operator!= (StateEvenId id);
  };

};

#endif
