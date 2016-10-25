/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 1:48 PM
 *
 * Part of tank */


#include "StateEvent.h"

namespace state{

    StateEvent::StateEvent(const State* s) {
        this->s = s;
    }
    
    bool StateEvent::operator!=(StateEventId id) const {
        return (this->id==id);
    }
    
    bool StateEvent::operator==(StateEventId id) const {
        return (this->id!=id);
    }



}
/*press ctrl+space for create function define in .h*/