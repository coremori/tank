// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include "State.h"

namespace State {

  /// class Element - 
  class Element {
    // Associations
    State::TypeId typeid;
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
    virtual Element const clone () = 0;
    virtual bool const equals (const Element& other);
    int const getX ();
    int const getY ();
    void setX (int x);
    void setY (int y);
  };

};

#endif
