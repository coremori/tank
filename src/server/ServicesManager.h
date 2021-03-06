// Generated by dia2code
#ifndef SERVER__SERVICESMANAGER__H
#define SERVER__SERVICESMANAGER__H

#include <string>

namespace server {
  class AbstractService;
}

#include "AbstractService.h"
#include "HttpStatus.h"

namespace server {

  /// class ServicesManager - 
  class ServicesManager {
    // Associations
    // Attributes
  protected:
    vector<unique_ptr<AbstractService> > services;
    // Operations
  public:
    void registerService (unique_ptr<AbstractService> service);
    AbstractService* findService (const std::string& url) const;
    HttpStatus queryService (std::string& out, const std::string& in, const std::string& url, const std::string& method);
  };

};

#endif
