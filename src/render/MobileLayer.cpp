/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 25, 2016, 2:56 PM
 *
 * Part of tank */


#include "MobileLayer.h"
#include "../state/StateEventId.h"
#include "../state/ElementEvent.h"
#include "../state/ProjectileEvent.h"
#include "../state/Element.h"
#include "../state/Tank.h"
#include "../state/TypeId.h"
#include <cstddef>
#include "../state.h"
#include "Shell.h"
#include "Missile.h"


namespace render{
    void MobileLayer::applyStateChanged() {//move tank sprite's and create the projectiles
        for(unsigned int i = 0; i<stateEvent.size(); i++){
            if(*stateEvent[i]==state::Element_Changed)
            {
                const state::ElementEvent* event = static_cast<const state::ElementEvent*>(stateEvent[i]);
                if(event->idx!=-1)// -1 = changement de niveau
                {
                    unsigned int idx = event->idx;

                    if (idx<tiles.size())
                    {
                        state::Tank* tank = dynamic_cast<state::Tank*>(event->list->get(idx));
                        tiles[idx].setX(tank->getX()-8);
                        tiles[idx].setY(tank->getY()-2*8);
                        switch(tank->getTankTypeId()){
                                case state::Little_tank_green :
                                    tiles[idx].setXTex(0);
                                    tiles[idx].setYTex(0);

                                    break;
                                case state::Little_tank_grey :
                                    tiles[idx].setXTex(96);
                                    tiles[idx].setYTex(0);
                                    break;
                                case state::Big_tank_green :
                                    tiles[idx].setXTex(0);
                                    tiles[idx].setYTex(24);
                                    break;
                                case state::Big_tank_grey :
                                    tiles[idx].setXTex(96);
                                    tiles[idx].setYTex(24);
                                    break;
                            }
                        switch(tank->getOrientation()){
                                case state::right_down :
                                    break;
                                case state::left_down :
                                    tiles[idx].setXTex(tiles[idx].getXTex()+24);
                                    break;
                                case state::right_up:
                                    tiles[idx].setXTex(tiles[idx].getXTex()+48);
                                    break;
                                case state::left_up :
                                    tiles[idx].setXTex(tiles[idx].getXTex()+72);
                                    break;
                            }
                        Layer::numTileToUpdate.push_back(idx);//la tuile idx sera à recharger dans Surface pour être dessiner
                    }
                    else // si on change le level
                    {
                        Layer::clear();
                        Layer::elementToTiles(event->list);
                    }

                }
            }
            else if (*stateEvent[i]==state::Projectile_Event)
            {
                const state::ProjectileEvent* event = static_cast<const state::ProjectileEvent*>(stateEvent[i]);
                        
                if(event->yMax==-1)//type shell
                {
                    tiles.push_back(*(new Tile(event->xStart, event->yStart, 8, 8)));
                    tiles[tiles.size()-1].setXTex(0);
                    tiles[tiles.size()-1].setYTex(112);
                    animation = new Shell(event->xImpact,event->rightDirection);
                }
                else
                {
                    tiles.push_back(*(new Tile(event->xStart, event->yStart, 8, 16)));
                    tiles[tiles.size()-1].setXTex(0);
                    tiles[tiles.size()-1].setYTex(96);
                    
                    animation = new Missile(event->xImpact, event->yImpact, event->rightDirection, event->yMax);
                }
               
            }
        }
        CacheStateObserver::clear();
    }
        

}
