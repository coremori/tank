/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ElementList.h"

namespace State {

  /// class State - mobiles-> liste des truc mobile (tank, missile)
  
    State::State (){
        
    };
    State::~State (){ // supprime tout pour l'instant
        delete mobiles;
        delete grid;
    };
    
    State* const clone ();
    bool const equals (const State& other);
    const ElementGrid& const getGrid ();
    const ElementList& const getMobiles ();
    const Mobile* const getMobile ( int idx);
    
    
    
    
    
    void setGrid (const ElementGrid& grid){
        this->*grid = grid;
    };
    
    
    void setMobiles (const ElementList list){
        this->*mobiles = list;
    };
    
    
    void loadLevel (const char* file_name);
    
    void State::setElementFactory (ElementFactory* factory){
        mobiles.setElementFactory (ElementFactory* factory);
        grid.setElementFactory (ElementFactory* factory);
    };
    
    void const notifyObservers (StateEventId id);
    void const notifyObservers (const StateEvent& e);
  };



