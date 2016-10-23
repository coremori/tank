/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

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
    
    ElementList& State::getMobiles () {
        return mobiles;
    };
    
    Element* State::getMobile (int idx){
        return this->mobiles.get(idx);
    };
      
    void State::load (const char* file_name){
        grid.load(file_name);
    };
   
   
   
  };



