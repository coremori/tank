

#include "Layer.h"
#include "state.h"
#include "Scene.h"
#include "CharLayer.h"


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

                render::CharLayer* charlayer = dynamic_cast<render::CharLayer*>(layers[2]);
                charlayer->setXChar(height*8);
                
                layers[2]->charToTiles('p',height*8 , 50);
                layers[2]->charToTiles('v',height*8 , 50 + 8);
                layers[2]->charToTiles(' ',height*8 , 50 + 16);
                layers[2]->charToTiles('p',height*8 , 50 + 24);
                layers[2]->charToTiles('l',height*8 , 50 + 32);
                layers[2]->charToTiles('a',height*8 , 50 + 40);
                layers[2]->charToTiles('y',height*8 , 50 + 48);
                layers[2]->charToTiles('e',height*8 , 50 + 56);
                layers[2]->charToTiles('r',height*8 , 50 + 64);
                layers[2]->charToTiles(' ',height*8 , 50 + 72);
                layers[2]->charToTiles('1',height*8 , 50 + 80);
                layers[2]->charToTiles(' ',height*8 , 50 + 88);
                layers[2]->charToTiles(' ',height*8 , 50 + 96);
                layers[2]->charToTiles('1',height*8, 50 + 104);
                layers[2]->charToTiles('0',height*8, 50 + 112);
                layers[2]->charToTiles('0',height*8, 50 + 120);

                layers[2]->charToTiles('p',height*8 +16, 50);
                layers[2]->charToTiles('v',height*8 +16, 50 + 8);
                layers[2]->charToTiles(' ',height*8 +16, 50 + 16);
                layers[2]->charToTiles('p',height*8 +16, 50 + 24);
                layers[2]->charToTiles('l',height*8 +16, 50 + 32);
                layers[2]->charToTiles('a',height*8 +16, 50 + 40);
                layers[2]->charToTiles('y',height*8 +16, 50 + 48);
                layers[2]->charToTiles('e',height*8 +16, 50 + 56);
                layers[2]->charToTiles('r',height*8 +16, 50 + 64);
                layers[2]->charToTiles(' ',height*8 +16, 50 + 72);
                layers[2]->charToTiles('2',height*8 +16, 50 + 80);
                layers[2]->charToTiles(' ',height*8 +16, 50 + 88);
                layers[2]->charToTiles(' ',height*8 +16, 50 + 96);
                layers[2]->charToTiles('1',height*8+16, 50 + 104);
                layers[2]->charToTiles('0',height*8+16, 50 + 112);
                layers[2]->charToTiles('0',height*8+16, 50 + 120);

            }
        }
        CacheStateObserver::clear();
    };
    
    int Scene::getHeight () const{
        return height;
    };
    
    int Scene::getWidth () const{
        return width;
    };

};