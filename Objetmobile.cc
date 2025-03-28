#include <vector>
#include "Vecteurs.h"
#include <iostream>
#include "Objetmobile.h"
using namespace std;

ostream& operator<<(ostream& out, ObjetMobile const& o)
{
	o.afficher(out);
	return out;
}


Vecteur ObjetMobile::getparametres() const {return parametres;}
void ObjetMobile::setparametres(Vecteur const& v)
{
	parametres = v;
}
	
Vecteur ObjetMobile::getderivee() const {return derivee;}
void ObjetMobile::setderiveetout(Vecteur const& v)
{
	derivee = v;
}

void ObjetMobile::set_parametre(std::size_t n, double x)
{
	parametres.set_coord(n, x);
}

void ObjetMobile::set_derivee(std::size_t n, double x)
{
	derivee.set_coord(n, x);
}
