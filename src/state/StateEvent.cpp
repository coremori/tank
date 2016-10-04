/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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