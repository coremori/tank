/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on December 29, 2016, 11:01 AM
 *
 * Part of tank */


#include "GameServer.h"
#include <map>
#include "ServiceException.hpp"
#include "engine/CommandCategory.h"
#include "engine/DirectionCommand.h"
#include "engine/MoveCommand.h"
#include "engine/ShotCommand.h"
#include "engine/ModeCommand.h"
#include <iostream>
#include "../state.h"
#include "ai/HeuristicAI.h"
#include "ai/TreeAI.h"
#include "engine/EndTurnCommand.h"
//><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<bibliotheque nonincluse  && reste le post

namespace server {
    GameServer::GameServer (UserDB& userDB) : AbstractService("/game"),
        userDB(userDB){
        state = new state::State();
        engine = new engine::Engine(this->state);
        state->load("res/Levels/level1.txt");
                
        commandSaved.push_back(new engine::CommandSet());
        commandSaved.push_back(new engine::CommandSet());
        
        ai.push_back(new ai::HeuristicAI(state,0));
        ai.push_back(new ai::TreeAI(state,1));
    }
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   recup commande
    HttpStatus GameServer::get (Json::Value& out, int characterSender, int characterAsked) const {

    //coté serveur, out sont les donnnées associé au GET à renvoyer
        User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

        User* userAsked = userDB.getUser(characterAsked);
        
        
        if (!userAsked)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe (joueur dont on veut récupérer les commandes
        

        if (engine->getMode() == engine::AI){
            
                commandSaved[engine->getCharTurn()]->clear();
                ai[engine->getCharTurn()]->run(*commandSaved[engine->getCharTurn()]);
                userAsked->take_command_from[1] = true;
                userAsked->take_command_from[0] = true;
                engine->takeCommands(commandSaved[engine->getCharTurn()]);
                int64_t timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
                engine->update(timeNow,0);
 
        } else{
        
            if (engine->getMode() == engine::play && userAsked->ai){
                commandSaved[engine->getCharTurn()]->clear();
                ai[engine->getCharTurn()]->run(*commandSaved[engine->getCharTurn()]);
                userAsked->take_command_from[1] = true;
                userAsked->take_command_from[0] = true;
                engine->takeCommands(commandSaved[engine->getCharTurn()]);
                int64_t timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
                engine->update(timeNow,0);
            } else if (user->take_command_from[characterAsked])
                throw ServiceException(HttpStatus::SERVICE_UNAVAILABLE,"Waiting for the other player");
        }
        
        out["Character"] = characterAsked;
        engine::CommandSet* cmd = commandSaved[characterAsked];
        
        if (cmd->get(engine::VIEW_CATEGORY))
        {
            engine::DirectionCommand* dcmd = dynamic_cast<engine::DirectionCommand*>(cmd->get(engine::VIEW_CATEGORY));
            out["Direction"] = dcmd->getDirection();
        }

        if (cmd->get(engine::MOVE_CATEGORY))
        {
            engine::MoveCommand* move = dynamic_cast<engine::MoveCommand*>(cmd->get(engine::MOVE_CATEGORY));            
            out["Xmove"] = move->getXmove();
            out["Ymove"] = move->getYmove();
        }
        if (cmd->get(engine::SHOT_CATEGORY))//Shot command
        {
            engine::ShotCommand* shot = dynamic_cast<engine::ShotCommand*>(cmd->get(engine::SHOT_CATEGORY));
            out["PowerShot"] = shot->getPower();
        }   

        if (cmd->get(engine::MODE_CATEGORY))
        {
            engine::ModeCommand* modeCmd = dynamic_cast<engine::ModeCommand*>(cmd->get(engine::MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            out["Mode"] =  modeCmd->getMode();
        }

        user->take_command_from[characterAsked] = true; //enregistrement de l'envoi, on pourra réécrire par dessus

        return HttpStatus::OK;
    }

    HttpStatus GameServer::post (const Json::Value& in, int characterSender) {//<<<  mettre des  mutex

    //coté serveur, in sont les donnnées associé au POST reçu

         User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

        if (engine->getCharTurn()!=characterSender)//Verif est ce que c'est son tour (Normalemement impossible, il faut qu'il joue lui même deux fois de suite et pour ça modif son engine....)
            throw ServiceException(HttpStatus::BAD_REQUEST,"Character sender is not the character waited");
    //        unique_ptr<User> usermod (new User(*user));
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Verif Est ce que l'autre joueur a prit les commandes ? (un tour de retard ?) Si non -> return HttpStatus::SERVICE_UNAVAILABLE
         
            
            int other = characterSender ? 0:1;
            User* userOther = userDB.getUser(other);
        if (!userOther->take_command_from[characterSender])
                    throw ServiceException(HttpStatus::SERVICE_UNAVAILABLE,"Other player didn't take the previous command");
            
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Partie lecture des données et conversion vers la liste de commande correspondante
        //Json::Value jsonIn;
        userOther->take_command_from[characterSender] = false;
        user->take_command_from[characterSender] = false;
        
        int player = in["Character"].asInt();
        commandSaved[player]->clear();
        if (in["Xmove"].asInt())
            commandSaved[player]->add(new engine::MoveCommand(player,in["Xmove"].asInt(),in["Ymove"].asInt()));
            
        if (in["Direction"].asInt()){
            // switch(in["Direction"].asInt()){
            //     case 1:
            //         commandSaved[player]->add(new engine::DirectionCommand(player,state::left_down));
            //         break;
            //     case 2:
            //         commandSaved[player]->add(new engine::DirectionCommand(player,state::left_up));
            //         break;
            //     case 3:
            //         commandSaved[player]->add(new engine::DirectionCommand(player,state::right_down));
            //         break;
            //     case 4:
            //         commandSaved[player]->add(new engine::DirectionCommand(player,state::right_up));
            //         break;
            // }
        }
                    
            

        
        if (in["PowerShot"].asInt())
            commandSaved[player]->add(new engine::ShotCommand(player,in["PowerShot"].asInt()));
            //engine->addCommand(new engine::ShotCommand(player,in["PowerShot"].asInt()));
        

        if (in["Mode"].asInt()){
            switch(in["Mode"].asInt()){
                case 1:
                    commandSaved[player]->add(new engine::ModeCommand(engine::play));
                    break;
                case 2:
                    commandSaved[player]->add(new engine::ModeCommand(engine::AI));
                    break;
                case 3:
                    commandSaved[player]->add(new engine::ModeCommand(engine::replay));
                default:
                    commandSaved[player]->add(new engine::ModeCommand(engine::play));
                    break;
            }
        }
        commandSaved[player]->add(new engine::EndTurnCommand(player));
        engine->takeCommands(commandSaved[player]);
        int64_t timeNow = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());

        engine->update(timeNow,0);
        return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
    }



}