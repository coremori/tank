// Generated by dia2code
#ifndef STATE__PROJECTILE__H
#define STATE__PROJECTILE__H


namespace state {
  class Mobile;
}

#include "OrientationMissile.h"
#include "Mobile.h"

namespace state {

  /// class Projectile - 
  class Projectile : public state::Mobile {
    // Associations
    state::OrientationMissile Orientation;
    // Operations
  public:
    virtual bool const isTank ();
    virtual bool const isMissile () = 0;
    OrientationMissile const getOrientation ();
    void setOrientation (OrientationMissile o);
  };

};

#endif
