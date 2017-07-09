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



ElementMobile::ElementMobile (int x, int y, int direction,  Move_Type moveType, int life, int defense, int id, bool canBeGetAcross , std::string name ):
	ElementLiving(life, defense, id, canBeGetAcross, name),
	f_x(x),
	f_y(y),
  f_direction(direction),
  f_moveType(moveType)
{ 
}
    

    
   ///////////////////////////////////////////////////////////////////////
   /// \brief getX
   /// \return Element position x 
   /////////////////////////////////////////////////////////////////////////    
    int ElementMobile::getX () const {
        return f_x;
    }


   ///////////////////////////////////////////////////////////////////////
   /// \brief getY
   /// \return Element position y
   /////////////////////////////////////////////////////////////////////////   
    int ElementMobile::getY () const {
        return f_y;
    }
    
   ///////////////////////////////////////////////////////////////////////
   /// \brief getMoveType
   /// \return Element Move_Type
   /////////////////////////////////////////////////////////////////////////   
    Move_Type ElementMobile::getMoveType () const {
        return f_moveType;
    }


   ///////////////////////////////////////////////////////////////////////
   /// \brief move
   /// \param dx mouvement x
   /// \param dy mouvement y
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
    void ElementMobile::move(const int dx, const int dy){
      f_x += dx;
      f_y += dy;
    }
    
   ///////////////////////////////////////////////////////////////////////
   /// \brief getDirection
   /// \return ElementDirection
   /////////////////////////////////////////////////////////////////////// 
    int ElementMobile::getDirection() const{
        return f_direction;
    }


   ///////////////////////////////////////////////////////////////////////
   /// \brief setDirection
   /// \param newDirection direction wanted
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
   void ElementMobile::setDirection(const int newDirection){
       f_direction = newDirection;
   }



