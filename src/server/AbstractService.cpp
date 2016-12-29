/** 
 * @file AbstractService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "AbstractService.hpp"

namespace server{

    AbstractService::AbstractService (const std::string& pattern) {//patern == url ici (interne au serveur)
        setPattern(pattern);
    }

    AbstractService::~AbstractService() {

    }

    const std::string& AbstractService::getPattern () const {
        return pattern;
    }

    void AbstractService::setPattern (const std::string& pattern) {
        this->pattern = pattern;
    }

    //toutes les méthodes suivante sont virtuelle et ne sont défini ici que pour permettre une réutilisation facile de la classe : Elle gére tout les types de requete basique (post,put,get et delete) de la manière la plus simple : je repond non implémenté pour toutes, et j'ai pas à les définir dans les classes filles

    HttpStatus AbstractService::get (Json::Value& out, int characterSender, int characterAsked) const {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::post (const Json::Value& in, int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::put (Json::Value& out, const Json::Value& in) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

    HttpStatus AbstractService::remove (int id) {
        throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    }

}