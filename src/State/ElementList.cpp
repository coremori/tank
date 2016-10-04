/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

namespace State {

  /// class ElementList - 
 
  
    
    
    
    ElementList::ElementList (State& s){
        this->*s = s;
       
        
    };
    
    
    ElementList::~ElementList (){
        factory.delete();
        
        
    };
}
    ElementList* const ElementList::clone (){
        ElementList* list = new ElementList();
        setElementFactory(factory);
        int i=0;
        while(){
            list.set(i,this->elements(i));
        
        };
        
        return list;
    } ;
    
    bool const equals (const ElementList& other);
    void copy (const ElementList& list);
    const State& const getState ();
    int const size ();
    Element* const get ( int idx);
    void clear ();
    void setElementFactory (ElementFactory* f);
    void set ( int idx, Element* e);
    void const notifyObservers (int  i = -1);
  };

};
