/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 1:43 PM
 *
 * Part of tank */


#include "Observable.h"

namespace state {

    void Observable::notifyObserver(const StateEvent& event) {
        for(unsigned int i=0; i<observers.size(); i++)
            observers[i]->stateChanged(event);
    };
       
    void Observable::registerObserver(StateObserver* obs) const {
        observers.push_back(obs);
    }
    
    Observable::~Observable() {
        observers.clear();
    }


}
/*press ctrl+space for create function define in .h*/