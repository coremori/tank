/**
 * \file ElementGraphic.cpp
 * \brief Graphic of on element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Give methode and variable to save the static element apparence
 *
 */

#include "ElementGraphic.h"


  ElementGraphic::ElementGraphic (int textureX, int textureY, int orientation_serie, int width , int height, bool dontDisplay, int relativePositionX, int relativePositionY, ElementGraphic* master):
    p_spriteNumber(0),
    f_textureX(textureX),
    f_textureY(textureY),
    f_orientation_serie(orientation_serie),
    f_width(width),
    f_height(height),
    f_dontDisplay(dontDisplay),
    f_relativePositionX(relativePositionX),
    f_relativePositionY(relativePositionY)
  { 
    if (master != nullptr)    master->setNewSubGraphic(this);
  }
      
  ElementGraphic::~ElementGraphic()
  {
    for (unsigned i=0 ; i<f_subGraphic.size() ; i++)
    {
      delete(f_subGraphic[i]);
    }
  }
      
  ///////////////////////////////////////////////////////////////////////
  /// \brief getTextureX
  /// \return int Element f_textureX
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getTextureX () const {
    return f_textureX;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getTextureY
  /// \return int Element f_textureY
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getTextureY () const {
    return f_textureY;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getOrientation_serie
  /// \return int Element f_orientation_serie
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getOrientation_serie () const {
    return f_orientation_serie;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getWidth
  /// \return int Element f_width
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getWidth () const {
    return f_width;
  }


  ///////////////////////////////////////////////////////////////////////
  /// \brief getHeight
  /// \return int Element f_height
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getHeight () const {
    return f_height;
  }


  ///////////////////////////////////////////////////////////////////////
  /// \brief getRelativePositionX
  /// \return int Element f_relativePositionX
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getRelativePositionX () const {
    return f_relativePositionX;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getRelativePositionY
  /// \return int Element f_relativePositionY
  /////////////////////////////////////////////////////////////////////////    
  int ElementGraphic::getRelativePositionY () const {
    return f_relativePositionY;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getDontDisplay
  /// \return bool Element f_dontDisplay
  /////////////////////////////////////////////////////////////////////////   
  bool ElementGraphic::getDontDisplay () const {
    return f_dontDisplay;
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getNumberSubGraphic
  /// \return int number of subdisplay
  /////////////////////////////////////////////////////////////////////////   
  int ElementGraphic::getNumberSubGraphic () const {
    return f_subGraphic.size();
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief getSubGraphic
  /// \param index number wanted
  /// \return SubGraphic number index
  /////////////////////////////////////////////////////////////////////////   
  ElementGraphic* ElementGraphic::getSubGraphic (const int index) const {
    return f_subGraphic[index];
  }

  ///////////////////////////////////////////////////////////////////////
  /// \brief setNewSubGraphic
  /// \param SubGraphic ElementGraphic to insert
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
    void ElementGraphic::setNewSubGraphic( ElementGraphic* SubGraphic)
    {
      f_subGraphic.push_back(SubGraphic);
    }


