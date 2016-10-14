#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state/Element.h"
#include "state/ElementList.h"
#include "state/Obstacle.h"
#include "render/SurfaceSFML.hpp"
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
    list[1] = new state::Obstacle(1);
    
    list[2] = new state::Obstacle(2);
    
    list[3] = new state::Obstacle(1);
    
    
    for(int i=0; i<list->size(); i++)
        {   
            state::Element* e = list->get(i);
            render::Tile* t = new render::Tile(e->getX(),e->getY());
            switch(e->getTypeId()){
                    case 1: //obstacle
                        switch(e->getObstacleType()){//if a la place
                                case sand
                                    break;
                                case state::ObstacleTypeId::greenery:
                                    break;
                        }
                        case 2://space
                            break;
                            case 3://tank
                                break;
                                case 4://missile
                                    break;
                                    case 5://shell
                                        break;
            }
                                            
        }
    render::Scene* s = new render::Scene();
    s->setLayer(0, test);*/
    
   SurfaceSFML* s = new SurfaceSFML();
   s->loadTexture("res/Textures/textures.png");
   
   std::vector<Tile*> tile;
   tile.push_back( new Tile(16,16,8,8));
   tile[0]->setXTex(0);
   tile[0]->setYTex(88);
   s->setSprite(tile);
   s->load(tile);       

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
