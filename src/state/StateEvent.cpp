/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

  
    void StateEvent::StateEvent (const Stade& s, StateEventId id);
    virtual StateEvent::~StateEvent ();
    virtual StateEvent::StateEvent* const clone ();
    bool const StateEvent::operator== (StateEvenId id);
    bool const StateEvent::operator!= (StateEvenId id);
  

};