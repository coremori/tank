/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

namespace state {

   Missile::Missile (){
   this->Ceiling =10;
   this->DistanceActuel = 0;
   }
   
   bool const Missile::isMissile(){
       return true;
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
    
    TypeId const Missile::getTypeId (){
        return missile;
    };
};


