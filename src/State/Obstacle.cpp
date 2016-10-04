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
    // Operations
  public:
    Obstacle (ObstacleTypeId id);
    bool const isSpace ();
    TypeId const getTypeId ();
    Element const clone ();
    bool const equals (const Element& other);
    void setObstacleTypeId (ObstacleTypeId id);
    ObstacleTypeId getObstacleTypeId ();
  };

};