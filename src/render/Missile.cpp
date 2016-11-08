/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 7, 2016, 3:18 PM
 *
 * Part of tank */


#include "Missile.h"
#include "Tile.h"

namespace render{
        
    Missile::Missile(int xEnd, int yEnd, int yCeiling,  bool rightDirection) {//xEnd, yCeiling, bool rightDirection = true si vers la droite
        this->xEnd = xEnd;
        this->yEnd = yEnd;
        this->yCeiling = yCeiling;
        this->rightDirection = rightDirection;
        this->countTimeExplosion = 0;
    }
        
    int Missile::getXEnd() const {
        return xEnd;
    }
    
    int Missile::getYEnd() const {
        return yEnd;
    }
        
    bool Missile::setNextTile(Tile* tile) {
        if(tile->getX()>=xEnd)//vertical d'impact
        {
            if(tile->getY()>=yEnd)
            {
                if(countTimeExplosion == 5)//dure 10 frame
                    return false;
                if(!countTimeExplosion)//Si on est au point d'impact, on explose
                {
                    tile->setXTex(16);
                    tile->setYTex(112);
                }
                countTimeExplosion ++;
            }
            else
            {
                tile->setY(tile->getY()+3);
            }
            
        }
        else if(tile->getY()<=yCeiling)//si on est sur l'horizontal
        {
            if(rightDirection)//si on va à droite
            {
                tile->setX(tile->getX()+3);
            }
            else
            {
                tile->setX(tile->getX()-3);
            }
            
            if(tile->getX()>=xEnd)//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< rightDirection depend!
            {
                tile->setHeight(16);
                tile->setWidth(8);
                tile->setXTex(24);
                tile->setYTex(96);
            }
        }
        else//si on est sur la vertical de tir
        {
            tile->setY(tile->getY()-3);
            if(tile->getY()<=yCeiling)
            {
                tile->setHeight(8);
                tile->setWidth(16);
                if(rightDirection)//ob va a droite
                {
                    tile->setXTex(8);
                    tile->setYTex(96);
                }
                else//on va à gauche
                {
                    tile->setXTex(8);
                    tile->setYTex(104);
                }
            }
        }
        return true;

    }
    
    



}

/*press ctrl+space for create function define in .h*/