#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "Objetmobile.h"
#include "ChampsForces.h"
#include <iostream>

class Contrainte;

class ObjetPhysique: public ObjetMobile
{	
public:
	ObjetPhysique(Vecteur v1, Vecteur v2={0, 0, 0})
	: ObjetMobile(v1, v2)
	{
		dimension = v1.size();
	}

     Vecteur force(double t = 0) const ;
     Vecteur position( const Contrainte& ct) const;
     Vecteur vitesse( const Contrainte& ct) const;
     
     double get_masse() const {return masse;} 
     
private:
     size_t dimension;
     ChampForces* champ;
     double masse;
     
};

