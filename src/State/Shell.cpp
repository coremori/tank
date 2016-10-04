/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Shell - 
  class Shell : public State::Projectile {
    // Operations
  public:
    Shell ();
    Element const clone ();
    bool const equals (const Element& other);
  };

};
