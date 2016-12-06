#include <vector>
#include <assert.h> 

#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <bits/stl_vector.h>
#include "SurfaceSFML.hpp"
#include <iostream>


    
    void SurfaceSFML::loadTexture (const char* image_file)
    {   //basic: "res/Textures/textures.png"
        //Vérifier l'ordre h/w
        
        if (!m_tileset.loadFromFile(image_file)) 
        {
            //error
        }
        
    };
    
       
    
    
    
    void SurfaceSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }
    
    
    
    
    
    
    void SurfaceSFML::clear (){
        m_vertices.clear();
    };
    
    
    
    
    
    
    
    
    void SurfaceSFML::setSprite (const std::vector<render::Tile> tiles){//NOT DONE!!
        // on charge la texture du tileset
        
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.clear();
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(tiles.size()*4);
        
        
        // on remplit le tableau de vertex, avec un quad par tuile
            for (unsigned int j = 0; j < tiles.size(); ++j)
            {
                // on récupère le numéro de tuile courant

                // on en déduit sa position dans la texture du tileset
                int tu = tiles[j].getXTex();//position dans la texture
                int tv = tiles[j].getYTex();
                
                unsigned int w = tiles[j].getWidth();//width d'un affichage
                unsigned int h = tiles[j].getHeight();
                
                unsigned int x = tiles[j].getX();//position dans l'image
                unsigned int y = tiles[j].getY();

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[j * 4];
                
                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(x,y);
                quad[1].position = sf::Vector2f(x+w, y);
                quad[2].position = sf::Vector2f(x+w, y+h);
                quad[3].position = sf::Vector2f(x, y+h);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu, tv);
                quad[1].texCoords = sf::Vector2f(tu + w, tv);
                quad[2].texCoords = sf::Vector2f(tu + w, tv +h);
                quad[3].texCoords = sf::Vector2f(tu, tv +h);
            }
        
    
    };
    
    
    
    
    
    
    void SurfaceSFML::setSpriteNum(int idx, render::Tile tile) {
        
        if(idx<0)
            return;
        unsigned int maxi = idx;
        if((maxi==(m_vertices.getVertexCount()/4)))//si idx > size ou idx<0 (comparaison signed/unsigned avantageuse ici)
        {
            m_vertices.resize(m_vertices.getVertexCount()+4);
        }
        else if(maxi>(m_vertices.getVertexCount()/4))
            return;
                
        int tu = tile.getXTex();//position dans la texture
                int tv = tile.getYTex();
                
                unsigned int w = tile.getWidth();//width d'un affichage
                unsigned int h = tile.getHeight();
                
                unsigned int x = tile.getX();//position dans l'image
                unsigned int y = tile.getY();

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[idx * 4];
                
                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(x,y);
                quad[1].position = sf::Vector2f(x+w, y);
                quad[2].position = sf::Vector2f(x+w, y+h);
                quad[3].position = sf::Vector2f(x, y+h);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu, tv);
                quad[1].texCoords = sf::Vector2f(tu + w, tv);
                quad[2].texCoords = sf::Vector2f(tu + w, tv +h);
                quad[3].texCoords = sf::Vector2f(tu, tv +h);        
    };

    
    
    
    
    
    void SurfaceSFML::setSpriteButton (unsigned int x1, unsigned int y1, unsigned int xTex, unsigned int width){
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        unsigned int size = m_vertices.getVertexCount();
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(size+4);
        
        int tu = xTex;//position dans la texture

        unsigned int w = width;//width d'un affichage
        unsigned int h = 72;

        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        sf::Vertex* quad = &m_vertices[size];

        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(x1,y1);
        quad[1].position = sf::Vector2f(x1+w, y1);
        quad[2].position = sf::Vector2f(x1+w, y1+h);
        quad[3].position = sf::Vector2f(x1, y1+h);

        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu, 0);
        quad[1].texCoords = sf::Vector2f(tu + w,0);
        quad[2].texCoords = sf::Vector2f(tu + w, h);
        quad[3].texCoords = sf::Vector2f(tu, h);
            
    }
  
    
