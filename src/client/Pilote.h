// Generated by dia2code
#ifndef CLIENT__PILOTE__H
#define CLIENT__PILOTE__H

#include "state/State.h"
#include "engine/Engine.h"
#include <vector>
#include "engine/CommandSet.h"

namespace client {
  class PiloteRendu;
}

#include "PiloteRendu.h"

namespace client {

  /// class Pilote - Run the engine and rendu thread
  class Pilote {
    // Associations
    // Attributes
  protected:
    state::State state;
    engine::Engine engine;
    PiloteRendu* rendu;
    std::vector<engine::CommandSet*> command;
    // Operations
  public:
    Pilote ();
    void runEngine ();
    void runRender ();
    void launch ();
  };

};

#endif
