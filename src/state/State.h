// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementList;
  class ElementGrid;
  class Element;
}

#include "ElementList.h"
#include "ElementGrid.h"

namespace state {

  /// class State - mobiles-> liste des truc mobile (tank, misile)
  class State {
    // Associations
    // Attributes
  protected:
    ElementList mobiles;
    ElementGrid grid;
    // Operations
  public:
    State ();
    ~State ();
    const ElementGrid& getGrid ();
    ElementList&  getMobiles ();
    const Element* getMobile (int idx);
  };

};

#endif