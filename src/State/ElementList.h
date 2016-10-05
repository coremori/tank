// Generated by dia2code
#ifndef STATE__ELEMENTLIST__H
#define STATE__ELEMENTLIST__H

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

#endif