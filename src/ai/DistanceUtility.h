// Generated by dia2code
#ifndef AI__DISTANCEUTILITY__H
#define AI__DISTANCEUTILITY__H

#include "state/State.h"

namespace ai {

  /// class DistanceUtility - Function for determing the fire range and the distance between the two player
  class DistanceUtility {
    // Attributes
  protected:
    int distance;
    // Operations
  public:
    DistanceUtility ();
    void updateDistance (state::State* state, int character);
    bool inShellFireRange (state::State* state, int CharShoting) const;
    bool inMissileFireRange () const;
    int getDistance () const;
  };

};

#endif
