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
    State::State (){
        
    };
    State::~State (){ // supprime tout pour l'instant
        delete mobiles;
        delete grid;
    };
    
    State* const State::clone (){
        //not implemented
    };
    bool const State::equals (const State& other){
        //not implemented
    };
    
    const ElementGrid& const State::getGrid (){
        return grid;
    };
    
    const ElementList& const State::getMobiles (){
        return mobiles;
    };
    
    const Mobile* const State::getMobile ( int idx){
        return mobiles.get(idx);
    };
    
    
    
    
    
    void State::setGrid (const ElementGrid& grid){
        this->*grid = grid;
    };
    
    
    void State::setMobiles (const ElementList list){
        this->*mobiles = list;
    };
    
    
    void State::loadLevel (const char* file_name){
        delete grid;
        delete mobiles;
        grid = new ElementGrid();
        grid.load(file_name);
    };
    
    
    
    
    
    
    void State::setElementFactory (ElementFactory* factory){
        mobiles.setElementFactory (ElementFactory* factory);
        grid.setElementFactory (ElementFactory* factory);
    };
    
    void const State::notifyObservers (StateEventId id){
        //not implemented
    };
    void const State::notifyObservers (const StateEvent& e){
        //not implemented
    };
  };



