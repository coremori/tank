/**
 * \file StateElementManagerEvent.cpp
 * \brief Element Event Manager (level changed)
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element manager event class
 *
 */

#include "StateElementManagerEvent.h"

StateElementManagerEvent::StateElementManagerEvent(StateEventId id, ElementManager *managerChanged) :
    StateEvent(id),
    p_managerChanged(managerChanged)
{

}
