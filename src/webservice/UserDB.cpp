/** 
 * @file UserDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserDB.hpp"

UserDB::UserDB() : idseq(1) {
    
}

const User* UserDB::getUser (int id) const {// récupéré un user
    auto ite = users.find(id);//auto parce que ite est un iterator donc type degueulasse)
    if (ite == users.cend())//users.cend() => hors du tableau (cend() est un iterator pour les std::map representant la fin)
        return nullptr;
    return ite->second.get();//ite->first est le numero associé à l'user dans le std::map
}

int UserDB::addUser (unique_ptr<User> user) {// ajouter un utilisateur
    int id = idseq++;
    users.insert(std::make_pair(id,std::move(user)));
    return id;
}

void UserDB::setUser (int id, unique_ptr<User> user) {//changer un utilisateur (s'il son numero n'existe pas il sera rajouter)
    users[id] = std::move(user);
    if (id > idseq) {
        idseq = id;
    }
}

void UserDB::removeUser (int id) {
    auto ite = users.find(id);
    if (ite == users.end())
        return;
    users.erase(ite);
}


