/**
 * \file StateEvent.h
 * \brief Basique Event
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Basique Event
 *
 */


#ifndef STATEEVENT_H
#define STATEEVENT_H

#include "StateEventid.h"
class StateEvent
{
public:
    StateEvent(StateEventId id);
    virtual ~StateEvent();

    ///////////////////////////////////////////////////////////////////////
    /// \fn operator==
    /// \brief compare the stateevent id
    /// \param id : StateEventId to compare
    /// \return true if the f_id is id
    /////////////////////////////////////////////////////////////////////////
    bool operator== (StateEventId id) const;

    ///////////////////////////////////////////////////////////////////////
    /// \fn operator!=
    /// \brief compare the stateevent id
    /// \param id : StateEventId to compare
    /// \return false if the f_id is id
    /////////////////////////////////////////////////////////////////////////
    bool operator!= (StateEventId id) const;

private:
    StateEventId f_id;

};

#endif // STATEEVENT_H
