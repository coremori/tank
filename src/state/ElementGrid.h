// Generated by dia2code
#ifndef STATE__ELEMENTGRID__H
#define STATE__ELEMENTGRID__H


namespace state {
  class State;
  class Element;
  class ElementList;
}

#include "ElementList.h"

namespace state {

  /// class ElementGrid - 
  class ElementGrid : public state::ElementList {
    // Attributes
  protected:
    int width;
    int height;
    // Operations
  public:
    ElementGrid (State& s);
    int const getWidth ();
    int const getHeight ();
    Element* const getCell (int i, int j);
    bool const isSpace (int i, int j);
    void setCell (int i, int j, Element* e);
    bool const hasCell (int i, int j);
  };

};

#endif