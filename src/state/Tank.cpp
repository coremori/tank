/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

    Tank::Tank (){};
    
    virtual bool const Tank::equals (const Element& other){//not implemented
    
    };
    virtual Element* const Tank::clone (){
        //not implemented
    };
    
    virtual bool const Tank::isTank () override {
        return true;
    };
    
    TypeId const Tank::getTypeId (){
        return tank;
    };
    
    
    bool const Tank::isPlayer (){
        return Player;
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
    
    int const Tank::getPv (){
        return this->pv;
    };
    
    Orientation const Tank::getOrientation (){
        return Orientation;
    };
    
    void Tank::setOrientation (Orientation o){
        this->Orientation = o;
    };
    
    void Tank::setTankTypeId (TankTypeId id){
        TankType = id;
    };
    
    TankTypeId Tank::getTankTypeId (){
        return TankType;
    };
  };

};