#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include <iostream>

class ObjetPhysique: public Objetmobile
{
public:
     Vecteur force(double t = 0) const ;
     Vecteur position( const Contrainte& ct) const;
     Vecteur vitesse( const Contrainte& ct) const;
private:
     unsigned int dimension;
};

