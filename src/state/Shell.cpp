/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

  
    Shell::Shell(){};
  
    bool Shell::isMissile () const {
        return false;
        
    };
    
    TypeId Shell::getTypeId () const {
        return shell;
    };
};
