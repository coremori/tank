/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
#include "state.h"
#include "Scene.h"


namespace render {

  
    Scene::Scene (){
        
    };
    Scene::~Scene (){};
        
    
    int Scene::getLayerCount () const{
        return layers.size();
    };
    
    void Scene::setSurface (int idx, Surface* surface){
        layers[idx]->setSurface(surface);
    };
    
        
    void Scene::setLayer (int idx, Layer* layer){
        if(idx==getLayerCount())
            layers.push_back(layer);
        layers[idx] = layer;
    };
    
    void Scene::update (){
        layers[1]->update();
        layers[2]->update();
    };
      
    void Scene::updateAll() {
        layers[0]->updateAll();
        layers[1]->updateAll();
        layers[2]->updateAll();
    }
    void Scene::applyStateChanged() {
        for(unsigned int i = 0; i<stateEvent.size(); i++){
            state::StateEvent e = *stateEvent[i];
            //notifié par son observateur
            if(e==state::Level_Changed){//on charge tout le level
                height = e.s->getGrid().getHeight();
                width = e.s->getGrid().getWidth();
                state::ElementGrid g = e.s->getGrid();
                state::ElementList l = e.s->getMobiles();
                layers[0]->clear();
                layers[1]->clear();
                layers[2]->clear();

                layers[0]->elementToTiles(&g);
                layers[1]->elementToTiles(&l);


                layers[2]->charToTiles('s',height*8);
                layers[2]->charToTiles('c',height*8);
                layers[2]->charToTiles('o',height*8);
                layers[2]->charToTiles('r',height*8);
                layers[2]->charToTiles('e',height*8);
                layers[2]->charToTiles(' ',height*8);
                layers[2]->charToTiles('0',height*8);
                layers[2]->charToTiles('0',height*8);
            }
        }

    };
    
    int Scene::getHeight () const{
        return height;
    };
    
    int Scene::getWidth () const{
        return width;
    };

};