/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 2:16 PM
 *
 * Part of tank */


#include "Ruler.h"
#include "CommandSet.h"
#include "MoveCommand.h"
#include "ModeCommand.h"
#include "ShotCommand.h"
#include "CommandCategory.h"
#include <cstddef>
#include <iostream>
#include "Engine.h"
#include "ActionMove.h"
#include "ActionDirection.h"
#include "ActionShot.h"
#include "DirectionCommand.h"

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
        actions->apply();
        //actions->clear();//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< enlever pour l'enregistrement
    };
        
    void Ruler::implementeRules() {
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
                
                bool impact = false;
                int target = -1;
                int xImpact = tank->getX();
                int yImpact = 0;
                int damage = 30;
                int xmax;
                //la fonction suivante calcule le point d'impact
                //tant que l'on est dans le tableau et que c'est du vide
                if(tank->getOrientation()==state::right_up)//si on tir à droite
                        xmax = tank->getX()+8+8*shot->getPower();
                    else
                        xmax = tank->getX()-8-8*shot->getPower();
                
                int ymax = tank->getY()-8*shot->getPower();
                
                if(ymax<0)
                    ymax = 0;
                yImpact = ymax;
                
                while((state->getGrid().hasCell(xImpact/8,yImpact/8)) &&  !impact)
                {
                    if(xImpact!=xmax)
                        if(tank->getOrientation()==state::right_up)//si on tir à droite
                            xImpact = xImpact+8;
                        else
                            xImpact = xImpact-8;
                    else
                        yImpact = yImpact + 8;
                    
                    
                    if(!(state->getGrid().isSpace(xImpact/8,yImpact/8)))//impact mur
                    {
                        impact = true;
                        yImpact = yImpact - 8;
                    }
                    for (int i = 0; i<state->getMobiles().size(); i++)
                        if(state->getMobile(i)->getY()==yImpact)//si on arrive sur un tank
                             if(((xImpact-state->getMobile(i)->getX())<=8) && ((xImpact-state->getMobile(i)->getX())>=-8))
                             {
                                  impact = true;
                                  yImpact = state->getMobile(i)->getY()-8;
                                  target = i;
                             }
                }//(tank->getOrientation()==state::right_up)
                actions->addAction(new ActionShot(shot->getCharacter(), target, damage, xImpact , yImpact, ymax, true));
                
                
            }
            else//tir au sol
            {
                int x = tank->getX()/8; // 8 est le nombre de pixel par bloc (element en position par pixel mais tableau d'element indexé en blocs (sand...)....)
                int y = tank->getY()/8-2;
                bool impact = false;
                int target = -1;
                int xImpact = 0;
                if(tank->getOrientation()==state::right_down)
                        xImpact = state->getGrid().getWidth()*8;
                    
                int yImpact = 0;
                int damage = 10;
                //la fonction suivante calcule le point d'impact
                //tant que l'on est dans le tableau et que c'est du vide                
                while((state->getGrid().hasCell(x,y)) &&  !impact)
                {
                    if(tank->getOrientation()==state::right_down)//si on tir à droite
                        x = x+1;//on peut avancer !
                    else
                        x = x-1;//on tir dans l'autre sens (recule)
                    
                    if(!(state->getGrid().isSpace(x,y)))//impact mur
                    {
                        impact = true;
                        if(tank->getOrientation()==state::right_down)
                            xImpact = 8*x-3;
                        else
                            xImpact = 8*x+3;
                        yImpact = 8*y;
                    }
                    for (int i = 0; i<state->getMobiles().size(); i++)
                        if(state->getMobile(i)->getX()==8*x)//si on arrive sur un tank
                             if(((8*y-state->getMobile(i)->getY())<=0) && ((8*y-state->getMobile(i)->getY())>=-16))
                             {
                                  impact = true;
                                  xImpact = state->getMobile(i)->getX();
                                  yImpact = state->getMobile(i)->getY();
                                  target = i;
                             }
                }
                actions->addAction(new ActionShot(shot->getCharacter(), target, damage, xImpact , yImpact, -1, (tank->getOrientation()==state::right_down)));
            } 
        }
        apply();
    }

    
    
    void Ruler::setState(state::State* s) {
            this->state = s;
    }

    


}

/*press ctrl+space for create function define in .h*/