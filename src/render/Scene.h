// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H

#include <vector>

namespace render {
  class Layer;
  class Surface;
};
namespace client {
  class CacheStateObserver;
}

#include "client/CacheStateObserver.h"
#include "Layer.h"

namespace render {

  /// class Scene - Store the layers and the height/width of the game - reacts only to "Level_Changed"  StateEvent
  class Scene : public client::CacheStateObserver {
    // Associations
    // Attributes
  protected:
    std::vector<Layer*> layers;
    int height;
    int width;
    // Operations
  public:
    Scene ();
    ~Scene ();
    int getLayerCount () const;
    void setSurface (int idx, Surface* surface);
    void setLayer (int idx, Layer* layer);
    int getHeight () const;
    int getWidth () const;
    void applyStateChanged ();
    bool update ();
    void updateAll ();
  };

};

#endif
