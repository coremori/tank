/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"
#include <assert.h> 

namespace State {

  /// class ElementGrid - 

    // Attributes
/*  protected:
    int width;
    int height;
    // Operations
  public:*/
    ElementGrid::ElementGrid (State& s){
        this->ElementList::s = s;
        this->width = 0;
        this->height =0;
    };
    
    ElementGrid* const ElementGrid::clone ();
    void ElementGrid::copy (const ElementGrid& other);
    bool const ElementGrid::equals (const ElementGrid& other);
    
    
    
    int const ElementGrid::getWidth (){
        return width;
    };
    
    int const ElementGrid::getHeight (){
        return height;
    };
        
    Element* const ElementGrid::getCell (int i, int j){ 
        // retourne l'element à la place ligne i, colonne j du tableau
        // error s'il n'existe pas
        assert (this->hasCell(i,j),"Cell not in tab"); VERIFIER ASSERT
        return ElementList::elements[i*width+j];

    };
          
    bool const ElementGrid::isSpace (){
        
    };
    void ElementGrid::setCell (int i, int j, Element* e);
    bool const ElementGrid::hasCell (int i, int j);
    void ElementGrid::load (const char* file_name);
    void const ElementGrid::notifyObservers (int i = -1, int j = -1);
  };


