/** 
 * @file UserDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserDB.hpp"
#include "User.h"
#include <map>
#include <iostream>


//<<<<<<<<<<<<<<<<<<<<<<< done

namespace server {
    UserDB::UserDB() : idseq(0) {

        unique_ptr<User> usermod (new User());
        usermod->take_command_from[0] = false;
        usermod->take_command_from[1] = true;
        usermod->ai = true;
        users.insert(std::make_pair(0,std::move(usermod)));
        
        unique_ptr<User> usermod2 (new User());
        usermod2->take_command_from[1] = false;
        usermod2->take_command_from[0] = true;
        usermod2->ai = true;
        users.insert(std::make_pair(1,std::move(usermod2)));
    }

    User* UserDB::getUser (int id) const {// récupéré un user
        auto ite = users.find(id);//auto parce que ite est un iterator donc type degueulasse)
        if (ite == users.cend())//users.cend() => hors du tableau (cend() est un iterator pour les std::map representant la fin)
            return nullptr;
        return ite->second.get();//ite->first est le numero associé à l'user dans le std::map
    }

    int UserDB::addUser () {// ajouter un utilisateur
                
        int id = idseq++;
        if(id<2){
            auto ite = users.find(id);
            if (ite == users.end())
                return -1;
            users.erase(ite);

            unique_ptr<User> usermod (new User());
            usermod->take_command_from[id] = false;
            usermod->take_command_from[id ? 0:1] = true;
            usermod->ai = false;
            users.insert(std::make_pair(id,std::move(usermod)));
           
        }
        return id;
    }

    void UserDB::removeUser (int id) {
        auto ite = users.find(id);
        if (ite == users.end())
            return;
       unique_ptr<User> usermod (new User());
        usermod->take_command_from[id] = false;
        usermod->take_command_from[id ? 0:1] = true;
        usermod->ai = true;
        users.insert(std::make_pair(id,std::move(usermod)));
        
    }
}

