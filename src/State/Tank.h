// Generated by dia2code
#ifndef STATE__TANK__H
#define STATE__TANK__H

#include "State.h"

namespace State {

  /// class Tank - 
  class Tank : public State::Mobile {
    // Associations
    State::PlayerType Player;
    State::TankTypeId TankType;
    // Attributes
  protected:
    int pv;
    // Operations
  public:
    Tank ();
    bool const equals (const Element& other);
    Element const clone ();
    bool const isTank ();
    TypeId const getTypeId ();
    bool const isPlayer ();
    void setPv (int pv);
    int const getPv ();
  };

};

#endif
