/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tile.h"

namespace render {
      
    Tile::Tile (int x, int y, int w, int h){
        this->x = x;
        this->y = y;
        this->height = h;
        this->width = w;
    };
    
    int const Tile::getX (){
        return x;
    };
    
    int const Tile::getY (){
        return y;
    };
    
    int const Tile::getWidth (){
        return width;
    };
    
    int const Tile::getHeight (){
        return height;
    };
    
    void Tile::setX (int x){
        this->x = x;
    };
    
    void Tile::setY (int y){
        this->y = y;
    };
    
    void Tile::setWidth (int w){
        width = w;
    };
    
    void Tile::setHeight (int h){
        height = h;
    };
  

};