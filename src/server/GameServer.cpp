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
//><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<bibliotheque nonincluse  && reste le post

namespace server {
    GameServer::GameServer (UserDB& userDB) : AbstractService("/game"),
        userDB(userDB){
        state = new state::State();
        engine = new engine::Engine(this->state);
        state->load("res/Levels/level1.txt");
                
        commandSaved.push_back(new engine::CommandSet());
        commandSaved.push_back(new engine::CommandSet());
    }
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   recup commande
    HttpStatus GameServer::get (Json::Value& out, int characterSender, int characterAsked) const {

    //coté serveur, out sont les donnnées associé au GET à renvoyer
        User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

        const User* userAsked = userDB.getUser(characterAsked);
        
        
        if (!userAsked)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe (joueur dont on veut récupérer les commandes

        
        out["Character"] = characterAsked;

        engine::CommandSet* cmd = commandSaved[characterAsked];

        
        
        
        
        if(cmd->get(engine::VIEW_CATEGORY))
        {
            engine::DirectionCommand* dcmd = dynamic_cast<engine::DirectionCommand*>(cmd->get(engine::VIEW_CATEGORY));
            out["Direction"] = dcmd->getDirection();
        }

        if(cmd->get(engine::MOVE_CATEGORY))
        {
            engine::MoveCommand* move = dynamic_cast<engine::MoveCommand*>(cmd->get(engine::MOVE_CATEGORY));            
            out["Xmove"] = move->getXmove();
            out["Ymove"] = move->getYmove();
        }
        if(cmd->get(engine::SHOT_CATEGORY))//Shot command
        {
            engine::ShotCommand* shot = dynamic_cast<engine::ShotCommand*>(cmd->get(engine::SHOT_CATEGORY));
            out["PowerShot"] = shot->getPower();
        }   

        if(cmd->get(engine::MODE_CATEGORY))
        {

            engine::ModeCommand* modeCmd = dynamic_cast<engine::ModeCommand*>(cmd->get(engine::MODE_CATEGORY));//on change le mode mais conserve la liste en attente
            out["Mode"] =  modeCmd->getMode();
        }

        user->take_command_from[characterAsked] = true; //enregistrement de l'envoi, on pourra réécrire par dessus

        return HttpStatus::OK;
    }

    HttpStatus GameServer::post (const Json::Value& in, int characterSender) {//<<<  mettre des  mutex

    //coté serveur, in sont les donnnées associé au POST reçu

        const User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

        if(engine->getCharTurn()!=characterSender)//Verif est ce que c'est son tour (Normalemement impossible, il faut qu'il joue lui même deux fois de suite et pour ça modif son engine....)
            throw ServiceException(HttpStatus::BAD_REQUEST,"Character sender is not the character waited");
    //        unique_ptr<User> usermod (new User(*user));
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Verif Est ce que l'autre joueur a prit les commandes ? (un tour de retard ?) Si non -> return HttpStatus::SERVICE_UNAVAILABLE

            
            int other = characterSender ? 0:1;
            const User* userOther = userDB.getUser(other);
        if(!userOther->take_command_from[characterSender])
                    throw ServiceException(HttpStatus::SERVICE_UNAVAILABLE,"Other player didn't take the previous command");

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Partie lecture des données et conversion vers la liste de commande correspondante
        //Json::Value jsonIn;
        
        
        int player = in["character"].asInt();
        
        if(in["Xmove"].asInt())
            commandSaved[0]->add(new engine::MoveCommand(player,in["Xmove"].asInt(),in["Ymove"].asInt()));
            //engine.addCommand(new engine::MoveCommand(player,in["Xmove"].asInt(),in["Ymove"].asInt()));
        
   /*     if(jsonIn["Direction"].asInt())//
            engine.addCommand(new engine::DirectionCommand(player,jsonIn["Direction"].asInt()));
        */
        if(in["PowerShot"].asInt())
            commandSaved[0]->add(new engine::ShotCommand(player,in["PowerShot"].asInt()));
            //engine.addCommand(new engine::ShotCommand(player,in["PowerShot"].asInt()));
        
   /*     if(jsonIn["Mode"].asInt())
            engine.addCommand(new engine::ModeCommand(jsonIn["Mode"].asInt()));
    */       
        
        printf("end post\n");
        return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
    }

    //<<<<<<<<<<<<< done
    /*
    HttpStatus GameServer::put (Json::Value& out,const Json::Value& in) {
    //modif des commandes -> pas utilisé, à viré
        string name = in["name"].asString();
        int age = in["age"].asInt();
        out["id"] = userDB.addUser(make_unique<User>(name,age));
        return HttpStatus::CREATED;
    }
    */

    //<<<<<<<<<<<<<< done
    /* HttpStatus GameServer::remove (int characterSender) {
    // delete l'utilisateur
        const User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        userDB.removeUser(id);
        return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
    }
              */

}