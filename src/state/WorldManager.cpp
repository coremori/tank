#include "WorldManager.h"

#define NB_PIXEL_BY_ELEMENT   8
namespace state {

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
    if ((posX < f_Width) && (posY < f_Height)
    	&& (0 <= posX) && (0 <= posY))
    	return f_ElementList[(posX * f_Width + posY) / NB_PIXEL_BY_ELEMENT];
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
}