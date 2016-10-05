/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

namespace state {

  /// class ElementAlloc - 
  template <  class E,   typename ID>
  class ElementAlloc : public State::AElementAlloc {
    // Attributes
  protected:
    ID id;
 
      
      
    template <  class E,   typename ID>  ElementAlloc::ElementAlloc(ID id){
        
        setID(id);
        
    };
    
    
    
    template <  class E,   typename ID> Element* ElementAlloc::newInstance (){
        Element* newElement=  new E();
        newElement.set<ID>(this->id);
        return newElement;
    };
  };

};