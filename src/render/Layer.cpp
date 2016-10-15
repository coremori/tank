/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../state.h"
#include "Tile.h"
#include "Surface.h"
#include "Layer.h"
#include <cstddef>



namespace render {

  
    Layer::Layer (){};
    Layer::~Layer (){
        tiles.clear();
    };
    
    void Layer::setSurface (Surface* surface){
        this->surface = surface;
    };
    
    void Layer::setTile (Tile* tile){
        tiles.push_back(tile);
    };
    
    Tile Layer::getTile (int i){
        return *tiles[i];
    };
  
    void Layer::update (){
        surface->setSprite(tiles);
    }
    
    void Layer::elementToTiles(const state::ElementList* e){//pas dans le dia
        
        // std::vector<state::Element*> list;
        state::Obstacle* obstacle = NULL;
        state::Tank* tank = NULL;
        state::Missile* missile = NULL;
        state::Shell* shell = NULL;
        state::Element* element = NULL;

        for(int i=0; i<e->size(); i++)
        {   
            element = e->get(i);
            tiles.push_back(new Tile(element->getX(),element->getY()));
            switch(element->getTypeId()){
                case state::obstacle : //obstacle
                        obstacle = dynamic_cast<state::Obstacle*>(element);
                        switch(obstacle->getObstacleTypeId()){//if a la place
                            case state::sand :
                                tiles[i]->setXTex(0);
                                tiles[i]->setYTex(88);
                                break;
                            case state::greenery:
                                tiles[i]->setXTex(16);
                                tiles[i]->setYTex(88);
                                break;
                        }
                    break;

                case state::tank :
                        tank = dynamic_cast<state::Tank*>(element);
                        tiles[i]->setHeight(24);
                        tiles[i]->setWidth(24);
                        switch(tank->getTankTypeId()){
                            case state::Little_tank_green :
                                tiles[i]->setXTex(0);
                                tiles[i]->setYTex(0);
                                break;
                            case state::Little_tank_grey :
                                tiles[i]->setXTex(96);
                                tiles[i]->setYTex(0);
                                break;
                            case state::Big_tank_green :
                                tiles[i]->setXTex(0);
                                tiles[i]->setYTex(24);
                                break;
                            case state::Big_tank_grey :
                                tiles[i]->setXTex(96);
                                tiles[i]->setYTex(24);
                                break;
                        }
                        switch(tank->getOrientation()){
                            case state::rigth_down :
                                break;
                            case state::left_down :
                                tiles[i]->setXTex(tiles[i]->getXTex()+24);
                                break;
                            case state::right_up:
                                tiles[i]->setXTex(tiles[i]->getXTex()+48);
                                break;
                            case state::left_up :
                                tiles[i]->setXTex(tiles[i]->getXTex()+72);
                                break;
                        }
                    break;

                case state::missile :
                        missile = dynamic_cast<state::Missile*>(element);
                        switch(missile->getStatus()){
                            case state::normal :
                                switch(missile->getOrientation()){
                                case state::left :
                                    tiles[i]->setHeight(8);
                                    tiles[i]->setWidth(16);
                                    tiles[i]->setXTex(8);
                                    tiles[i]->setYTex(96);
                                    break;
                                case state::rigth :
                                    tiles[i]->setHeight(8);
                                    tiles[i]->setWidth(16);
                                    tiles[i]->setXTex(8);
                                    tiles[i]->setYTex(104);
                                    break;
                                case state::up :
                                    tiles[i]->setHeight(16);
                                    tiles[i]->setWidth(8);
                                    tiles[i]->setXTex(0);
                                    tiles[i]->setYTex(96);
                                    break;
                                case state::down :
                                    tiles[i]->setHeight(16);
                                    tiles[i]->setWidth(8);
                                    tiles[i]->setXTex(24);
                                    tiles[i]->setYTex(96);
                                    break;
                                }
                                break;

                            case state::explosion :
                                tiles[i]->setXTex(16);
                                tiles[i]->setYTex(112);
                                break;

                        }

                    break;

                case state::shell :
                        shell = dynamic_cast<state::Shell*>(element);
                        switch(shell->getStatus()){
                            case state::normal :
                                switch(shell->getOrientation()){
                                    case state::left :
                                        tiles[i]->setXTex(0);
                                        tiles[i]->setYTex(112);
                                        break;
                                    case state::rigth :
                                        tiles[i]->setXTex(0);
                                        tiles[i]->setYTex(112);
                                        break;
                                    default :
                                        break;
                                }
                                break;
                            case state::explosion :
                                tiles[i]->setXTex(8);
                                tiles[i]->setYTex(112);
                                break;        
                        }
                    break;

                default ://space
                    tiles[i]->setXTex(24);
                    tiles[i]->setYTex(88);
                    break;                            
            }
        }
        if (obstacle)
            delete(obstacle);
        if (tank)
            delete(tank);
        if (shell)
            delete(shell);
        if (missile)
            delete(missile);
    };

};