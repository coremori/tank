/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"

namespace State {

  /// class Space - 

    // Associations
    State::SpaceTypeId SpaceTypeId;
    // Operations
  
    Space::Space (){
        
    };
    
    bool const Space::isSpace (){
        return true;
    };
    
    TypeId const Space::getTypeId (){
        return Space;
    };
    
    Element const Space::clone (){
        Element clone = new Space();
        clone.SpaceTypeId = this->SpaceTypeId;
        return clone;
    };
    
    bool const Space::equals (const Element& other){
        return (Element::equals(other))&&(getSpaceTypeId(other)==this->SpaceTypeId);
    };
    
    void Space::setSpaceTypeId (SpaceTypeId id){
        this->SpaceTypeId = id;
    };
        
    SpaceTypeId const Space::getSpaceTypeId (){
        return this->SpaceTypeId;
    };
  };

