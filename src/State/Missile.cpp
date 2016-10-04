/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

namespace State {

  /// class Missile - 
  class Missile : public State::Projectile {
    // Attributes
  public:
    int Ceiling;
    int DistanceActuel;
    // Operations
  public:
    Missile ();
    Element const clone ();
    bool const equals (const Element& other);
    void setCeiling (int p);
    int const getCeiling ();
    void setDistance (int d);
    int getDistance ();
  };

};
