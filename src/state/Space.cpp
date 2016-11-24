#include "state.h"
#include "Space.h"
namespace state {

  /// class Space - 
    // Associations
    // Operations
  
    Space::Space (SpaceTypeId id, int x,int y){
        this->x=x;
        this->y=y;
        this->SpaceType = id;
    };
    
    bool Space::isSpace () const {
        return true;
    };
    
    TypeId Space::getTypeId () const {
        return space;
    };
        
    SpaceTypeId Space::getSpaceTypeId() const {
        return SpaceType;
    }
        
    Element* Space::clone() const {
        Space* toto = new Space(SpaceType, x, y);
        return toto;
    }


  };

