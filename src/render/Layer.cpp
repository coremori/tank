/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tile.h"
#include "Surface.h"
#include "Layer.h"
namespace render {

  
    Layer::Layer (){};
    Layer::~Layer (){
        tiles.clear();
    };
    
    void Layer::setSurface (Surface* surface){
        this->surface = surface;
    };
    
    void Layer::setTile (Tile* tile){
        tiles.push_back(tile);
    };
    
    Tile Layer::getTile (int i){
        return *tiles[i];
    };
  
    void Layer::update (){
        surface->setSprite(tiles);
    };

};