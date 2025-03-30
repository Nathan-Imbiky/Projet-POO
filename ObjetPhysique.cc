#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>
using namespace std;


Vecteur ObjetPhysique :: force(double t) const
{
	return Vecteur(0);
}

    
Vecteur ObjetPhysique:: position(const Contrainte& ct) const
{
     return ct.position(*this);

}

Vecteur ObjetPhysique:: vitesse(const Contrainte& ct) const
{
     return ct.vitesse(*this);

}
