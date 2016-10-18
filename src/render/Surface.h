// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H

#include <vector>

namespace render {
  class Tile;
}

namespace render {

  /// class Surface - loadTexture : image + position de la texture dans image (donnée pat Tile) ; setSpriteTexture : on donne les tiles de la texture stocké à afficher
  class Surface {
    // Operations
  public:
    Surface ();
    virtual void loadTexture (const char* image_file) = 0;
    virtual void clear () = 0;
    virtual void setSpriteCount (int n) = 0;
    virtual void setSprite (const std::vector<Tile*> tile) = 0;
  };

};

#endif
