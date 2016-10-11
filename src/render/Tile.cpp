/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  protected:
    int x;
    int y;
    int height;
    int width;
    // Operations
  public:
      
      
    Tile::Tile (int x = 0, int y = 0, int w = 8, int h = 8){
        this->x = x;
        this->y = y;
        this->height = h;
        this->width = w;
    };
    
    int const Tile::getX ();
    int const Tile::getY ();
    int const Tile::getWidth ();
    int const Tile::getHeight ();
    void Tile::setX (int x);
    void Tile::setY (int y);
    void Tile::setWidth (int w);
    void Tile::setHeight (int h);
  };

};