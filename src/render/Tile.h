// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H


namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  protected:
    int x;
    int y;
    int height;
    int width;
    int xTex;
    int yTex;
    // Operations
  public:
    Tile (int x = 0, int y = 0, int w = 8, int h = 8);
    int getX () const;
    int getY () const;
    int getWidth () const;
    int getHeight () const;
    void setX (int x);
    void setY (int y);
    void setWidth (int w);
    void setHeight (int h);
    int getXTex () const;
    int getYTex () const;
    void setXTex (int xtex);
    void setYTex (int ytex);
  };

};

#endif
