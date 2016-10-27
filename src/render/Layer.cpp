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
        
    void Layer::clear() {
        tiles.clear();
    }
    
    void Layer::elementToTiles(const state::ElementList* e){//pas dans le dia
        
        // std::vector<state::Element*> list;
        state::Obstacle* obstacle = NULL;
        state::Tank* tank = NULL;
        state::Missile* missile = NULL;
        state::Shell* shell = NULL;
        state::Element* element = NULL;
        unsigned prevSize = tiles.size();
        for(int i=0; i<e->size(); i++)
        {   
            element = e->get(i);
            setTile(new Tile(element->getX(),element->getY()));
            switch(element->getTypeId()){
                case state::obstacle : //obstacle
                        obstacle = dynamic_cast<state::Obstacle*>(element);
                        switch(obstacle->getObstacleTypeId()){//if a la place
                            case state::sand :
                                tiles[i+prevSize]->setXTex(40);
                                tiles[i+prevSize]->setYTex(88);
                                break;
                            case state::greenery:
                                tiles[i+prevSize]->setXTex(64);
                                tiles[i+prevSize]->setYTex(88);
                                break;
                            case  state::border:
                                tiles[i+prevSize]->setXTex(48);
                                tiles[i+prevSize]->setYTex(88);
                                break;
                        }
                    break;

                case state::tank :
                        tank = dynamic_cast<state::Tank*>(element);
                        tiles[i+prevSize]->setHeight(24);
                        tiles[i+prevSize]->setWidth(24);
                        tiles[i+prevSize]->setX(tiles[i+prevSize]->getX()-8);
                        tiles[i+prevSize]->setY(tiles[i+prevSize]->getY()-2*8);
                        switch(tank->getTankTypeId()){
                            case state::Little_tank_green :
                                tiles[i+prevSize]->setXTex(0);
                                tiles[i+prevSize]->setYTex(0);
                                
                                
                                break;
                            case state::Little_tank_grey :
                                tiles[i+prevSize]->setXTex(96);
                                tiles[i+prevSize]->setYTex(0);
                                break;
                            case state::Big_tank_green :
                                tiles[i+prevSize]->setXTex(0);
                                tiles[i+prevSize]->setYTex(24);
                                break;
                            case state::Big_tank_grey :
                                tiles[i+prevSize]->setXTex(96);
                                tiles[i+prevSize]->setYTex(24);
                                break;
                        }
                        switch(tank->getOrientation()){
                            case state::right_down :
                                break;
                            case state::left_down :
                                tiles[i+prevSize]->setXTex(tiles[i+prevSize]->getXTex()+24);
                                break;
                            case state::right_up:
                                tiles[i+prevSize]->setXTex(tiles[i+prevSize]->getXTex()+48);
                                break;
                            case state::left_up :
                                tiles[i+prevSize]->setXTex(tiles[i+prevSize]->getXTex()+72);
                                break;
                        }
                    break;

                case state::missile :
                        missile = dynamic_cast<state::Missile*>(element);
                        switch(missile->getStatus()){
                            case state::normal :
                                switch(missile->getOrientation()){
                                case state::left :
                                    tiles[i+prevSize]->setHeight(8);
                                    tiles[i+prevSize]->setWidth(16);
                                    tiles[i+prevSize]->setXTex(8);
                                    tiles[i+prevSize]->setYTex(96);
                                    break;
                                case state::rigth :
                                    tiles[i+prevSize]->setHeight(8);
                                    tiles[i+prevSize]->setWidth(16);
                                    tiles[i+prevSize]->setXTex(8);
                                    tiles[i+prevSize]->setYTex(104);
                                    break;
                                case state::up :
                                    tiles[i+prevSize]->setHeight(16);
                                    tiles[i+prevSize]->setWidth(8);
                                    tiles[i+prevSize]->setXTex(0);
                                    tiles[i+prevSize]->setYTex(96);
                                    break;
                                case state::down :
                                    tiles[i+prevSize]->setHeight(16);
                                    tiles[i+prevSize]->setWidth(8);
                                    tiles[i+prevSize]->setXTex(24);
                                    tiles[i+prevSize]->setYTex(96);
                                    break;
                                }
                                break;

                            case state::explosion :
                                tiles[i+prevSize]->setXTex(16);
                                tiles[i+prevSize]->setYTex(112);
                                break;

                        }
                        
                    break;

                case state::shell :
                        shell = dynamic_cast<state::Shell*>(element);
                        switch(shell->getStatus()){
                            case state::normal :
                                switch(shell->getOrientation()){
                                    case state::left :
                                        tiles[i+prevSize]->setXTex(0);
                                        tiles[i+prevSize]->setYTex(112);
                                        break;
                                    case state::rigth :
                                        tiles[i+prevSize]->setXTex(0);
                                        tiles[i+prevSize]->setYTex(112);
                                        break;
                                    default :
                                        break;
                                }
                                break;
                            case state::explosion :
                                tiles[i+prevSize]->setXTex(8);
                                tiles[i+prevSize]->setYTex(112);
                                break;        
                        }
                    break;

                default ://space
                    tiles[i+prevSize]->setXTex(32);
                    tiles[i+prevSize]->setYTex(88);
                    break;                            
            }
        }
        
    };
        
    void Layer::charToTiles(char c, int Ypos) {//on choisi d'alligner les truc en bas gauche avec un écart de 160 pixels (toujours modifiables après hein :P)
        unsigned prevSize = tiles.size();  
        if (c==' '){
            setTile(new Tile(160+prevSize*8,Ypos));
            tiles[prevSize]->setXTex(0);
            tiles[prevSize]->setYTex(48);//rien
        }
        else if ((c>47)&(c<57)){//nombre
            setTile(new Tile(160+prevSize*8,Ypos));
            tiles[prevSize]->setXTex((c-48)*8);
            tiles[prevSize]->setYTex(64);
        }
        else{//alphabet
            setTile(new Tile(160+prevSize*8,Ypos+1));
            tiles[prevSize]->setXTex((c-97)*8);
            tiles[prevSize]->setYTex(56);
        }    
          
    };


};