/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

namespace state {

  /// class AElementAlloc - 
  class AElementAlloc {
    // Operations
  public:
    virtual ~AElementAlloc ();
    virtual Element* newInstance () = 0;
  };

};
