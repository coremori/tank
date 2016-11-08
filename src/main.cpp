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

 

int main ()
{
    
   // render::
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     Etat     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    State* state = new State();    
   
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Engine    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
   
    engine::Engine* engine = new engine::Engine(state);
    engine::ActionListTurn* actions = new engine::ActionListTurn(state);
    engine->getRuler()->setActions(actions);

    

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    piloteSFML* rendu = new piloteSFML(state);// s'occupe de l'affichage de la fenetre
    rendu->setEngine(engine);
    rendu->affiche();   
       

    return 0;
}
