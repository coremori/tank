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
    std::vector<sf::Sprite*> sprites;
    
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    
    int nSprite;
    // Operations
  public:
    void load(const std::vector<render::Tile*> tiles);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    virtual void loadTexture (const char* image_file);
    virtual void clear ();
    virtual void setSpriteCount (int n);
    virtual void setSprite (const std::vector<render::Tile*> tile);
    std::vector<sf::Sprite*> getSprites () const;
  };




#endif /* SURFACESFML_HPP */

