// Generated by dia2code
#ifndef STATE__ELEMENTEVENT__H
#define STATE__ELEMENTEVENT__H

#include "state/StateEvent.h"

namespace state {
  class ElementList;
  class StateEvent;
}

#include "StateEvent.h"

namespace state {

  /// class ElementEvent - Event "Element_Changed"
  class ElementEvent : public state::StateEvent {
    // Attributes
  public:
    const ElementList* list;
    int idx;
    // Operations
  public:
    ElementEvent (const ElementList* list, int idx = -1);
    StateEvent* clone () const;
  };

};

#endif
