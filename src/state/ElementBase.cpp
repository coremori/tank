/**
 * \file ElementBase.cpp
 * \brief Basique element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Basique element who does not have life and can't move
 *
 */

#include "ElementBase.h"

namespace state {
  ElementBase::ElementBase (int id, bool canBeGetAcross , std::string name ):
    f_X(0),
    f_Y(0),
    f_Id(id),
    f_CanBeGetAcross(canBeGetAcross),
    f_Name(name),
    f_ElementGraphic(nullptr)
  { 
    //TODO : Graphique
  }
      
  ElementBase::~ElementBase()
  {
    if (f_ElementGraphic != nullptr) delete f_ElementGraphic;
  }

  int ElementBase::getX () const
  {
    return f_X;
  }

  int ElementBase::getY () const
  {
    return f_Y;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn int ElementBase::getId () const
  /// \brief getId
  /// \return Element id
  /////////////////////////////////////////////////////////////////////////    
  int ElementBase::getId () const 
  {
    return f_Id;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn bool ElementBase::getCanBeGetAcross () const
  /// \brief getCanBeGetAcross
  /// \return f_canBeGetAcross
  /////////////////////////////////////////////////////////////////////////    
  bool ElementBase::getCanBeGetAcross () const 
  {
    return f_CanBeGetAcross;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn  std::string ElementBase::getName () const
  /// \brief getName
  /// \return Element name
  /////////////////////////////////////////////////////////////////////////    
  std::string ElementBase::getName () const 
  {
    return f_Name;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn ElementGraphic* ElementBase::getGraphic () const
  /// \brief getGraphic
  /// \return Element graphic
  /////////////////////////////////////////////////////////////////////////    
  ElementGraphic* ElementBase::getGraphic () const 
  {
    return f_ElementGraphic;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn int ElementBase::getLife () const
  /// \brief getLife
  /// \return Element life if it exist, -1 otherwise
  /////////////////////////////////////////////////////////////////////////    
  int ElementBase::getLife () const 
  {
    // Pas de vie, donc -1.
    return -1;
  }

  void ElementBase::setY (int y)
  {
    f_Y = y;
  }

  void ElementBase::setX (int x)
  {
    f_X = x;
  }
  ///////////////////////////////////////////////////////////////////////
  /// \fn void ElementBase::takeDamage(const int power, const bool ignoreDefense)
  /// \brief takeDamage
  /// \param power damage done to the life
  /// \param ignoreDefense if true, the defense is ignored
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void ElementBase::takeDamage(const int power, const bool ignoreDefense)
  {    
    // Pas de pv donc rien à faire
    return;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn void ElementBase::move(const int dx, const int dy)
  /// \brief move
  /// \param dx mouvement x
  /// \param dy mouvement y
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void ElementBase::move(const int dx, const int dy)
  {
    // On ne peut pas bouger donc rien à faire
    return;
  }

}
