// Generated by dia2code
#ifndef CLIENT__PILOTE__H
#define CLIENT__PILOTE__H

#include "state/State.h"
#include "engine/Engine.h"

namespace client {
  class PiloteRendu;
}

#include "PiloteRendu.h"

namespace client {

  /// class Pilote - 
  class Pilote {
    // Associations
    // Attributes
  protected:
    state::State state;
    engine::Engine engine;
    PiloteRendu* rendu;
    // Operations
  public:
    Pilote ();
    void runEngine ();
    void runRender ();
    void launch ();
  };

};

#endif
