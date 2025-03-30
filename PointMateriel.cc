#include <iostream>
#include "PointMateriel.h"
#include "Vecteurs.h"
using namespace std;

Vecteur PointMateriel :: position() const
{
	return VecteurPosition;
};

Vecteur PointMateriel :: vitesse() const
{
	return VecteurVitesse;
};

Vecteur GravitationConstante :: force(const PointMateriel& PM, double temps ) const
{
	if(PM.getMasse()==0)
	{
		cout<<"masse nulle le calul ne peut être effectue"<<endl;
	}else{
		return PM.getMasse()*gravitation;
	}

};

Vecteur PointMateriel :: evolution(double t)
{
	return G.getGr()/masse;
};

ostream& operator<<(ostream& out, PointMateriel const& pnt)
{
	out << pnt.getMasse() << " # masse" << endl;
    out << pnt.getPosition() << " # position" << endl;
    out << pnt.getVitesse() << " # vitesse" << endl;
    return out;
};


