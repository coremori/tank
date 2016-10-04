/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

namespace State {

  /// class ElementAlloc - 
  template <  class E,   typename ID>
  class ElementAlloc : public State::AElementAlloc {
    // Attributes
  protected:
    ID id;
    // Operations
  public:
    ElementAlloc (ID id);
    Element* newInstance ();
  };

};