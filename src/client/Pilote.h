// Generated by dia2code
#ifndef CLIENT__PILOTE__H
#define CLIENT__PILOTE__H

#include "state/State.h"
#include "engine/Engine.h"
#include "engine/CommandSet.h"
#include <SFML/Network.hpp>
#include <mutex>

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
    engine::CommandSet* command;
    int character;
    sf::Http http;
    mutable std::mutex commands_mutex;
    engine::CommandSet* command_waiting;
    int already;
    // Operations
  public:
    Pilote ();
    void runEngine ();
    void runRender ();
    void launch ();
    void waitGetCommand (int characterAsked, int characterSender);
    bool getCommand (int characterAsked, int characterSender);
    bool postCommand (int characterSender);
    void addCommand (engine::Command* command);
  };

};

#endif
