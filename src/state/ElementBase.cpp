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





  ElementBase::ElementBase (int id, bool canBeGetAcross , ElementGraphic* graphic, std::string name):
    f_id(id),
    f_canBeGetAcross(canBeGetAcross),
    f_elementGraphic(graphic),
    f_name(name)
  { 
    //TODO : Graphique
  }
      
  ElementBase::~ElementBase()
  {
    if (f_elementGraphic != nullptr) delete f_elementGraphic;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn int ElementBase::getId () const
  /// \brief getId
  /// \return Element id
  /////////////////////////////////////////////////////////////////////////    
  int ElementBase::getId () const {
    return f_id;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn bool ElementBase::getCanBeGetAcross () const
  /// \brief getCanBeGetAcross
  /// \return f_canBeGetAcross
  /////////////////////////////////////////////////////////////////////////    
  bool ElementBase::getCanBeGetAcross () const {
    return f_canBeGetAcross;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn  std::string ElementBase::getName () const
  /// \brief getName
  /// \return Element name
  /////////////////////////////////////////////////////////////////////////    
  std::string ElementBase::getName () const {
    return f_name;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn ElementGraphic* ElementBase::getGraphic () const
  /// \brief getGraphic
  /// \return Element graphic
  /////////////////////////////////////////////////////////////////////////    
  ElementGraphic* ElementBase::getGraphic () {
    return f_elementGraphic;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn int ElementBase::getLife () const
  /// \brief getLife
  /// \return Element life if it exist, -1 otherwise
  /////////////////////////////////////////////////////////////////////////    
  int ElementBase::getLife () const {
    return -1;
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
    return ;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn void ElementBase::move(const int dx, const int dy)
  /// \brief move
  /// \param dx mouvement x
  /// \param dy mouvement y
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void ElementBase::move(const int dx, const int dy){
      return;
  }
    




