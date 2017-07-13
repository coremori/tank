/**
 * \file ElementLiving.h
 * \brief Element with life
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element who have life. It herit from ElementBase.
 *
 */

#ifndef ELEMENTLIVING__H
#define ELEMENTLIVING__H

#include "Animation.h"
#include "ElementBase.h"
#include "ElementGraphic.h"
#include <string>




  /// class Element - 
  class ElementLiving : public ElementBase  {
    // Associations
    // Attributes
  protected:

    // Operations
  public:
  ElementLiving (int life, int defense, int id,  , ElementGraphic* graphic, bool canBeGetAcross = false, std::string name = NULL);
      
  ~ElementLiving();
      
  ///////////////////////////////////////////////////////////////////////
  /// \brief getLife
  /// \return Element f_life
  /////////////////////////////////////////////////////////////////////////    
  int getLife () const ;


  ///////////////////////////////////////////////////////////////////////
  /// \brief getDefense
  /// \return Element f_defense
  /////////////////////////////////////////////////////////////////////////   
  int getDefense () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getAnimation return the current animation
  /// If life <= 0, it return f_deadAnimation, f_lifeAnimation otherwise
  /// Please note that the function return a nullptr if no animation was specified
  /// \return Element current animation (f_deadAnimation if life <= 0, f_lifeAnimation otherwise) 
  /////////////////////////////////////////////////////////////////////////   
  Animation *getAnimation() const ;


  ///////////////////////////////////////////////////////////////////////
  /// \brief takeDamage
  /// \param power damage done to the life
  /// \param ignoreDefense if true, the defense is ignored
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void takeDamage(const int power, const bool ignoreDefense);



  private :
  int f_life;
  int f_defense;
  Animation *f_lifeAnimation;
  Animation *f_deadAnimation;

    };


#endif
