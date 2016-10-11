/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <assert.h> 
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "SurfaceSFML.h"

namespace render {

    
    void SurfaceSFML::loadTexture (const char* image_file, int x, int y, int height, int width)
    {   //basicque : "res/Textures/textures.png"
        //Vérifier l'ordre h/w
        if (!texture.loadFromFile(image_file, sf::IntRect(x,y,width, height))) 
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
    
    void SurfaceSFML::setSpriteTexture (int i, const Tile* tile){//NOT DONE!!
        assert(i<tiles.size());
        sprites[i] = new sf::Sprite;
        sprites[i]->setTexture(texture);
        sprites[i]->setTextureRect(sf::IntRect(0, 0, tile->getWidth(), tile->getHeight()));
        sprites[i]->setPosition(sf::Vector2f(tile->getX(),tile->getY()));
        
    };
  
    void SurfaceSFML::affiche () const{
        
    sf::RenderWindow window(sf::VideoMode(200, 200), L"Peut-tu seulement dépasser la médiocrité ?");// fenetre d'affichage

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.draw(*sprites[0]);
        window.draw(*sprites[1]);
        window.draw(*sprites[2]);//on les traces dans cette ordre là (le dernier tracer est au dessus (notamment pour le char))
        
        window.display();
    }
    };

};