/**
 * \file ElementFactory.cpp
 * \brief Factory for create element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Give methode to create element for ElementManager
 *
 */

#include "ElementFactory.h"
#include "ElementBase.h"
#include "ElementGraphic.h"
#include "ElementLiving.h"
#include "ElementMobile.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "trace.h"

ElementFactory::ElementFactory()
{

}


///////////////////////////////////////////////////////////////////////
/// \fn createElementSub
/// \brief make a new instance of Element which symbol is str, and stock it in f_design
/// \param str : symbol of the element
/// \return false if the symbol don't exist, true otherwise.
/////////////////////////////////////////////////////////////////////////
bool ElementFactory::createElementSub(std::string str)
{
    std::string CONFIG_MAP("C:\\Users\\coren\\Documents\\tank\\tank\\res\\configmap");
    std::ifstream configfile(CONFIG_MAP);

    int std_id = -1, life = -1, defense =-1, direction =-1, movetype=-1, x=-1, y=-1;
    bool crossable;
    std::string name;
    char s;
    ElementBase *newElement(nullptr);
    std::string line;
    Move_Type MoveTypeEnum;

    if(configfile.is_open()){

        while (getline(configfile,line,' '))
        {
            // If it's the symbole we want
            if (line == str)
            {
                getline(configfile,line,' ');

                // we check the object type
                // 'b' for ElementBase
                if (line == "b")
                {
                    // We get the default id (used for ElementBase)
                  getline(configfile,line,' ');
                  std_id = std::stol(line);

                  // we get canbeCrossed information
                  getline(configfile,line,' ');
                  crossable = std::stol(line);

                  // and we get the element name
                  getline(configfile,line,' ');
                  name = line;

                  // we create our element
                  newElement = new ElementBase( std_id, crossable, name);
                }
                else if (line == "l") // 'l' for ElementLiving
                {
                    // we get element life
                    getline(configfile,line,' ');
                    life = std::stol(line);

                    // we get element defense
                    getline(configfile,line,' ');
                    defense = std::stol(line);

                    // We get the default id (used for ElementBase)
                  getline(configfile,line,' ');
                  std_id = std::stol(line);

                  // we get canbeCrossed information
                  getline(configfile,line,' ');
                  crossable = std::stol(line);

                  // and we get the element name
                  getline(configfile,line,' ');
                  name = line;

                  //we create our element
                  newElement = new ElementLiving( life, defense, std_id, crossable, name);

                }
                else if (line == "m") // 'm' for ElementMobile
                {
                    // we get default x position
                    getline(configfile,line,' ');
                    x = std::stol(line);

                    // we get default y position
                    getline(configfile,line,' ');
                    y = std::stol(line);

                    // We get the direction
                    getline(configfile,line,' ');
                    direction = std::stol(line);

                    // we get the move_type information
                    getline(configfile,line,' ');
                    movetype = std::stol(line);

                    MoveTypeEnum = static_cast<Move_Type>(movetype);

                    // we get element life
                    getline(configfile,line,' ');
                    life = std::stol(line);

                    // we get element defense
                    getline(configfile,line,' ');
                    defense = std::stol(line);

                    // We get the default id (used for ElementBase)
                    getline(configfile,line,' ');
                    std_id = std::stol(line);

                    // we get canbeCrossed information
                    getline(configfile,line,' ');
                    crossable = std::stol(line);

                    // and we get the element name
                    getline(configfile,line,' ');
                    name = line;

                  //we create our element
                  newElement = new ElementMobile(x, y, direction, MoveTypeEnum, life, defense, std_id, crossable, name);

                }
                else
                {
                    TRACE(" Invalid Element type ; \"%s\" seem bad", CONFIG_MAP.data());
                    configfile.close();
                    return false;
                }

                // Graphical go here


                //After that, we save it :)
                f_design[str] = newElement;
                // job done
                configfile.close();
                return true;
            }
            else
                //if it is not the str we want, we go next line
                configfile.ignore();
            getline(configfile,line);
        }
        configfile.close();
    }
    else
    {
        TRACE(" Could not open config file \"%s\"", CONFIG_MAP.data());
        return false;
    }


   return true;
}

///////////////////////////////////////////////////////////////////////
/// \fn giveElementFromSymbol
/// \brief return a instance of Element which symbol is str
/// \param str : symbol of the element
/// \return nullptr if it couldn't create the element, a instance otherwise. Note that the Element need to by duplicated if we want to change it.
/////////////////////////////////////////////////////////////////////////
ElementBase* ElementFactory::giveElementFromSymbol(std::string str)
{
    // Chek if we already create it
    if(f_design.find(str) == f_design.end())
    {
        if (this->createElementSub(str) == false)
        {
            // if we couldn't create it, we return nullptr
            return nullptr;
        }
    }
    //we return a element
     return f_design[str];
}
