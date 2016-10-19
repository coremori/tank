/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

    Tank::Tank(TankTypeId tanktypeid, PlayerType playertype, Orientation orientation,int x,int y){
    this->TankType = tanktypeid;
    this->orientation = orientation;
    this->Player = playertype;
    this->x=x;
    this->y=y;
    this->pv = 100;
    };
    
    
    bool Tank::isTank () const  {
        return true;
    };
    
    TypeId Tank::getTypeId () const {
        return tank;
    };
    
    
    bool Tank::isPlayer () const {
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
    
  };

