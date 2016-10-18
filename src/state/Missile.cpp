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
   
   bool Missile::isMissile() const {
       return true;
   };
    
    void Missile::setCeiling (int p){
        this->Ceiling = p;
    };
    
    int Missile::getCeiling () const {
        return this->Ceiling;
    };
    
    void Missile::setDistance (int d){
        this->DistanceActuel = d;
    };
    
    int Missile::getDistance () const {
        return this->DistanceActuel;
    };
    
    TypeId Missile::getTypeId () const {
        return missile;
    };
};


