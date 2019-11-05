

#include <iosfwd>
#include <string>

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
        if (idx==getLayerCount())
            layers.push_back(layer);
        layers[idx] = layer;
    };
    
    bool Scene::update (){
        bool b = layers[1]->updateAnimation();
        layers[1]->update();
        b = b || layers[2]->updateAnimation();
        layers[2]->update();
        return b;
    };
      
    void Scene::updateAll() {
        layers[0]->updateAll();
        layers[1]->updateAll();
        layers[2]->updateAll();
    }
    
    void Scene::applyStateChanged() {
        // for(unsigned int i = 0; i<stateEvent.size(); i++){
        //     state::StateEvent e = *stateEvent[i];
        //     //notifié par son observateur
        //     if (e==state::Level_Changed){//on charge tout le level
        //         height = e.s->getGrid().getHeight();
        //         width = e.s->getGrid().getWidth();
        //         state::ElementGrid g = e.s->getGrid();
        //         state::ElementList l = e.s->getMobiles();
        //         layers[0]->clear();
        //         layers[1]->clear();
        //         layers[2]->clear();

        //         layers[0]->elementToTiles(&g);
        //         layers[1]->elementToTiles(&l);

        //         render::CharLayer* charlayer = dynamic_cast<render::CharLayer*>(layers[2]);
        //         charlayer->setXChar(height*8);
        //         std::string s = "pv player ";
        //         std::string st = "  100";
        //         unsigned int i = 0;
        //         /* for player 1*/
        //         for(i = 0; i<s.size(); i++)
        //             layers[2]->charToTiles(s[i],height*8 , 50 + 8*i);
                
        //         layers[2]->charToTiles('1',height*8 , 50 + 80);//player's num
                
        //         for(i = 0; i<st.size(); i++)
        //             layers[2]->charToTiles(st[i],height*8 , 138 + 8*i);
                
        //         /* for player 2*/
        //         for(i = 0; i<s.size(); i++)
        //             layers[2]->charToTiles(s[i],height*8 + 16 , 50 + 8*i);
                
        //         layers[2]->charToTiles('2',height*8 + 16 , 50 + 80);//player's num
                
        //         for(i = 0; i<st.size(); i++)
        //             layers[2]->charToTiles(st[i],height*8  + 16, 138 + 8*i);
        //         updateAll();
        //     }
        // }
        CacheStateObserver::clear();
    };
    
    int Scene::getHeight () const{
        return height;
    };
    
    int Scene::getWidth () const{
        return width;
    };

};