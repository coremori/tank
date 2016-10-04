/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Projectile - 
  class Projectile : public State::Mobile {
    // Associations
    State::OrientationMissile Orientation;
    // Operations
  public:
    bool const isTank ();
    virtual bool const isMissile () = 0;
    OrientationMissile const getOrientation ();
    void setOrientation (OrientationMissile o);
  };

};
