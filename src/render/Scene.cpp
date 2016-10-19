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
        layers[0]->update();
        layers[1]->update();
    };
  
    void Scene::stateChanged(state::State& s){
        height = s.getGrid().getHeight();
        width = s.getGrid().getWidth();
        state::ElementGrid g = s.getGrid();
        state::ElementList l = s.getMobiles();
        layers[0]->elementToTiles(&g);
        layers[1]->elementToTiles(&l);
    };
    
    int Scene::getHeight () const{
        return height;
    };
    
    int Scene::getWidth () const{
        return width;
    };

};