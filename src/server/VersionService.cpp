/** 
 * @file VersionService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "VersionService.h"

VersionService::VersionService () : AbstractService("/version") {
    
}

HttpStatus VersionService::get (Json::Value& out, int characterSender) const {
//renvoie la version du serveur
//pas utile mais bon elle est déjà codé
    out["major"] = 1;
    out["minor"] = 0;
    return HttpStatus::OK;
}
