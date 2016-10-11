/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
#include "state.h"
#include "Scene.h"
#include "SurfaceSFML.h"

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
    
    void Scene::setLayer (int idx, Surface* surface){
        layers[idx]->setSurface(surface);
    };
    
    void Scene::setLevel (){//state::State* s
        
        //
    };
  

};