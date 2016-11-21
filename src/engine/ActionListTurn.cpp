/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 2:05 PM
 *
 * Part of tank */


#include "ActionListTurn.h"
#include "Action.h"

namespace engine{
    

    ActionListTurn::ActionListTurn(state::State* s) {
        this->state = s;
        notify = true;
    };
    
    ActionListTurn::~ActionListTurn() {
        for(Action* action : actions)
            delete(action);
    }
    
    void ActionListTurn::addAction(Action* a) {
        actions.push_back(a);
    };
    
    void ActionListTurn::apply() {
        for(unsigned int i=0; i<actions.size(); i++)
            actions.at(i)->apply(state,notify);
    };

    void ActionListTurn::undo() {
        for(unsigned int i=0; i<actions.size(); i++)
            actions.at(i)->undo(state);
    };
    
    void ActionListTurn::clear() {
        actions.clear();
    }

}
/*press ctrl+space for create function define in .h*/