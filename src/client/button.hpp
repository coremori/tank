/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *  If not, you are juste stupid.
 */

/* 
 * File:   button.hpp
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 *
 * Created on January 3, 2017, 11:04 AM
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../engine/Command.h"
namespace client {
  class Pilote{
       public:
      void addCommand (engine::Command* command);
  };
}


#endif /* BUTTON_HPP */

