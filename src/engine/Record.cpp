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
        this->initState = new state::State();
        initState->load("res/Levels/level1.txt");
        
        this->lastState = &s;
        idx = 0;
        //fonction clone() nécéssaire pour toute les classes du State.dia (youhou)
    }

    Record::~Record() {

    }

    
    void Record::clear (){//clear actions
        for(ActionListTurn* action : actions)
            delete(action);
        actions.clear();
    }
    
    void Record::recordOne (ActionListTurn* actions){//push back in action list the given arguments
        this->actions.push_back(actions);
    }
    
    void Record::startReplay (){
        //lastState = mainState; copy mon amie where are you?
        //mainState = initState;
        mainState.load("res/Levels/level1.txt");
    }
    
    bool Record::replayOne (){
        unsigned i = idx;
        if(i >=actions.size())
            return false;//probablement si dernier tour enregistrer (pas de suivant)
        /*if(idx == 0)
            mainState = *initState; */
        actions[idx]->apply();
        idx ++;
        return true;
    }
    
    void Record::startRollback (){//rollback all the game, and you can see it
        typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<float, std::milli> duration;
        clock::time_point start = clock::now();
        duration elapsed;
        
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