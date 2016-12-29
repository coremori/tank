/** 
 * @file ServiceException.hpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#ifndef __ServiceException_hpp__
#define __ServiceException_hpp__

#include <stdexcept>
#include <string>

using std::string;

#include "HttpStatus.h"

namespace server {
/// class ServiceException - 
class ServiceException : public std::exception {
  // Associations
  server::HttpStatus httpStatus;
  // Attributes
protected:
  std::string msg;
  // Operations
public:
  ServiceException (HttpStatus status, std::string msg);
  HttpStatus status () const;
  const char* what () const noexcept;
};
}
#endif

