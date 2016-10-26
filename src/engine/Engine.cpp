/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 6:57 PM
 *
 * Part of tank */


#include "Engine.h"
#include "Ruler.h"
#include "CommandSet.h"
#include "../state/State.h"

namespace engine{

    Engine::Engine(state::State* s) {

        commands = new CommandSet();
        state = s;

    };
    
    void Engine::addCommand(Command* cmd) {
        commands->add(cmd);
    };
    
    void displayTest() const{
        
    }
    
    
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

}

/*press ctrl+space for create function define in .h*/