/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 2:16 PM
 *
 * Part of tank */


#include "Ruler.h"
#include "CommandSet.h"
#include "MoveCommand.h"
#include "ModeCommand.h"
#include "CommandCategory.h"
#include "ActionMove.h"
#include <cstddef>
#include <iostream>
#include "Engine.h"
#include "ActionDirection.h"
#include "DirectionCommand.h"
#include "ShotCommand.h"
#include "state/Tank.h"

namespace engine{

    Ruler::Ruler(Engine* engine) {
        this->engine = engine;
        
    };

    void Ruler::setCommandSet(CommandSet * const cmd) {
        this->cmd =  cmd;
    }
    

    void Ruler::setActions(ActionListTurn * const actions) {
        this->actions = actions;
    };
    
    void Ruler::apply() {
        if(cmd->get(200))//On le mettra dans l'apply(time)
        {
            ModeCommand* modeCmd = dynamic_cast<ModeCommand*>(cmd->get(200));//mode category
            engine->setMode(modeCmd->getMode());
        }
        if(cmd->get(VIEW_CATEGORY))
        {
            DirectionCommand* dcmd = dynamic_cast<DirectionCommand*>(cmd->get(VIEW_CATEGORY));
            actions->addAction(new ActionDirection(dcmd->getDirection(),dcmd->getCharacter()));
        }
        if(cmd->get(MOVE_CATEGORY))
        {
            //gere seulement le move command pour commencer et tester
            //
            
            MoveCommand* move = dynamic_cast<MoveCommand*>(cmd->get(MOVE_CATEGORY));
            
            int nextX = state->getMobile(move->getCharacter())->getX()+move->getXmove();
            int nextY = state->getMobile(move->getCharacter())->getY()+move->getYmove();
            
            if(state->getGrid().hasCell(nextX/8,nextY/8))
            {
                if(!(state->getGrid().isSpace(nextX/8,nextY/8)))
                {
                    if(state->getGrid().isSpace(nextX/8,(state->getMobile(move->getCharacter())->getY())/8+1))
                    {
                        actions->addAction(new ActionMove (move->getXmove(), move->getYmove()+8,move->getCharacter() ));
                    }
                    else if(((state->getGrid().isSpace(nextX/8,(state->getMobile(move->getCharacter())->getY()/8)-1))))
                    {
                        actions->addAction(new ActionMove (move->getXmove(), move->getYmove()-8,move->getCharacter() ));
                    }
                }
                else 
                {
                    if(!(state->getGrid().isSpace(nextX/8,(nextY/8)+1)))
                    {
                        actions->addAction(new ActionMove (move->getXmove(), move->getYmove(),move->getCharacter()));
                    }
                    else
                    {
                        if((state->getGrid().isSpace(nextX/8,nextY/8-1)) && (!(state->getGrid().isSpace(nextX/8,nextY/8))))
                        {
                            actions->addAction(new ActionMove (move->getXmove(), move->getYmove()-8,move->getCharacter()));
                        }
                        else if((state->getGrid().isSpace(nextX/8,nextY/8+1)) && (!(state->getGrid().isSpace(nextX/8,nextY/8+2))))
                        {
                            actions->addAction(new ActionMove (move->getXmove(), move->getYmove()+8,move->getCharacter()));
                        }
                            
                    }
                        
                }
            }
            
        }
        if(cmd->get(SHOT_CATEGORY))//Tir commande
        {
            ShotCommand* shot = dynamic_cast<ShotCommand*>(cmd->get(SHOT_CATEGORY));
            state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(shot->getCharacter()));
            if(tank->getOrientation()==state::right_up || tank->getOrientation()==state::left_up)//si on vise en haut
            {
                //note contre-intuitif : y = 0 est le haut, y = 252522xxx le bas de l'écran
            }
            else//tir au sol
            {
                int x = tank->getX()/8; // 8 est le nombre de pixel par bloc (element en position par pixel mais tableau d'element indexé en blocs (sand...)....)
                int y = tank->getY()/8;
                bool impact = false;
                
                while((state->getGrid().hasCell(x,y)) &&  !impact)//tant que l'on est dans le tableau et que c'est du vide
                {
                    if(!(state->getGrid().isSpace(x,y)))//impact mur
                        impact = false;
                    
                    for (int i = 0; i<state->getGrid().size(); i++)
                        if(state->getGrid().get(i)->getX()==x)//si on arrive sur un tank
                             if(((8*y-state->getGrid().get(i)->getY()-1)>=0) && ((8*y-state->getGrid().get(i)->getY()-1)<=3))
                             {
                                  impact = true;
                                  
                             }
                                
                       
                    if(tank->getOrientation()==state::right_down)//si on tir à droite
                        x = x+1;//on peut avancer !
                    else
                        x = x-1;//on tir dans l'autre sens (recule)
                }
                
            } 
        }
        
        
        
        
        /*for(unsigned int i=0; i<cmd->size(); i++)
        {
            c cmd->get()
        }*/
        
        /*shot :
         while(Nocolision){
         * calcule impact
         * action boum :
         }*/
        actions->apply();
        actions->clear();//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< enlever pour l'enregistrement
    };
    
    
    
    
    void Ruler::setState(state::State* s) {
            this->state = s;
    }

    


}

/*press ctrl+space for create function define in .h*/