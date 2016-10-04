/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.h"

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
    
    bool const equals (const ElementList& other){//not implemented
        
    };
    
    void copy (const ElementList& list){
        //not implemented
    };
    
    
    const State& const getState ();
    int const size ();
    
    
    
    
    
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
        elements[i*width+j] = e;
    };
    
    
    
    void const notifyObservers (int  i = -1){//not implemented
    };
  };

};
