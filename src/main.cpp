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


int main ()
{
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Multithreading - engine+IA et rendu >>>>>>>>>>>>>>>>>>>>>>
    
    client::Pilote* pilote = new client::Pilote();
    pilote->launch();
       

    return 0;
}
