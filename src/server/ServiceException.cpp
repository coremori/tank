/** 
 * @file ServiceException.cpp
 * @author Corentin Morisse
 * @date 9 décembre 2015
 */

#include "ServiceException.hpp"
#include <stdexcept>
//Gere les exceptions

namespace server {
    ServiceException::ServiceException (HttpStatus status, std::string msg) 
        : httpStatus(status),msg(msg) {    
    }

    HttpStatus ServiceException::status () const {// Type d'exception
        return httpStatus;
    }

    const char* ServiceException::what () const noexcept {//noexcept == ne renvoie pas d'exception
        return msg.c_str();//rajoute '\0' à la fin
    }

}