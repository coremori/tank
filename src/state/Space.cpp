#include "state.hpp"

namespace state {

  /// class Space - 
    // Associations
    // Operations
  
    Space::Space (int x,int y){
        this->x=x;
        this->y=y;
    };
    
    bool Space::isSpace () const {
        return true;
    };
    
    TypeId Space::getTypeId () const {
        return space;
    };
    
  };

