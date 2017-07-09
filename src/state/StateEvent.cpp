/**
 * \file StateEvent.cpp
 * \brief Basique Event
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Basique Event
 *
 */


#include "StateEvent.h"

StateEvent::StateEvent(StateEventId id):
    f_id(id)
{
}



StateEvent::~StateEvent() {

}



///////////////////////////////////////////////////////////////////////
/// \fn operator==
/// \brief compare the stateevent id
/// \param id : StateEventId to compare
/// \return true if the f_id is id
/////////////////////////////////////////////////////////////////////////
bool StateEvent::operator==(StateEventId id) const {
    return (f_id==id);
}



///////////////////////////////////////////////////////////////////////
/// \fn operator!=
/// \brief compare the stateevent id
/// \param id : StateEventId to compare
/// \return false if the f_id is id
/////////////////////////////////////////////////////////////////////////
bool StateEvent::operator!=(StateEventId id) const {
    return (f_id!=id);
}




