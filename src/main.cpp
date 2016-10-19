// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
#include "state/Element.h"
#include "state/ElementList.h"
#include "state/Obstacle.h"
#include "state/SpaceTypeId.h"
#include "state/Space.h"
#include "state/Tank.h"
#include "state/Missile.h"
#include "state/Shell.h"

#include "piloteSFML.hpp"
/*#include <cstdlib>
#include <pthread.h>*/

/* #define NUM_THREADS     5*/

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;
using namespace state;
using namespace render;

    
void Flemme(void *){
       /* cout << "I do nothing (the others works for me)" << endl;
        
        pthread_exit(NULL);*/
    }



int main ()
{
   /*pthread_t threads[NUM_THREADS];
   int rc;
   void *status;
   
      cout << "main() : creating thread for the render " << endl;*/
      
    
      
    State* state = new State();    
    state->getGrid().set(0,new Obstacle(state::ObstacleTypeId::sand));
    state->getGrid().setHeight(240);
    state->getGrid().setWidth(1200);
    
    
    Layer* layer = new Layer();    
    Scene* scene = new Scene();
    scene->setLayer(0,layer);
    scene->stateChanged(*state);
    piloteSFML* rendu = new piloteSFML(scene);/* s'occupe de l'affichage de la fenetre*/
    rendu->affiche();
    
     /*
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
   */

        string line;
        ifstream myfile("res/Levels/level.txt");
            if(myfile.is_open())
            {
                while (getline(myfile,line))
                {
                    cout << line << '\n';
                }
                myfile.close();
            }
            else cout << "Unable to open file"; 

   

    return 0;
}
