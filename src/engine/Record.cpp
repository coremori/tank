/*
 * Author: Corentin Morisse & Pierre-Bernard Le Roux
 * Created on November 7, 2016, 6:07 PM
 *
 * Part of Projet 
 */
#include "Record.h"

// il faut : à chaque tour on rajoute une actionlistTurn à la liste ; on ratache celle-ci au Ruler (lancer par engine.endTurn())
// l'engine (de préference, mais le ruler passe pour l'instant) doit géré le mode (reccord, normal...)
namespace engine{
    Record::Record (state::State& s) : mainState(s){//veut plus compiler sinon :(
        
    }
    void Record::clear (){
        
    }
    void Record::startRecord (){
        
    }
    void Record::recordOne (ActionListTurn* actions){
        
    }
    void Record::stopRecord (){
        
    }
    void Record::startReplay (){
        
    }
    bool Record::replayOne (){
        return false;//probablement si dernier tour enregistrer (pas de suivant)
    }
    void Record::startRollback (){
        
    }
    bool Record::rollbackOne (){
        return false; // probablement si premier tour enregistrer (pas de tour précédent)
    }
}