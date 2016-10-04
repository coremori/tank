/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Tank - 
  class Tank : public State::Mobile {
    // Associations
    State::Orientation Orientation;
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
    Orientation const getOrientation ();
    void setOrientation (Orientation o);
  };

};