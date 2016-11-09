// Generated by dia2code
#ifndef ENGINE__DIRECTIONCOMMAND__H
#define ENGINE__DIRECTIONCOMMAND__H

#include "state/Orientation.h"

namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class DirectionCommand - Command Direction
  class DirectionCommand : public engine::Command {
    // Attributes
  protected:
    int character;
    state::Orientation direction;
    // Operations
  public:
    DirectionCommand (int c, state::Orientation d);
    int getCharacter () const;
    state::Orientation getDirection () const;
    int getCategory () const;
  };

};

#endif
