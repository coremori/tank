/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on September 24, 2016, 3:34 PM
 *
 * Part of tank */

#include <thread>

#include "state/State.h"
#include "engine/Engine.h"
#include "client/PiloteSFML.h"
#include "client/Pilote.h"


#include <pthread.h>

void eng(engine::Engine* e){
    client::Pilote pilote = *(new client::Pilote(e));
    pilote.run();
}

void rend(client::PiloteSFML* p){
    p->affiche();
}

int main ()
{
           
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     Etat     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    state::State* state = new state::State();    
   
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Engine    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
   
    engine::Engine* engine = new engine::Engine(state);
    engine::ActionListTurn* actions = new engine::ActionListTurn(state);
    engine->getRuler()->setActions(actions);
    
    

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
        client::PiloteSFML* rendu = new client::PiloteSFML(state);// s'occupe de l'affichage de la fenetre
        rendu->setEngine(engine);
    
    
    
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Multithreading - engine+IA et rendu >>>>>>>>>>>>>>>>>>>>>>
        
    std::thread t1(eng,engine); // pass by value
    std::thread t2(rend,rendu); // pass by value
    t2.join();
    t1.join();
    
       

    return 0;
}
