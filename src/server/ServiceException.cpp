/** 
 * @file ServiceException.cpp
 * @author Corentin Morisse
 * @date 9 décembre 2015
 */

#include "ServiceException.h"
#include <stdexcept>
//Gere les exceptions
ServiceException::ServiceException (HttpStatus status, string msg) 
    : httpStatus(status),msg(msg) {    
}

HttpStatus ServiceException::status () const {// Type d'exception
    return httpStatus;
}

const char* ServiceException::what () const noexcept {//noexcept == ne renvoie pas d'exception
    return msg.c_str();//rajoute '\0' à la fin
}
