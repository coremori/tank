/**
 * \file StateElementManagerEvent.h
 * \brief Element Event Manager (level changed)
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element manager event class
 *
 */

#ifndef STATEELEMENTMANAGEREVENT_H
#define STATEELEMENTMANAGEREVENT_H

#include "StateEvent.h"
#include "ElementManager.h"

class StateElementManagerEvent : public StateEvent
{
public:
    StateElementManagerEvent(StateEventId id, ElementManager *managerChanged);

    ElementManager *p_managerChanged;
};

#endif // STATEELEMENTMANAGEREVENT_H
