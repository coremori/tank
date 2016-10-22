/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 2:16 PM
 *
 * Part of tank */


#include "Ruler.h"
#include "CommandSet.h"
#include "MoveCommand.h"
#include "ActionMove.h"
#include <cstddef>

namespace engine{

    Ruler::Ruler(state::State* state) {
        this->state = state;
    };
    
    void Ruler::apply() {
        actions->apply();
    };
        
    void Ruler::impleRule(EngineMode mode) {
        
        //gere seulement le move command pour commencer et tester
        MoveCommand* move = dynamic_cast<MoveCommand*>(cmd->get(300));
        
        actions->addAction(new ActionMove (move->getXmove(), move->getYmove(),1 ));
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

    void Ruler::setActions(ActionListTurn * const actions) {
        this->actions = actions;
    };

    void Ruler::setCommandSet(CommandSet * const cmd) {
        this->cmd =  cmd;
    }


}

/*press ctrl+space for create function define in .h*/