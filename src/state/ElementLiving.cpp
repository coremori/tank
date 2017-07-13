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


  ElementLiving::ElementLiving (int life, int defense, int id, ElementGraphic* graphic, bool canBeGetAcross , std::string name ):
    ElementBase(id, canBeGetAcross, graphic, name),
    f_life(life),
    f_defense(defense),
    f_lifeAnimation(nullptr),
    f_deadAnimation(nullptr)
  { 
    //TODO : Animation
  };
      
  ElementLiving::~ElementLiving()
  {
    if (f_lifeAnimation != nullptr) delete f_lifeAnimation;
    if (f_deadAnimation != nullptr) delete f_deadAnimation;
  }
      
  ///////////////////////////////////////////////////////////////////////
  /// \brief getLife
  /// \return Element f_life
  /////////////////////////////////////////////////////////////////////////    
  int ElementLiving::getLife () const {
    return f_life;
  };


  ///////////////////////////////////////////////////////////////////////
  /// \brief getDefense
  /// \return Element f_defense
  /////////////////////////////////////////////////////////////////////////   
  int ElementLiving::getDefense () const {
    return f_defense;
  };

  ///////////////////////////////////////////////////////////////////////
  /// \brief getAnimation return the current animation
  /// If life <= 0, it return f_deadAnimation, f_lifeAnimation otherwise
  /// Please note that the function return a nullptr if no animation was specified
  /// \return Element current animation (f_deadAnimation if life <= 0, f_lifeAnimation otherwise) 
  /////////////////////////////////////////////////////////////////////////   
  Animation* ElementLiving::getAnimation () const {

   return f_life <= 0 ?  f_lifeAnimation :  f_deadAnimation;

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

    //do we do damage ?
    if (f_defense - power > 0) return;

    f_life =  f_life + f_defense - power;
    return ;
  };



