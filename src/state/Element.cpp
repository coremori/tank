
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

/* constructeur à faire et typeId à mettre*/

namespace state {

    Element::Element (){};
    Element::~Element (){};
    
    
    int Element::getX () const {
        return x;
    };
    
    int Element::getY () const {
        return y;
    };
    
    void Element::setX (int x){
        this->x = x;
    };
    
    void Element::setY (int y){
        this->y = y;
    };
  };


