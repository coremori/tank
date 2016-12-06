/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"

UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {
    
}

HttpStatus UserService::get (Json::Value& out, int characterSender, int characterAsked) const {

//coté serveur, out sont les donnnées associé au GET à renvoyer
    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe

    const User* userAsked = userDB.getUser(characterAsked);
    if (!userAsked)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe (joueur dont on veut récupérer les commandes

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< partie remplissage du formulaire out suivant le schéma de donnée 1 (NOT DONE)
    out["name"] = user->name;
    out["age"] = user->age;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Partie enregistrement de l'envoi (NOT DONE)
    return HttpStatus::OK;
}

HttpStatus UserService::post (const Json::Value& in, int characterSender) {

//coté serveur, in sont les donnnées associé au POST reçu

    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");// on regarde si le joueur existe


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Verif est ce que c'est son tour ? non -> return HttpStatus::BAD_REQUEST (Normalemement impossible, il faut qu'il joue lui même deux fois de suite et pour ça modif son engine....)
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

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
//modif des commandes -> pas utilisé, à viré
    string name = in["name"].asString();
    int age = in["age"].asInt();
    out["id"] = userDB.addUser(make_unique<User>(name,age));
    return HttpStatus::CREATED;
}

HttpStatus UserService::remove (int characterSender) {
// delete l'utilisateur
    const User* user = userDB.getUser(characterSender);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    userDB.removeUser(id);
    return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
}

