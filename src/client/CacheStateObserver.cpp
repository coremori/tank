/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 6, 2016, 2:53 PM
 *
 * Part of tank */

  /// class CacheStateObserver - Save the StateEvent that the Pilote will update after

#include "CacheStateObserver.h"

namespace client{


            
    void CacheStateObserver::stateChanged(const state::StateEvent& e) {
        /* Save the event create by the engine thread in stateEvent
         */
        stateEvent.push_back(e.clone());
    }

    
    
    
    
    void CacheStateObserver::clear() {
        /* clear the stateEvent list
         */
        for(unsigned int i = 0; i<stateEvent.size(); i++)
            delete(stateEvent[i]);
        stateEvent.clear();
    }

    
    
}

