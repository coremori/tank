// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include "state/State.h"
#include <mutex>
#include <vector>
#include "ai/AI.h"

namespace engine {
  class CommandSet;
  class Command;
  class Ruler;
  class Record;
}

#include "EngineMode.h"
#include "Record.h"
#include "Ruler.h"
#include "CommandSet.h"

namespace engine {

  /// class Engine - Pilote of the game
  class Engine {
    // Associations
    engine::Record reccord;
    engine::EngineMode mode;
    engine::Ruler ruler;
    // Attributes
  protected:
    CommandSet* currentcommands;
    CommandSet* waitingcommands;
    int charTurn;
    state::State* state;
    mutable std::mutex commands_mutex;
    mutable std::mutex update_mutex;
    std::vector<ai::AI*> ai;
    bool AnimRunning;
    // Operations
  public:
    Engine (state::State* s);
    ~Engine ();
    void addCommand (Command* cmd);
    void setMode (EngineMode m);
    EngineMode getMode () const;
    void setcharTurn (int c);
    Ruler* getRuler ();
    void endTurn ();
    void swapCommands ();
    void update ();
    std::mutex& getUpdateMutex () const;
    void setAnimRunning (bool b);
  };

};

#endif
