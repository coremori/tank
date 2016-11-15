#include "state.h"

/* constructeur à faire et typeId à mettre*/

namespace state {

    Element::Element (){
        x=0;
        y=0;
    };
    
    Element::~Element (){};
    
    
    int Element::getX () const {
        return x;//pixels
    };
    
    int Element::getY () const {
        return y;//pixels
    };
    
    void Element::setX (int x){
        this->x = x;
    };
    
    void Element::setY (int y){
        this->y = y;
    };
};


