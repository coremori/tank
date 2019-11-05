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
#include "ActionMove.h"
#include "ActionDirection.h"
#include "ActionShot.h"
#include "DirectionCommand.h"

// #include "state/Tank.h"


namespace engine{
    
    
    
    
    
    
    
    Ruler::Ruler() {

        
    };
    
    
    
    
    
    
    
    
    void Ruler::setCommandSet(CommandSet * const cmd) {
        this->cmd =  cmd;
    }
    
    
    
    
    
    
    

    void Ruler::setActions(ActionListTurn * const actions) {
        this->actions = actions;
    };
    
    
    
    
    
    
    
    
    
    
    
    void Ruler::apply() {
        actions->apply();
    };
    
    
    
    
    
    void Ruler::undo (){
        actions->undo();
    }
    
    
    
    
    
    
    
    
    void Ruler::implementeRules() {
        
        
        // if (cmd->get(VIEW_CATEGORY))
        // {
        //     DirectionCommand* dcmd = dynamic_cast<DirectionCommand*>(cmd->get(VIEW_CATEGORY));
        //     state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(dcmd->getCharacter()));
        //     if (tank->getOrientation()!=dcmd->getDirection())
        //         actions->addAction(new ActionDirection(dcmd->getDirection(),dcmd->getCharacter()));
        // }
        
        
        // if (cmd->get(MOVE_CATEGORY))
        // {
        //     MoveCommand* move = dynamic_cast<MoveCommand*>(cmd->get(MOVE_CATEGORY));
            
        //     int nextX = state->getMobile(move->getCharacter())->getX()+move->getXmove();
        //     int nextY = state->getMobile(move->getCharacter())->getY()+move->getYmove();
            
        //     if (state->getGrid().hasCell(nextX/8,nextY/8))//si la case sur laquelle le char va est dans le paysage
        //     {   //car une unité de texture fait 8 pixels de largeur.
                
        //         if (!(state->getGrid().isSpace(nextX/8,nextY/8))){//si la case sur laquelle le char se dirige est un mur
        //             if (((state->getGrid().isSpace(nextX/8,(state->getMobile(move->getCharacter())->getY()/8)-1))))//on va sur le mur s'il y a de la place sur la case au-dessus
        //             {
        //                 actions->addAction(new ActionMove (move->getXmove(), move->getYmove()-8,move->getCharacter() ));
        //             }
        //         }
        //         else //s'il y a de la place sur la case vers laquelle le char se dirige
        //         {
        //             if (!(state->getGrid().isSpace(nextX/8,(nextY/8)+1)))//s'il n'y a pas de descente
        //             {
        //                 actions->addAction(new ActionMove (move->getXmove(), move->getYmove(),move->getCharacter()));//on va tout droit
        //             }
        //             else //
        //             {   
        //                 if ((state->getGrid().isSpace(nextX/8,nextY/8+1)) && (!(state->getGrid().isSpace(nextX/8,nextY/8+2))))//si on a bien un "escalier" et pas le vide...
        //                 {
        //                     actions->addAction(new ActionMove (move->getXmove(), move->getYmove()+8,move->getCharacter()));
        //                 }
        //             }
                        
        //         }
        //     }
            
        // }
        
        

        // if (cmd->get(SHOT_CATEGORY))//Shot command
        // {
        //     ShotCommand* shot = dynamic_cast<ShotCommand*>(cmd->get(SHOT_CATEGORY));
        //     state::Tank* tank = dynamic_cast<state::Tank*>(state->getMobile(shot->getCharacter()));
        //     state::Orientation o;
        //     if (cmd->get(VIEW_CATEGORY))
        //     {
        //         DirectionCommand* dcmd = dynamic_cast<DirectionCommand*>(cmd->get(VIEW_CATEGORY));
        //         o = dcmd->getDirection();
        //     }
        //     else
        //     {
        //         o = tank->getOrientation();
        //     }
            
            
        //     if (o==state::right_up || o==state::left_up)//si on vise en haut = tir de missile
        //     {
        //         //note contre-intuitif : y = 0 est le haut, y = 252522xxx le bas de l'écran
                
        //         bool impact = false;
        //         int target = -1; //-1 pour dire que le char n'est pas touché
        //         int xImpact = tank->getX();
        //         int yImpact = 0;
        //         int damage = 30;
        //         int xmax;//bord de l'écran
        //         //la fonction suivante calcule le point d'impact
        //         //tant que l'on est dans le tableau et que c'est du vide
                
        //         if (o==state::right_up)//si on tire à droite
        //             xmax = tank->getX()+8+8*shot->getPower();
        //         else //si on tire à gauche
        //             xmax = tank->getX()-8-8*shot->getPower();
                
        //         int ymax = tank->getY()-8*shot->getPower();
                
        //         if (ymax<0)//sécurité dans le cas où l'on atteint le plafond du ciel
        //             ymax = 0;
        //         yImpact = ymax;
                
        //         while((state->getGrid().hasCell(xImpact/8,yImpact/8)) &&  !impact)
        //         {
        //             if (xImpact!=xmax){
        //                 if (o==state::right_up)//si on tire à droite
        //                     xImpact = xImpact+8;
        //                 else
        //                     xImpact = xImpact-8;
        //             }
        //             else
        //                 yImpact = yImpact + 8;
                    
                    
        //             if (!(state->getGrid().isSpace(xImpact/8,yImpact/8)))//impact mur
        //             {
        //                 impact = true;
        //                 yImpact = yImpact - 8;
        //             }
                    
        //             for (int i = 0; i < state->getMobiles().size(); i++)
        //                 if (state->getMobile(i)->getY()==yImpact)//si on arrive sur un tank
        //                      if (((xImpact-state->getMobile(i)->getX())<=8) && ((xImpact-state->getMobile(i)->getX())>=-8))
        //                      {
        //                           impact = true;
        //                           yImpact = state->getMobile(i)->getY()-8;
        //                           target = i;
        //                      }
        //         }//(tank->getOrientation()==state::right_up)
        //         actions->addAction(new ActionShot(shot->getCharacter(), target, damage, xImpact , yImpact, ymax, true));
                
                
        //     }
            
        //     else //tir d'obus
        //     {
        //         int x = tank->getX()/8; // 8 est le nombre de pixel par bloc (element en position par pixel mais tableau d'element indexé en blocs (sand...)....)
        //         int y = tank->getY()/8-2; //pour que le projectile parte au niveau du canon et pas des roues!
        //         bool impact = false;
        //         int target = -1;
        //         int xImpact = 0;
        //         if (o==state::right_down)
        //                 xImpact = state->getGrid().getWidth()*8;
                    
        //         int yImpact = 0;
        //         int damage = 10;
                
        //         //la fonction suivante calcule le point d'impact
        //         //tant que l'on est dans le tableau et que c'est du vide                
        //         while((state->getGrid().hasCell(x,y)) &&  !impact)
        //         {
        //             if (o==state::right_down)//si on tire à droite
        //                 x = x+1;//on peut avancer !
        //             else //on tire à gauche
        //                 x = x-1;
                    
        //             if (!(state->getGrid().isSpace(x,y)))//impact mur
        //             {
        //                 impact = true;
        //                 if (o==state::right_down)
        //                     xImpact = 8*x-3; //-3 pour que l'explosion soit centrée sur le tank
        //                 else
        //                     xImpact = 8*x+3;
                        
        //                 yImpact = 8*y;
        //             }
                    
        //             for (int i = 0; i < state->getMobiles().size(); i++){
                        
        //                 if (state->getMobile(i)->getX() == 8*x){//si on arrive sur un tank
                            
        //                     if (((8*y-state->getMobile(i)->getY())<=0) && ((8*y-state->getMobile(i)->getY())>=-16))
        //                     {
        //                           impact = true;
        //                           xImpact = state->getMobile(i)->getX();
        //                           yImpact = state->getMobile(i)->getY();
        //                           target = i;
        //                     }
        //                 }
        //             }
        //         }
        //         actions->addAction(new ActionShot(shot->getCharacter(), target, damage, xImpact , yImpact, -1, (o==state::right_down)));
        //     } 
        // }
        // apply();
    }

    
    
    
    
    
    
    
    void Ruler::setState(state::State* s) {
            this->state = s;
    }


}
