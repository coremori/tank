// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


#include "TypeId.h"

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
    virtual TypeId getTypeId () const = 0;
    virtual bool isStatic () const = 0;
    int getX () const;
    int getY () const;
    void setX (int x);
    void setY (int y);
  };

};

#endif