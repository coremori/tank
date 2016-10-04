/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"
#include "Missile.h"

namespace State {

   Missile::Missile (){};
   
    Element const Missile::clone (){
        Element newElement = new Missile();
        newElement.setCeiling(this->Ceiling);
        newElement.setDistance(this->DistanceActuel);
        return newElement;        
    };
    
    bool const Missile::equals (const Element& other){
        bool e = (other.x == this->x)&&(other.y == this->y);
        bool p = (not other.isStatic());
        bool j = not other.isTank();
        bool h = other.isMissile();
        bool k = other.Ceiling == this->Ceiling)&&(other.DistanceActuel == this->DistanceActuel);
        return 
    };
    
    
    
    
    
    
    void Missile::setCeiling (int p){
        this->Ceiling = p;
    };
    
    int const Missile::getCeiling (){
        return this->Ceiling;
    };
    
    void Missile::setDistance (int d){
        this->DistanceActuel = d;
    };
    
    int Missile::getDistance (){
        return this->DistanceActuel;
    };
 


