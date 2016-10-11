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
        std::vector<Surface*> surfaces;
        surfaces[0] = new SurfaceSFML();
        surfaces[0]->loadTexture("res/Textures/textures.png",0,88);//sand
        layers.push_back(new Layer());
        layers[0]->setSurface(surfaces[0]);
                
        layers[0]->setTile(new Tile());
        layers[0]->setTile(new Tile(0,8));
        layers[0]->setTile(new Tile(0,16));
        
        layers[0]->surface->setSpriteTexture(0,layers[0]->getTile(0));
        layers[0]->surface->setSpriteTexture(0,layers[0]->getTile(1));
        layers[0]->surface->setSpriteTexture(0,layers[0]->getTile(2));
        
        layers[0]->surface->affiche();
    };
  

};