/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 6:57 PM
 *
 * Part of tank */


#include "Engine.h"
#include "Ruler.h"
#include "CommandSet.h"
#include "../state/State.h"
#include "LoadCommand.h"

namespace engine{

    Engine::Engine(state::State* s) : ruler(this) {

        commands = new CommandSet();
        state = s;
        charTurn = 0;

    };
    
    void Engine::addCommand(Command* cmd) {
        if(cmd->getCategory()==100)
        {
            LoadCommand* lcmd = dynamic_cast<LoadCommand*>(cmd);
            state->load(lcmd->getFileName());
            return;
        }
        if(cmd->getCharacter()==charTurn)
            commands->add(cmd);
    };
       
    
    void Engine::setcharTurn(int c) {
        charTurn = c;
    }
    
    int Engine::getcharTurn() const {
        return charTurn;
    };

    Ruler* Engine::getRuler() {
        return &ruler;
    }
    
    void Engine::setRuler() {
        ruler.setCommandSet(commands);
        ruler.setState(state);
    }
    
    void Engine::setMode(EngineMode m) {
        if((mode==m)&&(m==pause))
            mode = play;
        else 
            mode = m;
    }
    
    void Engine::endTurn() {
        ruler.apply();
        commands->clear();
    }

}

/*press ctrl+space for create function define in .h*/