/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Obstacle - 
  class Obstacle : public State::StaticElement {
    // Associations
    State::ObstacleTypeId ObstacleType;
    // Attributes
  public:
     ;
     
    Obstacle::Obstacle (ObstacleTypeId id){
        this->ObstacleType = id;
    };
    
    bool const Obstacle::isSpace (){
        return false;
    };
    
    TypeId const Obstacle::getTypeId (){
        return obstacle;
    };
    
    Element* const Obstacle::clone (){
        Element clone = new Obstacle(this->ObstacleTypeId);
        return *clone;
    };
    
    bool const Obstacle::equals (const Element& other){
        return
    };
    
    void Obstacle::setObstacleTypeId (ObstacleTypeId id){
        this->ObstacleType = id;
    };
    
    ObstacleTypeId const Obstacle::getObstacleTypeId (){
        return this->ObstacleType;
    };
  };

};