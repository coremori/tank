/** 
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServicesManager.hpp"

using namespace std;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {// on enregistre notre premier service (la version)
    services.push_back(std::move(service));
}

AbstractService* ServicesManager::findService (const string& url) const {// l'url existe-t-elle dans nos service ?
    for (auto& service : services) {
        const string& pattern(service->getPattern());
        if (url.find(pattern) != 0)//si l'url est diff de "patern" (url enregistré) on quite cet itération et on commence la suivante
            continue;
        if (url.size() > pattern.size() && url[pattern.size()] != '/')//si on commence par "patern" mais que c'est pas "/" après (type truc/4245) on quite cet itération et on commence la suivante
            continue;
        return service.get();//sinon c'est bon !
    }
    return nullptr;// elle n'existe pas
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    AbstractService* service = findService(url);//on trouve le service voulu
    if (!service)
        throw ServiceException(HttpStatus::NOT_FOUND,"Service "+url+" non trouvé");//s'il existe bien sûr
    // Recherche un éventuel id (ex: /mon/service/<id>)


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< verif de la forme du GET (NOT DONE)(forme attendue: <service>/<nombre>/<nombre> type game/characterSender/characterAsked
    const string& pattern(service->getPattern());
    int id = 0;
    if (url.size() > pattern.size()) {
        string end = url.substr(pattern.size());
        if (end[0] != '/')//double sécurité 
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        end = end.substr(1);
        if (end.empty())// si pas de nombre
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        try {
            size_t pos = 0;
            id = stoi(end,&pos);//string to integer, pos devient = position juste après le dernier chiffre (425de -> pos = 3 (adresse de d))
            if (pos != end.size())//si il ya des caracteres après
                throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
        catch(...) {//Si le programmeur fume de l'héroine en chantant sur son poney
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
    }
    // Traite les différentes méthodes
    if (method == "GET") {
        cerr << "Requête GET " << pattern << " avec id=" << id << endl;
        Json::Value jsonOut;
        HttpStatus status = service->get(jsonOut,id);
        out = jsonOut.toStyledString();//out = renvoie du get (on renvoie de la fonction actuel out et status)
        return status;
    }
    else if (method == "POST") {
        cerr << "Requête POST " << pattern << " avec contenu: " << in << endl;
        Json::Reader jsonReader;
        Json::Value jsonIn;
        if (!jsonReader.parse(in,jsonIn))//parse -> passé du formatage lecture humaine à un formatage html (valable pour JSON,XML...)
            throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
        return service->post(jsonIn,id);
    }
    else if (method == "PUT") {
        cerr << "Requête PUT " << pattern << " avec contenu: " << in << endl;
        Json::Reader jsonReader;
        Json::Value jsonIn;
        if (!jsonReader.parse(in,jsonIn))
            throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
        Json::Value jsonOut;
        HttpStatus status = service->put(jsonOut,jsonIn);
        out = jsonOut.toStyledString();
        return status;
    }
    else if (method == "DELETE") {
        cerr << "Requête DELETE" << endl;
        return service->remove(id);
    }
    throw ServiceException(HttpStatus::BAD_REQUEST,"Méthode "+method+" invalide");
}


