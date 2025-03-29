#include <vector>
#include "Vecteurs.h"
#include <iostream>
#include "Objetmobile.h"
using namespace std;

ObjetMobile::ObjetMobile(Vecteur v1, Vecteur v2)
: etat(v1), derivee(v2)
	{
		if(etat.size()<derivee.size())
		{
			for(size_t i(0); i<derivee.size() - etat.size(); ++i)
			{
				etat.augmente();
			}
		}
		if(etat.size()>derivee.size())
		{
			for(size_t i(0); i<etat.size() - derivee.size(); ++i)
			{
				derivee.augmente();
			}
		}
	}

ostream& operator<<(ostream& out, ObjetMobile const& o)
{
	o.afficher(out);
	return out;
}


Vecteur ObjetMobile::get_etat() const {return etat;}
void ObjetMobile::set_etat(Vecteur const& v)
{
	etat = v;
}
	
Vecteur ObjetMobile::get_derivee() const {return derivee;}
void ObjetMobile::set_derivee(Vecteur const& v)
{
	derivee = v;
}

void ObjetMobile::set_parametre(std::size_t n, double x)
{
	etat.set_coord(n, x);
}

void ObjetMobile::set_coord_derivee(std::size_t n, double x)
{
	derivee.set_coord(n, x);
}
