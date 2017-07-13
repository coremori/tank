/* 
 * File:   SurfaceSFML.hpp
 * Author: corentin
 *
 * Created on October 12, 2016, 8:30 AM
 */

#ifndef SURFACESFML_HPP
#define SURFACESFML_HPP


#include "state/ElementGraphic.h"
#include "state/ElementBase"
#include <string>

#include <vector>
#include "render/Surface.h"
#include "render/Tile.h"
#include "Surface.h"
#include <SFML/Graphics.hpp>

  /// class SurfaceSFML - 
  class SurfaceSFML : public render::Surface, public sf::Drawable, public sf::Transformable{
    // Attributes
  protected:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    
    // Operations
  public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void loadTexture (const char* image_file);
    virtual void clear ();
    virtual void setSprite (const std::vector<render::Tile> tiles);
    virtual void setSpriteNum (int idx, render::Tile tile);
    void setSpriteButton (unsigned int x1, unsigned int y1, unsigned int xTex, unsigned int width);


 ///////////////////////////////////////////////////////////////////////
   /// \fn updateElementGraphic
   /// \brief change the texture 
   /// \param elementDisplay : ElementGraphic we want to display
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
    void updateElementGraphic(ElementGraphic* elementDisplay, int newPositionX = -1, int newPositionY = -1);

  ///////////////////////////////////////////////////////////////////////
  /// \fn newSprite
  /// \brief create a new sprite
  /// \param elementToDisplay : ElementBase* we want to display
  /// \param x : Element position x, if -1 then elementToDisplay is assumed being a ElementMobile and x is get from it
  /// \param y : Element position y, if -1 then elementToDisplay is assumed being a ElementMobile and y is get from it
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
    void newSprite( ElementBase* elementToDisplay, int x, int y);

  ///////////////////////////////////////////////////////////////////////
  /// \fn newSpriteList
  /// \brief create a new sprite for each element in listOfElementToDisplay
  /// \param listOfElementToDisplay : elements we want to display
  /// \param sizeLine : number of element by line
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
void newSpriteList (std::vector<ElementBase*> listOfElementToDisplay, int sizeLine);


  ///////////////////////////////////////////////////////////////////////
  /// \fn textToSprite
  /// \brief Display a text on a sprite
  /// \param text : text we want to display
  /// \param textNumber : numero of the previous text (for update this sprite)
  /// \param positionX : text position x (-1 for no change)
  /// \param positionY : text position y (-1 for no change)
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void textToSprite (std::string text, int spriteNumber, int positionX = -1, int positionY =-1);

  ///////////////////////////////////////////////////////////////////////
  /// \fn loadFont
  /// \brief load the font who will be used to display the text
  /// \param font_file : the font to use
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void loadFont( const char* font_file);

  private :
  sf::Font f_Font; //verifier les includes
  std::vector<sf::Text*> f_AllText;

 };




#endif /* SURFACESFML_HPP */

