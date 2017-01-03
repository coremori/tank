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
#include "ai/DumbAI.h"
#include "ai/HeuristicAI.h"
#include <mutex>
#include <chrono>
#include <ctime>
#include <thread>

#include <iostream>






namespace engine{

    
    
    
    Engine::Engine(state::State* s) : reccord(s), ruler(){

        currentcommands = new CommandSet();
        waitingcommands = new CommandSet();
        state = s;
        charTurn = 0;
        ruler.setState(state);
        ActionListTurn* first = new ActionListTurn(s);
        ruler.setActions(first);
        reccord.recordOne(first);
        
        mode = play;
        
        AnimRunning = false;
        lastEndTurnTime = 0;

    };
  
    
    
    
    
    
    Engine::~Engine() {
        reccord.~Record();
        
    }

    
    
    
    
    
    
    void Engine::addCommand(Command* cmd) {//lock mutex commands and add them to "waitingcommands"
        commands_mutex.lock();
        if(cmd->getCharacter()==charTurn || cmd->getCharacter()==-1)//si c'est au tour du personnage ou c'est une commande prioritaire indépendante du joueur
            waitingcommands->add(cmd);
        commands_mutex.unlock();
    };
       
    
    
    
    
    
    
    
    
    void Engine::setMode(EngineMode m) {
        /* The engine mode will be the parameter
         * If it is already the mode, then the next mode will be "play"
         */
        if(mode==m)
            mode = play;
        else 
            mode = m;
        if(mode == replay){
            update_mutex.lock();
            reccord.startReplay();
            update_mutex.unlock();
        }
                
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

    
    
    
    
    
    
    
    
    
    void Engine::endTurn() {
        /* swap waitingcommands and currentcommands
         * send the waitingcommand to the ruler and apply them
         * check if one player doesn't have any pv and the game is finish
         */
        swapCommands();
        charTurn = charTurn ? 0:1;
        ruler.setCommandSet(currentcommands);
        ruler.implementeRules();
        for(int i = 0; i<state->getMobiles().size(); i++)
        {
            state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(i));
            if(tank->getPv() == 0){
                mode = Finish;
                std::cout << "Victory character " << (i?0:1) << std::endl;
            }
        }
            
    }
        
    
    
    
    
    
    
    
    std::mutex& Engine::getUpdateMutex() const {
        return update_mutex;
    }
    
    
    
    
    
    
    
    
    void Engine::setAnimRunning(bool b) {
        update_mutex.lock();
        AnimRunning = b;
        update_mutex.unlock();
    }

    
    
    
    
    
    
    
    
    
    
    
    void Engine::update(int64_t timeNow, int64_t timeinterval) {
        /*vérifie les commandes de la list : passage au tour suivant ? 
         *Changement de mode ? les mutex sont importants pour une lecture prolongée et l'actualisation du state, 
         * pas nécessaires pour vérifier leur existence (puisque le render ne peut pas les supprimer, juste les remplacer)
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
            if(!AnimRunning){
            commands_mutex.lock();
            ModeCommand* modeCmd = dynamic_cast<ModeCommand*>(waitingcommands->get(MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            setMode(modeCmd->getMode());
            waitingcommands->clear();
            commands_mutex.unlock();
            }
        }
        
        if(mode == AI || mode == play){
            if(waitingcommands->get(END_CATEGORY) && !AnimRunning)//si pas d'anim en cours et commande fin de tour lancé
            {
                if((timeNow-lastEndTurnTime)>=timeinterval){
                    update_mutex.lock();
                    endTurn();
                    update_mutex.unlock();
                    ActionListTurn* turn = new ActionListTurn(state);
                    ruler.setActions(turn);
                    reccord.recordOne(turn);
                    lastEndTurnTime = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
                }
            }
        }
        else if(mode == replay){
            if((timeNow-lastEndTurnTime)>timeinterval){//timeinterval ms between each turn
                update_mutex.lock();
                if(!AnimRunning)
                    if(!reccord.replayOne()){
                        mode = play;
                        endTurn();
                    }
                update_mutex.unlock();
                lastEndTurnTime = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());                        
            }
        }
    }

    
    
    
    
    
    
    
    int Engine::getCharTurn() const{
        return charTurn;
    }

    
    
    
        
    
    void Engine::takeCommands(CommandSet* commandset) {/* prend un commandset et transfert les commandes vers celui de l'engine*/
        if(commandset->get(MAIN_CATEGORY))
        {
            addCommand(commandset->get(MAIN_CATEGORY));
        }
        if(commandset->get(END_CATEGORY))
        {
            addCommand(commandset->get(END_CATEGORY));
        }
        if(commandset->get(MODE_CATEGORY))
        {
            addCommand(commandset->get(MODE_CATEGORY));
        }
        if(commandset->get(VIEW_CATEGORY))
        {
            addCommand(commandset->get(VIEW_CATEGORY));
        }
        if(commandset->get(MOVE_CATEGORY))
        {
            addCommand(commandset->get(MOVE_CATEGORY));
        }
        if(commandset->get(SHOT_CATEGORY))
        {
            addCommand(commandset->get(SHOT_CATEGORY));
        }
       // commandset->clear();
    }
    
    
    
}
