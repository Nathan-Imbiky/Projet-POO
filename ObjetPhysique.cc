#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>
using namespace std;


Vecteur ObjetPhysique :: force(double t) const
{
	return champ->force(*this, t);
}

    
Vecteur ObjetPhysique:: position(const Contrainte& ct) const
{
     return ct.position(*this);

}

Vecteur ObjetPhysique:: vitesse(const Contrainte& ct) const
{
     return ct.vitesse(*this);

}
