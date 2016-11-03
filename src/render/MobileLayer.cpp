/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 2:56 PM
 *
 * Part of tank */


#include "MobileLayer.h"
#include "../state/StateEventId.h"
#include "../state/ElementEvent.h"
#include "../state/Element.h"
#include "../state/Tank.h"
#include "../state/Shell.h"
#include "../state/Missile.h"
#include "../state/TypeId.h"
#include <cstddef>
#include "../state.h"


namespace render{

    void MobileLayer::stateChanged(const state::StateEvent& e) {
        if(e==state::Element_Changed)
        {
            
            const state::ElementEvent* event = static_cast<const state::ElementEvent*>(&e);
            if(event->idx!=-1)
            {
                Layer::clear();
                    Layer::elementToTiles(event->list);
                    
                /*if (event->idx<tiles.size())
                {
                    Layer::clear();
                    Layer::elementToTiles(event->list);
                    
                }
                else
                {
                    Layer::clear();
                    Layer::elementToTiles(event->list);
                }
                 */
            }
        }
    }

        

}
/*press ctrl+space for create function define in .h*/