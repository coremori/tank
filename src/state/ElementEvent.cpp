/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 1:50 PM
 *
 * Part of tank */


#include "ElementEvent.h"
#include "StateEventId.h"
#include <cstddef>

namespace state {

    ElementEvent::ElementEvent(const ElementList* list, int idx) : StateEvent(NULL, Element_Changed) {
        this->list = list;
        this->idx = idx;
    }

    StateEvent* ElementEvent::clone() const {
        return new ElementEvent(list, idx);
    }


}