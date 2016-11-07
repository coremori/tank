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
                        std::cout << "toto" << std::endl;
                        actions->addAction(new ActionMove (move->getXmove(), move->getYmove(),move->getCharacter()));
                    }
                    else
                    {
                        if((state->getGrid().isSpace(nextX/8,nextY/8-1)) && (!(state->getGrid().isSpace(nextX/8,nextY/8))))
                        {
                            std::cout << "toto5" << std::endl;
                            actions->addAction(new ActionMove (move->getXmove(), move->getYmove()-8,move->getCharacter()));
                        }
                        else if((state->getGrid().isSpace(nextX/8,nextY/8+1)) && (!(state->getGrid().isSpace(nextX/8,nextY/8+2))))
                        {
                             std::cout << "toto2" << std::endl;
                            actions->addAction(new ActionMove (move->getXmove(), move->getYmove()+8,move->getCharacter()));
                        }
                            
                    }
                        
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