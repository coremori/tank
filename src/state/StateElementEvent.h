/**
 * \file StateElementEvent.h
 * \brief Element Event
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element event class
 *
 */

#ifndef STATEELEMENTEVENT_H
#define STATEELEMENTEVENT_H

#include "StateEvent.h"
#include "ElementBase.h"

class StateElementEvent : public StateEvent
{
public:
    StateElementEvent(StateEventId id, ElementBase *elementChanged);

    ElementBase *p_elementChanged;
private:

};

#endif // STATEELEMENTEVENT_H
