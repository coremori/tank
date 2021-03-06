// Generated by dia2code
#ifndef ENGINE__ENDTURNCOMMAND__H
#define ENGINE__ENDTURNCOMMAND__H


namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class EndTurnCommand - end the turn
  class EndTurnCommand : public engine::Command {
    // Attributes
  protected:
    int character;
    // Operations
  public:
    EndTurnCommand (int c);
    int getCharacter () const;
    int getCategory () const;
  };

};

#endif
