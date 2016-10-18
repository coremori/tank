// Generated by dia2code
#ifndef STATE__SPACE__H
#define STATE__SPACE__H


namespace state {
  class StaticElement;
}

#include "SpaceTypeId.h"
#include "TypeId.h"
#include "StaticElement.h"

namespace state {

  /// class Space - 
  class Space : public state::StaticElement {
    // Associations
    state::SpaceTypeId SpaceType;
    // Operations
  public:
    Space (SpaceTypeId id);
    virtual bool isSpace () const;
    TypeId getTypeId () const;
    void setSpaceTypeId (SpaceTypeId id);
    SpaceTypeId getSpaceTypeId () const;
  };

};

#endif