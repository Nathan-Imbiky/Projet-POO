 #include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "ObjetPhysique.h"
#include <iostream>


Vecteur Libre :: applique_force(const ObjetPhysique& ob, Vecteur force, double t)
{
     if(ob.get_masse()==0)
     {
          return force;
     }else{
          return force/ob.get_masse();
     }

}

Vecteur Libre :: position( const ObjetPhysique& Ob)
{
     return Ob.get_etat();
}

Vecteur Libre :: vitesse( const ObjetPhysique& Ob)
{
     return Ob.get_derivee();

}
