#ifndef STATE__STATE__H
#define STATE__STATE__H

#include "state/StateEvent.h"

namespace state {
  class ElementList;
  class ElementGrid;
  class Element;
  class StateEvent;
  class Observable;
}

#include "ElementList.h"
#include "ElementGrid.h"
#include "Observable.h"

namespace state {

  /// class State - mobiles-> liste des trucs mobiles (tank, missile)
  class State : public state::Observable {
    // Associations
    // Attributes
  protected:
    ElementList mobiles;
    ElementGrid grid;
    // Operations
  public:
    State ();
    ~State ();
    ElementGrid& getGrid ();
    const ElementGrid& getGrid () const;
    ElementList& getMobiles ();
    const ElementList& getMobiles () const;
    Element* getMobile (int idx);
    const Element* getMobile (int idx) const;
    void load (const char* file_name);
    void notifyObserver (const StateEvent& event) const;
  };

};

#endif
