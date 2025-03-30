#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>

class ChampForces 
{
public:
         
     virtual Vecteur force(const ObjetPhysique& p, double t) const = 0;
     virtual ~ChampForces() = default;
};
