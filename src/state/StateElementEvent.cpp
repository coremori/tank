/**
 * \file StateElementEvent.cpp
 * \brief Element Event
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element event class
 *
 */


#include "StateElementEvent.h"

StateElementEvent::StateElementEvent(StateEventId id, ElementBase *elementChanged):
    StateEvent(id),
    p_elementChanged(elementChanged)
{

}
