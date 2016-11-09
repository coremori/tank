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
    
    void Layer::clear() {//Erases all the tiles
        tiles.clear();
    }
    
    void Layer::charToTiles(char c, int Ypos, int Xpos) {//on choisi d'alligner les truc en bas gauche avec un écart de 160 pixels (toujours modifiables après hein :P)
        unsigned prevSize = tiles.size();  
        if (c==' '){
            tiles.push_back(*(new Tile(Xpos,Ypos)));
            tiles[prevSize].setXTex(0);
            tiles[prevSize].setYTex(48);//rien
        }
        else if ((c>47)&&(c<58)){//nombre
            tiles.push_back((*new Tile(Xpos,Ypos)));
            tiles[prevSize].setXTex((c-48)*8);
            tiles[prevSize].setYTex(64);
        }
        else{//alphabet
            tiles.push_back(*(new Tile(Xpos,Ypos+1)));
            tiles[prevSize].setXTex((c-97)*8);
            tiles[prevSize].setYTex(56);
        }    
          
    };
    
    
    void Layer::elementToTiles(const state::ElementList* e){//pas dans le dia
        
        // std::vector<state::Element*> list;
        state::Obstacle* obstacle = NULL;
        state::Tank* tank = NULL;
        state::Element* element = NULL;
        unsigned prevSize = tiles.size();
        for(int i=0; i<e->size(); i++)
        {   
            element = e->get(i);
            tiles.push_back(*(new Tile(element->getX(),element->getY())));
            switch(element->getTypeId()){
                case state::obstacle : //obstacle
                        obstacle = dynamic_cast<state::Obstacle*>(element);
                        switch(obstacle->getObstacleTypeId()){//if a la place
                            case state::sand :
                                tiles[i+prevSize].setXTex(40);
                                tiles[i+prevSize].setYTex(88);
                                break;
                            case state::greenery:
                                tiles[i+prevSize].setXTex(64);
                                tiles[i+prevSize].setYTex(88);
                                break;
                            case  state::border:
                                tiles[i+prevSize].setXTex(48);
                                tiles[i+prevSize].setYTex(88);
                                break;
                        }
                    break;

                case state::tank :
                        tank = dynamic_cast<state::Tank*>(element);
                        tiles[i+prevSize].setHeight(24);
                        tiles[i+prevSize].setWidth(24);
                        tiles[i+prevSize].setX(tiles[i+prevSize].getX()-8);
                        tiles[i+prevSize].setY(tiles[i+prevSize].getY()-2*8);
                        switch(tank->getTankTypeId()){
                            case state::Little_tank_green :
                                tiles[i+prevSize].setXTex(0);
                                tiles[i+prevSize].setYTex(0);
                                
                                
                                break;
                            case state::Little_tank_grey :
                                tiles[i+prevSize].setXTex(96);
                                tiles[i+prevSize].setYTex(0);
                                break;
                            case state::Big_tank_green :
                                tiles[i+prevSize].setXTex(0);
                                tiles[i+prevSize].setYTex(24);
                                break;
                            case state::Big_tank_grey :
                                tiles[i+prevSize].setXTex(96);
                                tiles[i+prevSize].setYTex(24);
                                break;
                        }
                        switch(tank->getOrientation()){
                            case state::right_down :
                                break;
                            case state::left_down :
                                tiles[i+prevSize].setXTex(tiles[i+prevSize].getXTex()+24);
                                break;
                            case state::right_up:
                                tiles[i+prevSize].setXTex(tiles[i+prevSize].getXTex()+48);
                                break;
                            case state::left_up :
                                tiles[i+prevSize].setXTex(tiles[i+prevSize].getXTex()+72);
                                break;
                        }
                    break;
                default ://space
                    tiles[i+prevSize].setXTex(32);
                    tiles[i+prevSize].setYTex(88);
                    break;                            
            }
        }
        
    };
    
    Tile Layer::getTile (int i){
        return tiles[i];
    };
    
    void Layer::setTile(int idx, Tile tile) {
        tiles[idx]=tile;
    }

    void Layer::setSurface (Surface* surface){
        this->surface = surface;
    };

    void Layer::update (){// update tiles who have been modified
        if(animation != NULL)//animation existe
        {
            bool test = animation->setNextTile(&tiles[tiles.size()-1]);
            if(!test)//set the next tile of the animation and return false if it is finish
            {
                delete(animation);
                animation = NULL;
                tiles.erase(tiles.begin()+tiles.size()-1);
                updateAll();
            }
            numTileToUpdate.push_back(tiles.size()-1);
        }
        if(numTileToUpdate.size()==0)
            return;
        for(unsigned int i = 0; i<numTileToUpdate.size(); i++)
            surface->setSpriteNum(numTileToUpdate[i],tiles[numTileToUpdate[i]]);
        numTileToUpdate.clear();//clear the list
        
    }
        
    void Layer::updateAll() {// update all the tiles
        surface->clear();
        surface->setSprite(tiles);
    }
    
    
};