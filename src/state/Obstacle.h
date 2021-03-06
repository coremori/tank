// Generated by dia2code
#ifndef STATE__OBSTACLE__H
#define STATE__OBSTACLE__H


namespace state {
  class Element;
  class StaticElement;
}

#include "ObstacleTypeId.h"
#include "TypeId.h"
#include "StaticElement.h"

namespace state {

  /// class Obstacle - 
  class Obstacle : public state::StaticElement {
    // Associations
    state::ObstacleTypeId ObstacleType;
    // Operations
  public:
    Obstacle (ObstacleTypeId id, int x, int y);
    virtual bool isSpace () const;
    TypeId getTypeId () const;
    void setObstacleTypeId (ObstacleTypeId id);
    ObstacleTypeId getObstacleTypeId () const;
    Element* clone () const;
  };

};

#endif
