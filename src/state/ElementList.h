// Generated by dia2code
#ifndef STATE__ELEMENTLIST__H
#define STATE__ELEMENTLIST__H

#include <vector>

namespace state {
  class ElementFactory;
  class Element;
  class State;
}

#include "Element.h"
#include "ElementFactory.h"

namespace state {

  /// class ElementList - 
  class ElementList {
    // Associations
    // Attributes
  protected:
    ElementFactory* factory;
    std::vector<Element*> elements;
    State& s;
    // Operations
  public:
    ElementList (State& s);
    ~ElementList ();
    int const size ();
    Element* const get ( int idx);
    void clear ();
    void setElementFactory (ElementFactory* f);
    void set ( int idx, Element* e);
  };

};

#endif
