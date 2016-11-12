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
                std::string s = "pv player ";
                std::string st = "  ";
                unsigned int i = 0;
                clear();
                /* for player 1*/
                const state::Tank* tank = static_cast<const state::Tank*>(e.s->getMobile(0));            
                std::string numStr = patch::to_string(tank->getPv());
                for(i = 0; i<s.size(); i++)
                    charToTiles(s[i],XChar , 50 + 8*i);
                
                charToTiles('1',XChar , 50 + 80);//player's num
                
                for(i = 0; i<st.size(); i++)
                    charToTiles(st[i],XChar , 138 + 8*i);
                
                for(unsigned int i = 0; i<numStr.size(); i++)
                    charToTiles(numStr[i] ,XChar, 146 + i*8);
                
                /* for player 2*/                              
                const state::Tank* tank2 = static_cast<const state::Tank*>(e.s->getMobile(1));            
                numStr = patch::to_string(tank2->getPv());
                for(i = 0; i<s.size(); i++)
                    charToTiles(s[i],XChar + 16 , 50 + 8*i);
                
                charToTiles('2',XChar + 16 , 50 + 80);//player's num
                
                for(i = 0; i<st.size(); i++)
                    charToTiles(st[i],XChar  + 16, 138 + 8*i);
                
                for(unsigned int i = 0; i<numStr.size(); i++)
                    charToTiles(numStr[i] ,XChar + 16, 146 + i*8);
                
                updateAll();
            }
        }
        CacheStateObserver::clear();
    }
    
    void CharLayer::setXChar (int x){
        XChar = x;
    };

}