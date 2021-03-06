/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 7, 2016, 3:06 PM
 *
 * Part of tank */


#include "Shell.h"
#include "Tile.h"

namespace render{

    Shell::Shell(int xEnd, bool rightDirection) {//xEnd and bool rightDirection = true if go to the right
        this->xEnd = xEnd;
        this->rightDirection = rightDirection;
        this->countTimeExplosion = 0;
    }
    
    
    bool Shell::setNextTile(Tile* tile) {//return false if the shell is at the target
        
        if(countTimeExplosion == 5)//dure 10 frame
            return false;
        
        if((tile->getX()>=xEnd && rightDirection) || (tile->getX()<=xEnd && !rightDirection))
        {
            
            if(!countTimeExplosion)
            {
                tile->setXTex(8);
                tile->setYTex(112);
            }
            countTimeExplosion ++;
        }
        else
        {
            if(rightDirection)
                tile->setX(tile->getX()+6);
            else
                tile->setX(tile->getX()-6);
        }
        return true;
    }


}
/*press ctrl+space for create function define in .h*/