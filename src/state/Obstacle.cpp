/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.h"
#include "Obstacle.h"

namespace state{

  
    Obstacle::Obstacle (ObstacleTypeId id,int x,int y){
        this->ObstacleType = id;
        this->x=x;
        this->y=y;
    };
    
    bool Obstacle::isSolid () const {
        return true;
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
      
    Element* Obstacle::clone() const {
        return new Obstacle(ObstacleType, x, y);
    }


};