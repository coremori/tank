/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 1:48 PM
 *
 * Part of tank */


#include "StateEvent.h"

namespace state{

    StateEvent::StateEvent(const State* s, StateEventId id) {
        this->s = s;
        this->id = id;
    }
        
    StateEvent::~StateEvent() {

    }

    
    bool StateEvent::operator==(StateEventId id) const {
        return (this->id==id);
    }
    
    bool StateEvent::operator!=(StateEventId id) const {
        return (this->id!=id);
    }

    StateEvent* StateEvent::clone() const {
        return new StateEvent(s, id);
    }
  

}
/*press ctrl+space for create function define in .h*/