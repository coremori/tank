// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include "state.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    // Operations
  public:
    Element ();
    virtual ~Element ();
    virtual TypeId const getTypeId () = 0;
    virtual bool const isStatic () = 0;
    int const getX ();
    int const getY ();
    void setX (int x);
    void setY (int y);
  };

};

#endif
