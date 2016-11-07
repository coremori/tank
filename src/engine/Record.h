#ifndef ENGINE__RECORD__H
#define ENGINE__RECORD__H

#include "../state.h"
#include <vector>

namespace engine {
  class ActionListTurn;
}

namespace engine {

  /// class Record - 
  class Record {
    // Attributes
  protected:
    static state::State& mainState;
    state::State* initState;
    state::State* lastState;
    std::vector<ActionListTurn*> actions;
    int idx;
    // Operations
  public:
    Record (state::State& s);
    ~Record ();
    void clear ();
    void startRecord ();
    void recordOne (ActionListTurn* actions);
    void stopRecord ();
    void startReplay ();
    bool replayOne ();
    void startRollback ();
    bool rollbackOne ();
  };

};

#endif
