/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

    // state::OrientationMissile Orientation

  
    virtual bool const Projectile::isTank () override{
        return false;
    };
    
    virtual bool const Projectile::isMissile () = 0;
    
    OrientationMissile const Projectile::getOrientation (){
        return Orientation;
    };
    void Projectile::setOrientation (OrientationMissile o){
        Orientation = o;
    };
  
};
