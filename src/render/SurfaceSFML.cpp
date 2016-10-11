/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <assert.h> 
#include <SFML/Graphics.hpp>
#include "SurfaceSFML.h"

namespace render {

    
    void SurfaceSFML::loadTexture (const char* image_file){
        //basicque : "res/Textures/textures.png"
        
        if (!texture.loadFromFile(image_file)) 
        {
            //error
        }
        
    };
    
    void SurfaceSFML::clear (){
        tiles.clear();
    };
    
    void SurfaceSFML::setSpriteCount (int n){
        nSprite = n;
    };
    
    void SurfaceSFML::setSpriteTexture (int i, const Tile* tile){
        assert(i<tiles.size());
        tiles[i] = tile;
    };
  

};