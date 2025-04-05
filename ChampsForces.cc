#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>
using namespace std;


Vecteur ForceCentrale::quadratique_inverse(ObjetPhysique const& ob) const
{
	double d((ob.get_etat() - centre.get_etat()).norme());
	if(d<0.001)
	{
		Vecteur v(ob.get_etat().size());
		return v;
	}
	else
	{
		Vecteur v2(~(centre.get_etat() - ob.get_etat()));
		return v2/(d*d);
	}
}

Vecteur ChampNewtonien::force(const ObjetPhysique& PM, double temps) const
{
	return G*centre.get_masse()*PM.get_masse()*quadratique_inverse(PM);
}

Vecteur ForceNulle::force(const ObjetPhysique& PM, double temps) const
{
	return 0*PM.get_etat();
}

ostream& ForceCentrale::afficher(ostream& out) const
{
	out<<"champ newtonien, centre : "<<centre.get_etat()<<", masse : "<<centre.get_masse();
	return out;
}
