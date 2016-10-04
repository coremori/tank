/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"


namespace State {

  /// class Mobile - 
  class Mobile : public State::Element {
    // Attributes
  protected:
    int position;
    // Operations
  public:
    Tank ();
    bool const isStatic ();
    virtual bool const isTank () = 0;
    void setPosition (int position);
    int const getPosition ();
  };

};
