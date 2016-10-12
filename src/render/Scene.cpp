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
    
    int Scene::getWidth () const{
        return width;
    };
    
    int Scene::getHeight () const{
        return height;
    };
    
    int Scene::getLayerCount () const{
        return layers.size();
    };
    
    void Scene::setSurface (int idx, Surface* surface){
        layers[idx]->setSurface(surface);
    };
    
        
    void Scene::setLayer (int idx, Layer* layer){
        layers[idx] = layer;
    };
    
    void Scene::update (){
        layers[0]->update();
    };
  

};