/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "State.h"

namespace State {

  /// class ElementList - 
  class ElementList : public State::Observable {
    // Associations
    // Attributes
  protected:
    State s;
    ElementFactory* factory;
    std::vector<Element*> elements;
    // Operations
  public:
    ElementList (State& s);
    ~ElementList ();
    ElementList* const clone ();
    bool const equals (const ElementList& other);
    void copy (const ElementList& list);
    const State& const getState ();
    int const size ();
    Element* const get ( int idx);
    void clear ();
    void setElementFactory (ElementFactory* f);
    void set ( int idx, Element* e);
    void const notifyObservers (int  i = -1);
  };

};
