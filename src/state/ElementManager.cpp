/**
 * \file ElementManager.cpp
 * \brief Class for manage element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Manage the different element (stock the game world)
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "ElementManager.h"
#include "ElementLiving.h"
#include "ElementMobile.h"
#include "MoveType.h"
#include "trace.h"

ElementManager::ElementManager(int height, int width):
    f_width(width),
    f_height(height),
    Factorio(new ElementFactory())
{

}


ElementManager::~ElementManager()
{
    if (Factorio != nullptr) delete(Factorio);
}

///////////////////////////////////////////////////////////////////////
/// \brief getCell
/// \param i : position x of the element
/// \param j : position y of the element
/// \return ElementBase* at the position (i,j)
/////////////////////////////////////////////////////////////////////////
ElementBase* ElementManager::getCell(int i, int j)
{
    if ((i > f_width) || (j > f_height) || (i < 0) || (j < 0 ) )
    {
        std::cout << "Error : Invalid coordonner, i=" << i << " j=" << j << "\n";
        return nullptr;
    }

    return f_world[i * f_width + j];
}


///////////////////////////////////////////////////////////////////////
/// \brief getElementByID
/// \param id : id of the element wanted
/// \return ElementBase* who's id is id
/////////////////////////////////////////////////////////////////////////
ElementBase* ElementManager::getElementByID(int id)
{
    return nullptr;
}


///////////////////////////////////////////////////////////////////////
/// \brief getElementByName
/// \param name : name of the element
/// \return ElementBase* who's name is name
/////////////////////////////////////////////////////////////////////////
ElementBase* ElementManager::getElementByName(std::string name)
{
    return nullptr;
}


///////////////////////////////////////////////////////////////////////
/// \brief canMoveHere
/// \param i : position x of the element
/// \param j : position y of the element
/// \return true if the element at (i,j) is crossable, false otherwise
/////////////////////////////////////////////////////////////////////////
bool ElementManager::canMoveHere( int i, int j) const
{
    // Check if the cell exist
    if ((i > f_width) || (j > f_height) || (i < 0) || (j < 0 ) )
    {
        return false;
    }

    return f_world[ i * f_width + j]->getCanBeGetAcross();

}

///////////////////////////////////////////////////////////////////////
/// \brief getWidth
/// \return Width
/////////////////////////////////////////////////////////////////////////
int ElementManager::getWidth() const
{
    return f_width;
}

///////////////////////////////////////////////////////////////////////
/// \brief getHeight
/// \return height
/////////////////////////////////////////////////////////////////////////
int ElementManager::getHeight() const
{
    return f_height;
}


///////////////////////////////////////////////////////////////////////
/// \brief takeDamage
/// \param power damage done to the life
/// \param ignoreDefense if true, the defense is ignored
/// \return void
/////////////////////////////////////////////////////////////////////////
bool ElementManager::loadFile(std::string filename)
{
    int NB_STD_HEIGHT_SPRITE(8);

    // delete the currrend world
    this->clear();

    std::string line;
    ElementBase *bric;

    //std::string line;
    std::ifstream mapfile(filename);

    int x=0,y=-NB_STD_HEIGHT_SPRITE;


    if(mapfile.is_open()){

        mapfile >> f_width >> f_height;

        while (getline(mapfile,line))
        {
            x = 0;

             for(unsigned int i = 0; i < line.length(); i++){

                bric = Factorio->giveElementFromSymbol(line.substr(i,1));
                if ( bric == nullptr)
                {
                    TRACE("Unknow element ! ");
                }
                else
                {
                    f_world.push_back(bric);
                }


                x = x+NB_STD_HEIGHT_SPRITE;
            }
            y=y+NB_STD_HEIGHT_SPRITE;

        }
        mapfile.close();
    }
    else
    {
        TRACE("Could not open map \"%s\"", filename.data());
        return false;
    }

    return true;
}


///////////////////////////////////////////////////////////////////////
/// \brief takeDamage
/// \param power damage done to the life
/// \param ignoreDefense if true, the defense is ignored
/// \return void
/////////////////////////////////////////////////////////////////////////
void ElementManager::clear()
{
    f_world.clear();
}
