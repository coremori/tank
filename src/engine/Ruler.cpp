/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 2:16 PM
 *
 * Part of tank */


#include "Ruler.h"
#include "CommandSet.h"
#include "MoveCommand.h"
#include "ModeCommand.h"
#include "CommandCategory.h"
#include "ActionMove.h"
#include <cstddef>
#include <iostream>
#include "Engine.h"

namespace engine{

    Ruler::Ruler(Engine* engine) {
        this->engine = engine;
        
    };

    void Ruler::setCommandSet(CommandSet * const cmd) {
        this->cmd =  cmd;
    }
    

    void Ruler::setActions(ActionListTurn * const actions) {
        this->actions = actions;
    };
    
    void Ruler::apply() {
        actions->apply();
    };
    
    void Ruler::impleRule(EngineMode mode) {
        
        if(cmd->get(200))//On le mettra dans l'apply(time)
        {
            ModeCommand* modeCmd = dynamic_cast<ModeCommand*>(cmd->get(200));//mode category
            engine->setMode(modeCmd->getMode());
        }
        
        if(cmd->get(300))
        {
            //gere seulement le move command pour commencer et tester
            MoveCommand* move = dynamic_cast<MoveCommand*>(cmd->get(300));
            actions->addAction(new ActionMove (move->getXmove(), move->getYmove(),move->getCharacter() ));
        }
        
        
        
        
        /*for(unsigned int i=0; i<cmd->size(); i++)
        {
            c cmd->get()
        }*/
        
        /*shot :
         while(Nocolision){
         * calcule impact
         * action boum :
         }*/
    };
    
    
    void Ruler::setState(state::State* s) {
            this->state = s;
    }

    


}

/*press ctrl+space for create function define in .h*/