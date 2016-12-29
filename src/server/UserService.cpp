/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @adapted by Corentin Morisse and Pierre-Bernard Le Roux
 * @date 15 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"
#include "HttpStatus.h"
#include "User.h"
#include "../extern/jsoncpp-0.10.5/include/json/json.h"



//><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<bibliotheque nonincluse & reste fini

namespace server {

    UserService::UserService (UserDB& userDB) : AbstractService("/user"),
        userDB(userDB) {

    }

    HttpStatus UserService::get (Json::Value& out, int characterSender, int characterAsked) const {


        out["character"] = userDB.addUser();

        return HttpStatus::OK;
    }


    HttpStatus UserService::remove (int characterSender) {
    // delete l'utilisateur
        const User* user = userDB.getUser(characterSender);
        if (!user)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
        userDB.removeUser(characterSender);
        return HttpStatus::NO_CONTENT;//ok & pas de donnée renvoyer
    }
          
                
}             