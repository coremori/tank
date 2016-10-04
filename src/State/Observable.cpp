/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

namespace State {

  /// class Observable - 
  class Observable {
    // Associations
    // Attributes
  protected:
    mutable std::vector<StateOberver*> observers;
    // Operations
  public:
    virtual ~Observable ();
    void const registerObserver (StateObserver* o);
    void const unregisterObserver (const StateEvent& e);
  };

};
