#include "state.hpp"
#include "SpaceTypeId.h"

namespace state {

  /// class Space - 

    // Associations
    state::SpaceTypeId SpaceType;
    // Operations
  
    Space::Space (int x,int y){

    };
    
    bool Space::isSpace () const {
        return true;
    };
    
    TypeId Space::getTypeId () const {
        return space;
    };
    
  };

