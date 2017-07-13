/**
 * \file ElementGraphic.h
 * \brief Graphic of on element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Give methode and variable to save the static element apparence
 *
 */

#ifndef ELEMENTGRAPHIC__H
#define ELEMENTGRAPHIC__H


#include <vector>

  class ElementGraphic;






  /// class Element - 
  class ElementGraphic   {
    // Associations
    // Attributes
  protected:

    // Operations
  public:
  ElementGraphic (int textureX, int textureY, int orientation_serie, int width , int height, bool dontDisplay = false, int relativePositionX = 0, int relativePositionY = 0, ElementGraphic* master = nullptr);
  ~ElementGraphic();
      
  ///////////////////////////////////////////////////////////////////////
  /// \brief getTextureX
  /// \return int Element f_textureX
  /////////////////////////////////////////////////////////////////////////    
  int getTextureX () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getTextureY
  /// \return int Element f_textureY
  /////////////////////////////////////////////////////////////////////////    
  int getTextureY () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getOrientation_serie
  /// \return int Element f_orientation_serie
  /////////////////////////////////////////////////////////////////////////    
  int getOrientation_serie () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getWidth
  /// \return int Element f_width
  /////////////////////////////////////////////////////////////////////////    
  int getWidth () const ;


  ///////////////////////////////////////////////////////////////////////
  /// \brief getHeight
  /// \return int Element f_height
  /////////////////////////////////////////////////////////////////////////    
  int getHeight () const ;


  ///////////////////////////////////////////////////////////////////////
  /// \brief getRelativePositionX
  /// \return int Element f_relativePositionX
  /////////////////////////////////////////////////////////////////////////    
  int getRelativePositionX () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getRelativePositionY
  /// \return int Element f_relativePositionY
  /////////////////////////////////////////////////////////////////////////    
  int getRelativePositionY () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getDontDisplay
  /// \return bool Element f_dontDisplay
  /////////////////////////////////////////////////////////////////////////   
  bool getDontDisplay () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getNumberSubGraphic
  /// \return int number of subdisplay
  /////////////////////////////////////////////////////////////////////////   
  int getNumberSubGraphic () const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief getSubGraphic
  /// \param index number wanted
  /// \return SubGraphic number index
  /////////////////////////////////////////////////////////////////////////   
  ElementGraphic* getSubGraphic (const int index) const ;

  ///////////////////////////////////////////////////////////////////////
  /// \brief setNewSubGraphic
  /// \param SubGraphic ElementGraphic to insert
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
void setNewSubGraphic( ElementGraphic* SubGraphic) ;

//Variable :
public :
int p_spriteNumber;

  private :
    int f_textureX ;
    int f_textureY ;
    int f_orientation_serie ;
    int f_width ;
    int f_height ;
    bool f_dontDisplay ;
    int f_relativePositionX ;
    int f_relativePositionY ;
    std::vector<ElementGraphic*> f_subGraphic;

};


#endif
