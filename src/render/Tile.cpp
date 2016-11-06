/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tile.h"
#include "CharLayer.h"

namespace render {
      
    Tile::Tile (int x, int y, int w, int h){
        this->x = x;
        this->y = y;
        this->height = h;
        this->width = w;
    };
    
    Tile::~Tile(){
        
    }
    
    int Tile::getX () const{
        return x;
    };
    
    int Tile::getY () const{
        return y;
    };
    
    int Tile::getWidth () const{
        return width;
    };
    
    int Tile::getHeight () const{
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
  
    int Tile::getXTex () const{
        return xTex;
    };
    
    int Tile::getYTex () const{
        return yTex;
    };
    void Tile::setXTex (int xtex){
        xTex = xtex;
    };
    void Tile::setYTex (int ytex){
        yTex = ytex;
    };
};