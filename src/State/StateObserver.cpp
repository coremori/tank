/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class StateObserver - 
  class StateObserver {
    // Operations
  public:
    virtual void StateChanged (const StateEvent& e) = 0;
  };

};
