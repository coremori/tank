/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Element.h"

#include "state.hpp"

namespace state {

  /// class ElementList -  c
     
    ElementList::ElementList (State& s) : s(s) {
    };
    
    
    ElementList::~ElementList (){
    };

   
    int const ElementList::size (){
        return elements.size();
    };
        
    Element* const ElementList::get ( int idx){
        assert(size()>idx && idx>=0);
        return elements[idx];
    };
        
    void ElementList::clear (){
        elements.clear();
    };
    
  
    void ElementList::set ( int idx, Element* e){
        elements[idx] = e;
    };
    
    

};
