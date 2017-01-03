/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on September 24, 2016, 3:34 PM
 *
 * Part of tank */


#include "client/Pilote.h"
#include <chrono>
#include <ctime>
#include <thread>
int main ()
{
     std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //waiting for the server initialisation
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Multithreading - engine+IA et rendu >>>>>>>>>>>>>>>>>>>>>>
        //
    client::Pilote* pilote = new client::Pilote();
    pilote->launch();
       

    return 0;
}
