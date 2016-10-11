// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H

#include <vector>

namespace render {
  class Layer;
  class Surface;
}

#include "Layer.h"

namespace render {

  /// class Scene - 
  class Scene {
    // Associations
    // Attributes
  public:
    std::vector<Layer*> layers;
  protected:
    int width;
    int height;
    // Operations
  public:
    Scene ();
    ~Scene ();
    int getWidth () const;
    int getHeight () const;
    int getLayerCount () const;
    void setLayer (int idx, Surface* surface);
    void setLevel ();
  };

};

#endif
