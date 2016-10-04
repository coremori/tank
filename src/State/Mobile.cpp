/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"


#include "State.h"

namespace State {

    bool const Mobile::isStatic (){
        return false;
    };
    virtual bool const Mobile::isTank () = 0;
  

};
