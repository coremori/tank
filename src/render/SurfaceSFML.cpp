/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <assert.h> 

#include "Tile.h"
#include <SFML/Graphics.hpp>
#include "SurfaceSFML.h"

namespace render {

    
    void SurfaceSFML::loadTexture (const char* image_file)
    {   //basicque : "res/Textures/textures.png"
        //Vérifier l'ordre h/w
        if (!texture.loadFromFile(image_file)) 
        {
            //error
        }
        
    };
    
    void SurfaceSFML::clear (){
        sprites.clear();
    };
    
    void SurfaceSFML::setSpriteCount (int n){
        nSprite = n;
    };
    
    void SurfaceSFML::setSprite (const std::vector<Tile*> tile){//NOT DONE!!
        for(unsigned int i=0; i<tile.size(); i++)
        {
            sprites[i] = new sf::Sprite;
            sprites[i]->setTexture(texture);
            sprites[i]->setTextureRect(sf::IntRect(0, 0, tile[i]->getWidth(), tile[i]->getHeight()));
            sprites[i]->setPosition(sf::Vector2f(tile[i]->getX(),tile[i]->getY()));
        }
        
        
    };
  
    std::vector<sf::Sprite*> SurfaceSFML::getSprites () const{
        return sprites;
    };

};