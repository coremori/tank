/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 6, 2016, 2:53 PM
 *
 * Part of tank */


#include "CacheStateObserver.h"

namespace client{

            
    void CacheStateObserver::stateChanged(const state::StateEvent& e) {
        stateEvent.push_back(e.clone());
        }

    void CacheStateObserver::clear() {
        for(unsigned int i = 0; i<stateEvent.size(); i++)
            delete(stateEvent[i]);
        stateEvent.clear();
    }

}
/*press ctrl+space for create function define in .h*/

