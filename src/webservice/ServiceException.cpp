/** 
 * @file ServiceException.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServiceException.hpp"

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
