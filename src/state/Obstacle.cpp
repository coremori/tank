/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state{

  
    Obstacle::Obstacle (ObstacleTypeId id,int x,int y){
        this->ObstacleType = id;
        this->x=x;
        this->y=y;
    };
    
    bool Obstacle::isSpace () const {
        return false;
    };
    
    TypeId Obstacle::getTypeId () const {
        return obstacle;
    };
    
   
    
    void Obstacle::setObstacleTypeId (ObstacleTypeId id){
        this->ObstacleType = id;
    };
    
    ObstacleTypeId Obstacle::getObstacleTypeId () const {
        return this->ObstacleType;
    };
  

};