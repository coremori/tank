// Generated by dia2code
#ifndef STATE__MOBILE__H
#define STATE__MOBILE__H

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

#endif
