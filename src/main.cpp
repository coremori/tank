#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state/Element.h"
#include "state/ElementList.h"
#include "state/Obstacle.h"
#include "render/SurfaceSFML.hpp"
#include "state/SpaceTypeId.h"
#include "state/Space.h"
#include "state/Tank.h"
#include "state/Missile.h"
#include "state/Shell.h"
#include <cstdlib>
#include <pthread.h>

#define NUM_THREADS     5

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;
using namespace state;
using namespace render;

    void *PrintWindows(void *)
{
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");// fenetre d'affichage
           
    /*  
    render::Surface* terrain = new render::SurfaceSFML();
    terrain->loadTexture("res/Textures/textures.png");
        
    
    
    render::Layer* test = new render::Layer();
    test->setSurface(terrain);
    
    std::vector<state::Element*> list;
    list.push_back( new state::Obstacle(state::ObstacleTypeId::sand));
    
    list.push_back(new state::Obstacle(state::ObstacleTypeId::greenery));
    
    list.push_back(new state::Space(state::SpaceTypeId::startPlayer1));
    
    state::Obstacle* o = dynamic_cast<state::Obstacle*>(list[0]);
    if(o->getObstacleTypeId() == state::sand)
        cout << "sand" <<endl;
    render::Scene* s = new render::Scene();
    s->setLayer(0, test);*/
    SurfaceSFML* s = new SurfaceSFML();
    s->loadTexture("res/Textures/textures.png");
   
   
    State* state = new State();    
    ElementList elist = state->getMobiles();
    elist.set(0,new Obstacle(state::ObstacleTypeId::sand));
    
    
    
    Layer* layer = new Layer();
    layer->setSurface(s);
    
    Scene* scene = new Scene();
    scene->setLayer(0,layer);
    scene->stateChanged(&elist);
    scene->update();
    
   
   
  /* std::vector<Tile*> tile;
   tile.push_back( new Tile(16,16,8,8));
   tile[0]->setXTex(0);
   tile[0]->setYTex(88);
   s->setSprite(tile);
   s->load(tile);     */ 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*s);        
        window.display();
    }
   pthread_exit(NULL);
}
    
void *Flemme(void *){
        cout << "I do nothing (the others works for me)" << endl;
        
        pthread_exit(NULL);
    }



int main ()
{
   pthread_t threads[NUM_THREADS];
   int rc;
   void *status;
   
      cout << "main() : creating thread for the render " << endl;
      rc = pthread_create(&threads[0], NULL, 
                          PrintWindows, NULL);
      
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
      
      rc = pthread_create(&threads[1], NULL, 
                          Flemme, NULL);
      
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
      
    pthread_join(threads[0], &status);
    pthread_join(threads[1], &status);
    
    
    cout << "I was tired of waiting" << endl;
   
   
    pthread_exit(0);
   
}
