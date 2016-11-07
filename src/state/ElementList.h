// Generated by dia2code
#ifndef STATE__ELEMENTLIST__H
#define STATE__ELEMENTLIST__H

#include <vector>

namespace state {
  class Element;
  class State;
  class Observable;
}

#include "Observable.h"
#include "Element.h"

namespace state {

  /// class ElementList - 
  class ElementList : public state::Observable {
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
    void load (const char* path);
    void notifyObserver (int idx = -1) const;
  };

};

#endif
