

#include "state.h"

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

    
    TypeId Tank::getTypeId () const {
        return tank;
    };
        
    void Tank::setPv (int pv){
        if(pv<0){
            this->pv = 0;
        }
        else
        {
            this->pv = pv;
        }
    };
    
    int Tank::getPv () const {
        return this->pv;
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
        Tank* newtank = new Tank(TankType,orientation,x,y);
        newtank->setPv(pv);
        return newtank;
    }

    
  };

