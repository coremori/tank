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
#include <mutex>
#include <chrono>
#include <thread>


namespace engine{

    Engine::Engine(state::State* s) : ruler(this) {

        currentcommands = new CommandSet();
        waitingcommands = new CommandSet();
        state = s;
        charTurn = 0;
        ruler.setState(state);

    };
    
    void Engine::addCommand(Command* cmd) {//lock mutex commands and add them to "waitingcommands"
        commands_mutex.lock();
        if(cmd->getCategory()==100)//commande load
        {
            LoadCommand* lcmd = dynamic_cast<LoadCommand*>(cmd);
            state->load(lcmd->getFileName());
            return;
        }//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< mettre ici le cas de commande pour le mode (on peut lui demander "reccord debut/fin everytime, et alors pas de mouvement)
        if(cmd->getCharacter()==charTurn)//si c'est au tour du personnage
            waitingcommands->add(cmd);
        commands_mutex.unlock();
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
    
    
    
    void Engine::setMode(EngineMode m) {
        if((mode==m)&&(m==pause))
            mode = play;
        else 
            mode = m;
    }
        
    void Engine::swapCommands() {//lock commands and swap them
        commands_mutex.lock();
        CommandSet* s = currentcommands;
        currentcommands = waitingcommands;
        s->clear();
        waitingcommands = s;
        commands_mutex.unlock();
    }

    void Engine::endTurn() {//swap waitingcommands and currentcommands, send the waitingcommand to the ruler and apply them
        swapCommands();
        ruler.setCommandSet(currentcommands);
        ruler.apply();
    }
    void Engine::update() {//tant ue la fenetre n'est pas fermée
        while(mode!=close)
        {
            //std::this_thread::sleep_for(2s);
        }
    }

}
