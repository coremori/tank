// Generated by dia2code
#ifndef STATE__ELEMENTGRID__H
#define STATE__ELEMENTGRID__H


namespace state {
  class ElementGrid;
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
    ElementGrid ();
    ElementGrid* const clone ();
    void copy (const ElementGrid& other);
    bool const equals (const ElementGrid& other);
    int const getWidth ();
    int const getHeight ();
    Element* const getCell (int i, int j);
    bool const isSpace (int i, int j);
    void setCell (int i, int j, Element* e);
    bool const hasCell (int i, int j);
    void load (const char* file_name);
    void const notifyObservers (int i = -1, int j = -1);
  };

};

#endif
