/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 7, 2016, 3:01 PM
 *
 * Part of tank */


#include "ProjectileEvent.h"
#include <cstddef>


namespace state{
    

    ProjectileEvent::ProjectileEvent(int xStart, int yStart, int xImpact, int yImpact, bool rightDirection, int yMax) : StateEvent(NULL, Projectile_Event) {
        this->xStart = xStart;
        this->yStart = yStart;
        this->xImpact = xImpact;
        this->yImpact = yImpact;
        this->yMax = yMax;
        this->rightDirection = rightDirection;
    }

    StateEvent* ProjectileEvent::clone() const {
        return new ProjectileEvent(xStart, yStart, xImpact, yImpact, rightDirection , yMax);
    }

}
