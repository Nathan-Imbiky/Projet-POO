#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>

class ObjetPhysique;

class ChampForces 
{	
	public:     
     virtual Vecteur force(const ObjetPhysique& PM, double temps) const = 0;
     virtual ~ChampForces() = default;
};
