// Generated by dia2code
#ifndef RENDER__MISSILE__H
#define RENDER__MISSILE__H


namespace render {
  class Tile;
  class Animation;
}

#include "Animation.h"

namespace render {

  /// class Missile - 
  class Missile : public render::Animation {
    // Attributes
  protected:
    int xEnd;
    int yCeiling;
    int yEnd;
    // Operations
  public:
    Missile (int xEnd, int yEnd, int yCeiling, bool rightDirection);
    bool setNextTile (Tile* tile);
    int getXEnd () const;
    int getYEnd () const;
  };

};

#endif
