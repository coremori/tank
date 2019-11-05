/**
 * \file ElementMobile.cpp
 * \brief Element with mobility
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element with life and mobility. Inherit from ElementLiving.
 *
 */

#include "ElementMobile.h"

namespace state {

ElementMobile::ElementMobile (int x, int y, int direction,  int totalLife, int totalDefense, int id, bool canBeGetAcross , std::string name ):
	ElementLiving(totalLife, totalDefense, id, canBeGetAcross, name),
  f_Direction(direction)
{ 
}
    

  

   ///////////////////////////////////////////////////////////////////////
   /// \brief move
   /// \param dx mouvement x
   /// \param dy mouvement y
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
    void ElementMobile::move(const int dx, const int dy){
      f_X += dx;
      f_Y += dy;
    }
    
   ///////////////////////////////////////////////////////////////////////
   /// \brief getDirection
   /// \return ElementDirection
   /////////////////////////////////////////////////////////////////////// 
    int ElementMobile::getDirection() const{
        return f_Direction;
    }


   ///////////////////////////////////////////////////////////////////////
   /// \brief setDirection
   /// \param newDirection direction wanted
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
   void ElementMobile::setDirection(const int newDirection){
       f_Direction = newDirection;
   }

   ElementBase* ElementMobile::clone () const
   {
    
   }

}