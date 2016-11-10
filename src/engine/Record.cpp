/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 7, 2016, 6:07 PM
 *
 * Part of Projet 
 */
#include "Record.h"
#include "ActionListTurn.h"
#include <chrono>
#include <ctime>

// il faut : à chaque tour on rajoute une actionlistTurn à la liste ; on ratache celle-ci au Ruler (lancer par engine.endTurn())
// l'engine (de préference, mais le ruler passe pour l'instant) doit géré le mode (reccord, normal...)
namespace engine{
    Record::Record (state::State& s) : mainState(s){//veut plus compiler sinon :(
        this->initState = &s;
        this->lastState = &s;
        
        //fonction clone() nécéssaire pour toute les classes du State.dia (youhou)
    }
    
    void Record::clear (){//clear actions
        for(ActionListTurn* action : actions)
            delete(action);
        actions.clear();
    }
    
    void Record::startRecord (){
        
    }
    
    void Record::recordOne (ActionListTurn* actions){//push back in action list the given arguments
        this->actions.push_back(actions);
    }
    
    void Record::stopRecord (){
        
    }
    void Record::startReplay (){
        
    }
    bool Record::replayOne (){
        
        
        return false;//probablement si dernier tour enregistrer (pas de suivant)
    }
    
    void Record::startRollback (){//rollback all the game, and you can see it
        typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<float, std::milli> duration;
        clock::time_point start = clock::now();
        duration elapsed;
        
        //elapsed.count();
        //std::chrono::milliseconds millisec(20);
        bool nofini = true;
        while(nofini)
        {
            elapsed = clock::now() - start;
            if(elapsed.count()>=20)
            {
                nofini = rollbackOne();
            }
        }
    }
    
    bool Record::rollbackOne (){
        if(!actions.size())// Si pas de tour enregistrer (pas de tour précédent)
            return false;
        actions[actions.size()-1]->undo();
        actions.pop_back();
        return true; 
    }
}