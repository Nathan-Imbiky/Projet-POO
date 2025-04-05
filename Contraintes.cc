#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "ObjetPhysique.h"
#include <iostream>
#include <string>
using namespace std;


Vecteur Libre :: applique_force(const ObjetPhysique& ob, Vecteur force, double t) const
{
     if(ob.get_masse()==0)
     {
          return force;
     }else{
          return force/ob.get_masse();
     }

}

Vecteur Libre :: position( const ObjetPhysique& Ob) const
{
     return Ob.get_etat();
}

Vecteur Libre :: vitesse( const ObjetPhysique& Ob) const
{
     return Ob.get_derivee();

}

unique_ptr<Contrainte> Libre::copie() const
{
	return clonage();
}

unique_ptr<Libre> Libre::clonage() const
{
	return unique_ptr<Libre>(new Libre(*this));
}
