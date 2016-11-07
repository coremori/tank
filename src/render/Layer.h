#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <vector>
#include "../state.h"

namespace render {
  class Surface;
  class Tile;
  class Animation;
};
namespace cache {
  class CacheStateObserver;
}

#include "Tile.h"
#include "cache/CacheStateObserver.h"
#include "Animation.h"
#include "Surface.h"

namespace render {

  /// class Layer - 
  class Layer : public cache::CacheStateObserver {
    // Associations
    // Attributes
  protected:
    Surface* surface;
    std::vector<Tile> tiles;
    std::vector<int> numTileToUpdate;
    Animation* animation;
    // Operations
  public:
    Layer ();
    ~Layer ();
    void clear ();
    void charToTiles (char c, int Ypos);
    void elementToTiles (const state::ElementList* list);
    Tile getTile (int i);
    void setTile (int idx, Tile tile);
    void setSurface (Surface* surface);
    void update ();
    void updateAll ();
  };

};

#endif
