/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

/* constructeur à faire et typeId à mettre*/

namespace State {

  /// class Element - 
  class Element {
    // Associations
    State::TypeId test;
    // Attributes
  protected:
    int x; //position x
    int y;
    // Operations
  public:
    Element ();
    virtual ~Element ();
    virtual TypeId const getTypeId () = 0;
    virtual bool const isStatic () = 0;
    virtual Element const clone () = 0;
    
    virtual bool const equals (const Element& other){
        return (this->x == other.x)&&(this->y == other.y);
    };
    
    int const getX (){
        return x;
    };
    
    int const getY (){
        return y;
    };
    
    void setX (int x){
        this->x = x;
    };
    
    void setY (int y){
        this->y = y;
    };
  };

};
