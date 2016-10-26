// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
#include "state/Element.h"
#include "state/ElementList.h"
#include "state/Obstacle.h"
#include "state/Space.h"
#include "state/Tank.h"
#include "state/Missile.h"
#include "state/Shell.h"
#include "engine.h"

#include "piloteSFML.hpp"
#include "render.h"
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
   
      cout << "main() : creating thread for the render " << endl;
      
*/    
      
    State* state = new State();    
    
    
    LandscapeLayer* layer = new LandscapeLayer();
    MobileLayer* layerchar = new MobileLayer();
    CharLayer* layertext = new CharLayer();
    
    layertext->setXChar(120);
    state->getGrid().registerObserver(layer);
    state->getMobiles().registerObserver(layerchar);
    state->getMobiles().registerObserver(layertext);
    
    
    Scene* scene = new Scene();
    scene->setLayer(0,layer);
    scene->setLayer(1,layerchar);
    scene->setLayer(2,layertext);
    //scene->stateChanged(*state);
    state->registerObserver(scene);
    state->load("res/Levels/level.txt");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Engine    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
   
    engine::Engine* engine = new engine::Engine(state);
    engine::MoveCommand* mcmd = new engine::MoveCommand(0,24,1);
    engine::ActionListTurn* actions = new engine::ActionListTurn(state);
    engine->addCommand(mcmd);
    engine->setRuler();
    
    engine->getRuler()->setActions(actions);
    engine->getRuler()->impleRule(engine::play);
    engine->getRuler()->apply();
    //scene->stateChanged(*state);


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    piloteSFML* rendu = new piloteSFML(scene);// s'occupe de l'affichage de la fenetre
    
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
   

    return 0;
}
