

#include "state.h"
#include "Tank.h"

namespace state {

    Tank::Tank(TankTypeId tanktypeid, Orientation orientation,int x,int y){
    this->TankType = tanktypeid;
    this->orientation = orientation;
    this->x=x;
    this->y=y;
    this->pv = 100;
    };
    
    bool Tank::isStatic() const {
        return false;
    }

    bool Tank::isSolid () const
    {
        // on ne peut pas être traversé
        return true;
    }

    
    TypeId Tank::getTypeId () const {
        return tank;
    };
           
    state::Orientation Tank::getOrientation () const {
        return orientation;
    };
    
    void Tank::setOrientation (state::Orientation o){
        this->orientation = o;
    };
    
    void Tank::setTankTypeId (TankTypeId id){
        TankType = id;
    };
    
    TankTypeId Tank::getTankTypeId () const {
        return TankType;
    };
        
    Element* Tank::clone() const {
        Tank* newtank(new Tank(TankType, orientation, x, y));
        newtank->setPV(pv);
        return newtank;
    }

    
  };

