#include <iostream>
#include "PointMateriel.h"
#include "Vecteurs.h"
using namespace std;


Vecteur GravitationConstante :: force(const ObjetPhysique& PM, double temps ) const
{
	if(PM.get_masse()==0)
	{
		cout<<"masse nulle le calul ne peut etre effectue"<<endl; //commentaire ?
		return gravitation;
	}else{
		return PM.get_masse()*gravitation;
	}

}

Vecteur PointMateriel :: evolution(double t) const
{
	return champ->force(*this, t)/masse;
}

/*
ostream& operator<<(ostream& out, PointMateriel const& pnt)
{
	pnt.afficher(out);
    return out;
}
*/


ostream& PointMateriel::afficher(ostream& out) const
{
	out << masse << " # masse" << endl;
    out << etat << " # position" << endl;
    out << derivee << " # vitesse" << endl;
    return out;
}

