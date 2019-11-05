#include "WorldManager.h"

#define NB_PIXEL_BY_ELEMENT


WorldManager::WorldManager (int width, int height):
f_Width(width),
f_Height(height)
{

}

WorldManager::~WorldManager ()
{
	this->clear();
}

ElementBase* WorldManager::getCell ( int posX, int posY) const
{
	// Si l'élèment existe bien
    if ((posX < width) && (posY < height)
    	&& (0 <= posX) && (0 <= posY))
    	return ElementList::elements[(posX * width + posY) / NB_PIXEL_BY_ELEMENT];
    else 
    	return nullptr;
}

ElementBase* WorldManager::getElementByID (int id)
{

}

ElementBase* WorldManager::getElementByName (std::string name)
{

}

int WorldManager::getWidth () const
{

}

int WorldManager::getHeight () const
{

}

bool WorldManager::canMoveHere (int posX, int posY) const
{

}

void WorldManager::clear ()
{

}

void WorldManager::load (std::string path)
{

}