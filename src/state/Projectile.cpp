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
