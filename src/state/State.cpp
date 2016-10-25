/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"
#include "StateEventId.h"

namespace state {

  /// class State - mobiles-> liste des truc mobile (tank, missile)
  /* ElementList mobiles;
    ElementGrid grid;
    */
    State::State() : mobiles(*this), grid(*this) {
        
    };
    
    State::~State (){ // supprime tout pour l'instant
    };
    
    ElementGrid& State::getGrid () {
        return grid;
    };
    
   
    const ElementGrid& State::getGrid () const{
        return grid;
    };
    
    
    ElementList& State::getMobiles () {
        return mobiles;
    };
    
    const ElementList& State::getMobiles () const{
        return mobiles;
    };
    
    
    
    Element* State::getMobile (int idx){
        return this->mobiles.get(idx);
    };
    
    const Element* State::getMobile(int idx) const{
        return this->mobiles.get(idx);
    };
    
      
    void State::load (const char* file_name){
        grid.load(file_name);
        notifyObserver(*(new StateEvent(this, Level_Changed )));
    };
       
    void State::notifyObserver(const StateEvent& event) const {
        Observable::notifyObserver(event);
    }

   
   
  };



