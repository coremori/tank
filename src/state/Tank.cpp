/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

    Tank::Tank (){};
    
    
    bool const Tank::isTank () {
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
    
    state::Orientation const Tank::getOrientation (){
        return orientation;
    };
    
    void Tank::setOrientation (state::Orientation o){
        this->orientation = o;
    };
    
    void Tank::setTankTypeId (TankTypeId id){
        TankType = id;
    };
    
    TankTypeId Tank::getTankTypeId (){
        return TankType;
    };
    
  };

