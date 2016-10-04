/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

/* constructeur à faire et typeId à mettre*/

namespace State {

    Element::Element (){};
    virtual Element::~Element (){};
    
    virtual TypeId const Element::getTypeId () = 0;
    virtual bool const Element::isStatic () = 0;
    virtual Element const Element::clone () = 0;
    
    virtual bool const Element::equals (const Element& other){
        return (this->x == other.x)&&(this->y == other.y);
    };
    
    int const Element::getX (){
        return x;
    };
    
    int const Element::getY (){
        return y;
    };
    
    void Element::setX (int x){
        this->x = x;
    };
    
    void Element::setY (int y){
        this->y = y;
    };
  };


