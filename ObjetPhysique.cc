#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <memory>
#include <iostream>
using namespace std;


Vecteur ObjetPhysique :: force(double t) const
{	
	return champ->force(*this, t);
}
ObjetPhysique::ObjetPhysique(Vecteur v1, Vecteur v2, double m)
: ObjetMobile(v1, v2), masse(m)
	{
		dimension = v1.size();
		champ=std::unique_ptr<ChampForces>(new ForceNulle);
		contraintes=std::unique_ptr<Contrainte>(new Libre);
	}
    
Vecteur ObjetPhysique:: position() const
{
     return contraintes->position(*this);

}

Vecteur ObjetPhysique:: vitesse() const
{
     return contraintes->vitesse(*this);

}

void ObjetPhysique::set_contraintes(Contrainte const& ctr) 
{ 
	contraintes = ctr.copie();
}

ObjetPhysique& ObjetPhysique::operator=(ObjetPhysique const& O) 
{
		etat = O.etat;
		derivee = O.derivee;
		masse = O.masse;
		dimension = O.dimension;
		
		ChampForces& C(*O.champ);
		Contrainte& Ctr(*O.contraintes);
		
		set_champ(C);
		set_contraintes(Ctr);
		return *this;
}

