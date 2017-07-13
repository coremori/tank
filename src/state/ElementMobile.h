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

#ifndef ELEMENTMOBILE__H
#define ELEMENTMOBILE__H



#include <string>

#include "MoveType.h"
#include "ElementLiving.h"


  class ElementMobile;



  /// class Element - 
  class ElementMobile : public ElementLiving {
    // Associations
    // Attributes
  protected:

    // Operations
  public:
    ElementMobile (int x, int y, int direction, Move_Type moveType, int life, int defense, int id, ElementGraphic* graphic, bool canBeGetAcross = false, std::string name = NULL);


	///////////////////////////////////////////////////////////////////////
	/// \brief getX
	/// \return Element position x 
	/////////////////////////////////////////////////////////////////////////    
    int getX () const;



	///////////////////////////////////////////////////////////////////////
	/// \brief getY
	/// \return Element position y
	/////////////////////////////////////////////////////////////////////////   
    int getY () const;


   ///////////////////////////////////////////////////////////////////////
   /// \brief move
   /// \param dx mouvement x
   /// \param dy mouvement y
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
    void move(const int dx, const int dy);

    
   ///////////////////////////////////////////////////////////////////////
   /// \brief getDirection
   /// \return ElementDirection
   /////////////////////////////////////////////////////////////////////// 
    int getDirection() const;

   ///////////////////////////////////////////////////////////////////////
   /// \brief setDirection
   /// \param newDirection direction wanted
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
   void setDirection(const int newDirection);

	///////////////////////////////////////////////////////////////////////
	/// \brief getMoveType
	/// \return Element Move_Type
	/////////////////////////////////////////////////////////////////////////   
    Move_Type getMoveType () const ;


    private :
    int f_x; //position x
    int f_y; //position y
    int f_direction; //direction
    Move_Type f_moveType; // move who can be used by the element


  };

    




#endif
