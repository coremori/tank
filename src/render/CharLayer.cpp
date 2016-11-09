/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 3:39 PM
 *
 * Part of tank */


#include "CharLayer.h"
#include "../state/StateEventId.h"
#include "../state/Tank.h"
#include <iostream>
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



namespace render {
    void CharLayer::applyStateChanged() {
        for(unsigned int i = 0; i<stateEvent.size(); i++){
            state::StateEvent e = *stateEvent[i];
            if (e==state::Pv_Changed)
            {
                const state::Tank* tank = static_cast<const state::Tank*>(e.s->getMobile(0));            
                std::string numStr = patch::to_string(tank->getPv());
                Layer::clear();
                
                Layer::charToTiles('p',XChar, 50);
                Layer::charToTiles('v',XChar, 50 + 8);
                Layer::charToTiles(' ',XChar, 50 + 16);
                Layer::charToTiles('p',XChar, 50 + 24);
                Layer::charToTiles('l',XChar, 50 + 32);
                Layer::charToTiles('a',XChar, 50 + 40);
                Layer::charToTiles('y',XChar, 50 + 48);
                Layer::charToTiles('e',XChar, 50 + 56);
                Layer::charToTiles('r',XChar, 50 + 64);
                Layer::charToTiles(' ',XChar, 50 + 72);
                Layer::charToTiles('1',XChar, 50 + 80);
                Layer::charToTiles(' ',XChar, 50 + 88);
                Layer::charToTiles(' ',XChar, 50 + 96);

                for(unsigned int i = 0; i<numStr.size(); i++)
                    Layer::charToTiles(numStr[i] ,XChar, 146 + i*8);
                    
                const state::Tank* tank2 = static_cast<const state::Tank*>(e.s->getMobile(1));            
                numStr = patch::to_string(tank2->getPv());
                Layer::charToTiles('p',XChar + 16, 50);
                Layer::charToTiles('v',XChar + 16, 50 + 8);
                Layer::charToTiles(' ',XChar + 16, 50 + 16);
                Layer::charToTiles('p',XChar + 16, 50 + 24);
                Layer::charToTiles('l',XChar + 16, 50 + 32);
                Layer::charToTiles('a',XChar + 16, 50 + 40);
                Layer::charToTiles('y',XChar + 16, 50 + 48);
                Layer::charToTiles('e',XChar + 16, 50 + 56);
                Layer::charToTiles('r',XChar + 16, 50 + 64);
                Layer::charToTiles(' ',XChar + 16, 50 + 72);
                Layer::charToTiles('2',XChar + 16, 50 + 80);
                Layer::charToTiles(' ',XChar + 16, 50 + 88);
                Layer::charToTiles(' ',XChar + 16, 50 + 96);
                for(unsigned int i = 0; i<numStr.size(); i++)
                    Layer::charToTiles(numStr[i] ,XChar + 16, 146 + i*8);
                
                updateAll();
            }
        }
        CacheStateObserver::clear();
    }
    
    void CharLayer::setXChar (int x){
        XChar = x;
    };

}