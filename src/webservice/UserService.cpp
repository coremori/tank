/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @adapted by Corentin Morisse and Pierre-Bernard Le Roux
 * @date 15 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"



//><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<bibliotheque nonincluse  && reste le post


UserService::UserService (UserDB& userDB) : AbstractService("/game"),
    userDB(userDB) {
    
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   recup commande
HttpStatus UserService::get (Json::Value& out, int characterSender, int characterAsked) const {

//coté serveur, out sont les donnnées associé au GET à renvoyer
    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

    const User* userAsked = userDB.getUser(characterAsked);
    if (!userAsked)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe (joueur dont on veut récupérer les commandes

    out["Character"] = characterAsked;
    
    engine::CommandSet* cmd = commandSaved[characterAsked];
    
    if(cmd->get(VIEW_CATEGORY))
    {
        DirectionCommand* dcmd = dynamic_cast<DirectionCommand*>(cmd->get(VIEW_CATEGORY));
        out["Direction"] = dcmd->getDirection();
    }
    
    if(cmd->get(MOVE_CATEGORY))
    {
        MoveCommand* move = dynamic_cast<MoveCommand*>(cmd->get(MOVE_CATEGORY));            
        out["Xmove"] = move->getXmove();
        out["Ymove"] = move->getYmove();
    }
    
    if(cmd->get(SHOT_CATEGORY))//Shot command
    {
        ShotCommand* shot = dynamic_cast<ShotCommand*>(cmd->get(SHOT_CATEGORY));
        out["PowerShot"] = shot->getPower();
    }   
    
    if(cmd->get(MODE_CATEGORY))
    {
            
        ModeCommand* modeCmd = dynamic_cast<ModeCommand*>(waitingcommands->get(MODE_CATEGORY));//on change le mode mais conserve la liste en attente
        out["Mode"] =  setMode(modeCmd->getMode());
    }
            
    user.take_command_from[characterAsked] = true; //enregistrement de l'envoi, on pourra réécrire par dessus
    
    return HttpStatus::OK;
}

HttpStatus UserService::post (const Json::Value& in, int characterSender) {

//coté serveur, in sont les donnnées associé au POST reçu

    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

    if(engine->getCharTurn()!=characterSender)//Verif est ce que c'est son tour (Normalemement impossible, il faut qu'il joue lui même deux fois de suite et pour ça modif son engine....)
        throw ServiceException(HttpStatus::BAD_REQUEST,"Character sender is not the character waited");
        unique_ptr<User> usermod (new User(*user));
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Verif Est ce que l'autre joueur a prit les commandes ? (un tour de retard ?) Si non -> return HttpStatus::SERVICE_UNAVAILABLE
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Partie lecture des données et conversion vers la liste de commande correspondante
    if (in.isMember("name")) {
        usermod->name = in["name"].asString();
    }
    if (in.isMember("age")) {
        usermod->age = in["age"].asInt();
    }
    userDB.setUser(id,std::move(usermod));

    return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
}

//<<<<<<<<<<<<< done
/*
HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
//modif des commandes -> pas utilisé, à viré
    string name = in["name"].asString();
    int age = in["age"].asInt();
    out["id"] = userDB.addUser(make_unique<User>(name,age));
    return HttpStatus::CREATED;
}
*/

//<<<<<<<<<<<<<< done
HttpStatus UserService::remove (int characterSender) {
// delete l'utilisateur
    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
}
          
                
                