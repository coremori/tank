/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class StaticElement - 
  class StaticElement : public State::Element {
    // Operations
  public:
    bool const isStatic ();
    virtual bool const isSpace () = 0;
  };

};