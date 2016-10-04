/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Space - 
  class Space : public State::StaticElement {
    // Associations
    State::SpaceTypeId SpaceTypeId;
    // Operations
  public:
    Space ();
    bool const isSpace ();
    TypeId const getTypeId ();
    Element const clone ();
    bool const equals (const Element& other);
    void setSpaceTypeId (SpacetypeId id);
    SpaceTypeId getSpaceTypeId ();
  };

};