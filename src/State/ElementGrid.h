// Generated by dia2code
#ifndef STATE__ELEMENTGRID__H
#define STATE__ELEMENTGRID__H

#include "State.h"

namespace State {

  /// class ElementGrid - 
  class ElementGrid : public State::ElementList {
    // Attributes
  protected:
    int width;
    int height;
    // Operations
  public:
    ElementGrid (State& s);
    ElementGrid* const clone ();
    void copy (const ElementGrid& other);
    bool const equals (const ElementGrid& other);
    int const getWidth ();
    int const getHeight ();
    Element* const getCell (int i, int j);
    bool const isSpace ();
    void setCell (int i, int j, Element* e);
    hasCell (int i, int j);
    void load (const char* file_name);
    void const notifyObservers (int i = -1, int j = -1);
  };

};

#endif
