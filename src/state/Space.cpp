/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"
#include "SpaceTypeId.h"

namespace state {

  /// class Space - 

    // Associations
    state::SpaceTypeId SpaceType;
    // Operations
  
    Space::Space (){
        
    };
    
    bool const Space::isSpace (){
        return true;
    };
    
    TypeId const Space::getTypeId (){
        return space;
    };
    
    
    void Space::setSpaceTypeId (SpaceTypeId id){
        this->SpaceType = id;
    };
        
    state::SpaceTypeId const Space::getSpaceTypeId (){
        return this->SpaceType;
    };
  };

