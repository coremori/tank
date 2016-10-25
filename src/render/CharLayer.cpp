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

    void CharLayer::stateChanged(const state::StateEvent& e) {
        if (e==state::Pv_Changed)
        {
            const state::Tank* tank = static_cast<const state::Tank*>(e.s->getMobile(0));            
            std::string numStr = patch::to_string(tank->getPv());
            Layer::clear();
            Layer::charToTiles('s',XChar);
            Layer::charToTiles('c',XChar);
            Layer::charToTiles('o',XChar);
            Layer::charToTiles('r',XChar);
            Layer::charToTiles('e',XChar);
            Layer::charToTiles(' ',XChar);
            for(unsigned int i = 0; i<numStr.size(); i++)
                Layer::charToTiles(numStr[i] ,XChar);
        }
    }
    
    void CharLayer::setXChar (int x){
        XChar = x;
    };

}
/*press ctrl+space for create function define in .h*/