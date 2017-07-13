/**
 * \file ElementManager.h
 * \brief Class for manage element
 * \author Coremori
 * \version 0.1
 * \date 08 july 2017
 *
 * Manage the different element (stock the game world)
 *
 */


#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#include <vector>
#include <string>

#include "ElementBase.h"
#include "ElementFactory.h"
#include "GlobalState.h"

class ElementManager
{
public:
    ElementManager(int height, int width);

    ~ElementManager();
    ///////////////////////////////////////////////////////////////////////
    /// \brief getCell
    /// \param i : position x of the element
    /// \param j : position y of the element
    /// \return ElementBase* at the position (i,j)
    /////////////////////////////////////////////////////////////////////////
    ElementBase* getCell(int i, int j);


    ///////////////////////////////////////////////////////////////////////
    /// \brief getElementByID
    /// \param id : id of the element wanted
    /// \return ElementBase* who's id is id
    /////////////////////////////////////////////////////////////////////////
    ElementBase* getElementByID(int id);


    ///////////////////////////////////////////////////////////////////////
    /// \brief getElementByName
    /// \param name : name of the element
    /// \return ElementBase* who's name is name
    /////////////////////////////////////////////////////////////////////////
    ElementBase* getElementByName(std::string name);


    ///////////////////////////////////////////////////////////////////////
    /// \brief canMoveHere
    /// \param i : position x of the element
    /// \param j : position y of the element
    /// \return true if the element at (i,j) is crossable, false otherwise
    /////////////////////////////////////////////////////////////////////////
    bool canMoveHere( int i, int j) const;

    ///////////////////////////////////////////////////////////////////////
    /// \brief getWidth
    /// \return Width
    /////////////////////////////////////////////////////////////////////////
    int getWidth() const;

    ///////////////////////////////////////////////////////////////////////
    /// \brief getHeight
    /// \return height
    /////////////////////////////////////////////////////////////////////////
    int getHeight() const;


    ///////////////////////////////////////////////////////////////////////
    /// \brief takeDamage
    /// \param power damage done to the life
    /// \param ignoreDefense if true, the defense is ignored
    /// \return void
    /////////////////////////////////////////////////////////////////////////
    bool loadFile(std::string filename);


    ///////////////////////////////////////////////////////////////////////
    /// \brief takeDamage
    /// \param power damage done to the life
    /// \param ignoreDefense if true, the defense is ignored
    /// \return void
    /////////////////////////////////////////////////////////////////////////
    void clear();

//    void notifyObserver(const StateEvent* event);


public:
    GlobalState p_worldInfo;
private:
    int f_width;
    int f_height;
    std::vector<ElementBase*> f_world;
    ElementFactory* Factorio;
};

#endif // ELEMENTMANAGER_H
