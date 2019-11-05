/**
 * \file ElementLiving.cpp
 * \brief Element with life
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Element who have life. It herit from ElementBase.
 *
 */


#include "ElementLiving.h"


  ElementLiving::ElementLiving (int life, int defense, int id, bool canBeGetAcross , std::string name ):
    ElementBase(id, canBeGetAcross, name),
    f_Life(life),
    f_Defense(defense)
  { 
    //TODO : Animation
  };
      
  ///////////////////////////////////////////////////////////////////////
  /// \brief getLife
  /// \return Element f_life
  /////////////////////////////////////////////////////////////////////////    
  int ElementLiving::getLife () const
  {
    return f_Life;
  };


  ///////////////////////////////////////////////////////////////////////
  /// \brief getDefense
  /// \return Element f_defense
  /////////////////////////////////////////////////////////////////////////   
  int ElementLiving::getDefense () const {
    return f_Defense;
  };


  ///////////////////////////////////////////////////////////////////////
  /// \brief takeDamage
  /// \param power damage done to the life
  /// \param ignoreDefense if true, the defense is ignored
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void ElementLiving::takeDamage(const int power, const bool ignoreDefense)
  {
    // if we ignore the defense
    if (ignoreDefense)
    {
      f_life -= power;
      return;
    }

    // Si on frappe moins que la defense, on sort
    if ((f_defense - power) > 0) return;

    f_life -=  (power - f_defense);

    return;
  };

  ElementBase* ElementLiving::clone () const
  {
    ElementLiving* newLivingElement = new ElementLiving(f_Life, f_Defense, f_Id, f_CanBeGetAcross, f_Name);
    return newLivingElement;
  }
