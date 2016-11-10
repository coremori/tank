/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on September 24, 2016, 3:34 PM
 *
 * Part of tank */

#include "state/State.h"
#include "engine/Engine.h"
#include "client/PiloteSFML.h"

int main ()
{
    
    typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<float, std::milli> duration;
        clock::time_point start = clock::now();
        duration elapsed;
        
        //elapsed.count();
        //std::chrono::milliseconds millisec(20);
        
            elapsed = clock::now() - start;
            if(elapsed.count()>=20)
            {
                
            }
       
        
        
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     Etat     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    state::State* state = new state::State();    
   
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Engine    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
   
    engine::Engine* engine = new engine::Engine(state);
    engine::ActionListTurn* actions = new engine::ActionListTurn(state);
    engine->getRuler()->setActions(actions);

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SFML    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    client::PiloteSFML* rendu = new client::PiloteSFML(state);// s'occupe de l'affichage de la fenetre
    rendu->setEngine(engine);
    rendu->affiche();   
       

    return 0;
}
