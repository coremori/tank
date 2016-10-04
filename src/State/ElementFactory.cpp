/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"


namespace State {

  /// class ElementFactory - 
  class ElementFactory {
    // Associations
    // Attributes
  protected:
    std map::<char ,AElementAlloc*> list;
    // Operations
  public:
    ~ElementFactory ();
    Element* const newInstance (char id);
    void registerType (char id, AElementAlloc* a);
  };

};