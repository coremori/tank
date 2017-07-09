/**
 * \file ElementFactory.h
 * \brief Factory for create element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Give methode to create element for ElementManager
 *
 */

#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H

#include "ElementBase.h"

#include <map>

class ElementFactory
{
public:
    ElementFactory();

    ///////////////////////////////////////////////////////////////////////
    /// \fn giveElementFromSymbol
    /// \brief return a instance of Element which symbol is str
    /// \param str : symbol of the element
    /// \return nullptr if it couldn't create the element, a instance otherwise. Note that the Element need to by duplicated if we want to change it.
    /////////////////////////////////////////////////////////////////////////
    ElementBase* giveElementFromSymbol(std::string str);

private:
    ///////////////////////////////////////////////////////////////////////
    /// \fn createElementSub
    /// \brief make a new instance of Element which symbol is str, and stock it in f_design
    /// \param str : symbol of the element
    /// \return false if the symbol don't exist, true otherwise.
    /////////////////////////////////////////////////////////////////////////
    bool createElementSub(std::string str);



    /* Variable */
private:
    std::map<std::string, ElementBase*> f_design;
};

#endif // ELEMENTFACTORY_H
