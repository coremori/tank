/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

    // state::OrientationMissile Orientation

  
    bool const Projectile::isTank (){
        return false;
    };
    
  
    
    OrientationMissile const Projectile::getOrientation (){
        return Orientation;
    };
    void Projectile::setOrientation (OrientationMissile o){
        Orientation = o;
    };
  
};
