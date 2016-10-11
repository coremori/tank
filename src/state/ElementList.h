// Generated by dia2code
#ifndef STATE__ELEMENTLIST__H
#define STATE__ELEMENTLIST__H

#include <vector>

namespace state {
  class Element;
  class State;
}

#include "Element.h"

namespace state {

  /// class ElementList - 
  class ElementList {
    // Associations
    // Attributes
  protected:
    std::vector<Element*> elements;
    State& s;
    // Operations
  public:
    ElementList (State& s);
    ~ElementList ();
    int size () const;
    Element* get ( int idx) const;
    void clear ();
    void set ( int idx, Element* e);
  };

};

#endif
