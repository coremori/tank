/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SurfaceSFML.hpp
 * Author: corentin
 *
 * Created on October 12, 2016, 8:30 AM
 */

#ifndef SURFACESFML_HPP
#define SURFACESFML_HPP

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

  };




#endif /* SURFACESFML_HPP */

