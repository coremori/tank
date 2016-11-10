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
#include "CommandCategory.h"
#include "EndTurnCommand.h"
#include "ModeCommand.h"

#include "state/Tank.h"
#include <mutex>
#include <chrono>
#include <ctime>
#include <thread>

#include <iostream>



namespace engine{

    Engine::Engine(state::State* s) : ruler(this) {

        currentcommands = new CommandSet();
        waitingcommands = new CommandSet();
        state = s;
        charTurn = 0;
        ruler.setState(state);
        mode = play;

    };
    
    void Engine::addCommand(Command* cmd) {//lock mutex commands and add them to "waitingcommands"
        commands_mutex.lock();
        /*if(cmd->getCategory()==100)//commande load
        {
            LoadCommand* lcmd = dynamic_cast<LoadCommand*>(cmd);
            state->load(lcmd->getFileName());
            return;
        }*/
        
        if(cmd->getCharacter()==charTurn || cmd->getCharacter()==-1)//si c'est au tour du personnage
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
       
    EngineMode Engine::getMode() const {
        return mode;
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
        /*if(charTurn == 1 )// Other player round
            charTurn = 0;
        else
            charTurn = 1*/
        ruler.setCommandSet(currentcommands);
        ruler.apply();
        for(int i = 0; i<state->getMobiles().size(); i++)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(i));
            if(tank->getPv() == 0){
                if(i==1)
                {
                    std::cout << "Victoire" << std::endl;
                    mode = victoire;
                }
                else
                {
                    std::cout << "lost" << std::endl;
                    mode = defaite;
                }
                    
            }
        }
            
    }
        
    std::mutex& Engine::getUpdateMutex() const {
        return update_mutex;
    }

    
    void Engine::update() {
        /*vérifie les commandes de la list : passage au tour suivant ? 
         *Changement de mode ? les mutex sont importants pour une lecture prolongé et l'actualisation du state, 
         * pas nécéssaire pour vérifier leurs existence (puisque le render ne peut pas les supprimer, juste les remplacer)
         */
        
        if(waitingcommands->get(MAIN_CATEGORY))//Load commande
        {
            update_mutex.lock();
            swapCommands();
            LoadCommand* load = dynamic_cast<LoadCommand*>(currentcommands->get(MAIN_CATEGORY));
            state->load(load->getFileName());
            update_mutex.unlock();
        }
        else if(waitingcommands->get(MODE_CATEGORY))
        {
            commands_mutex.lock();
            ModeCommand* modeCmd = dynamic_cast<ModeCommand*>(waitingcommands->get(MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            setMode(modeCmd->getMode());
            commands_mutex.unlock();
        }
        else if(waitingcommands->get(END_CATEGORY))
        {
            update_mutex.lock();
            endTurn();
            update_mutex.unlock();
        }
    }

}
