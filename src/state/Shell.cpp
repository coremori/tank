/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "state.hpp"

namespace state {

  
    Shell::Shell(){};
  
    bool const Shell::isMissile (){
        return false;
        
    };
    
    TypeId const Shell::getTypeId (){
        return shell;
    };
};
