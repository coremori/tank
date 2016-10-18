/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

    // state::OrientationMissile Orientation

  
    bool Projectile::isTank () const {
        return false;
    };
    
  
    
    OrientationMissile Projectile::getOrientation () const {
        return Orientation;
    };
    void Projectile::setOrientation (OrientationMissile o){
        Orientation = o;
    };
    
    Status Projectile::getStatus () const{
        return status;
    };
    
    void Projectile::setStatus (Status status){
        this->status = status;
    };
};
