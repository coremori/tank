/**
 * \file StateEventId.h
 * \brief Event type enum
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Enum of all the event possible
 *
 */


#ifndef STATEEVENTID_H
#define STATEEVENTID_H

enum StateEventId {
    Need_Global_Graphic_Rebuild = 1,
    ElementGraphic_Changed     = 2,
    Element_Info_Changed = 3,
    New_Animation = 4,
    Delete_Animation = 5
};


#endif // STATEEVENTID_H
