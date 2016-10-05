/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

namespace state {

  /// class ElementList -  
     
    ElementList::ElementList (State& s){
        this->s = s;
    };
    
    
    ElementList::~ElementList (){
        factory.delete();
    };
}
   
    int const size (){
        return elements.size();
    };
        
    Element* const get ( int idx){
        assert(size()>idx && idx>=0);
        return elements[idx];
    };
        
    void clear (){//not implemented
        
    };
    
    void setElementFactory (ElementFactory* f){
        this->factory = f;
    };

    void set ( int idx, Element* e){
        elements[idx] = e;
    };
    
    
    
  };

};
