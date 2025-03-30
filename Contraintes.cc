#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "ObjetPhysique.h"
#include <iostream>


Vecteur Libre :: applique_force()
{
     if(masse==0)
     {
          return force;
     }else{
          return force/masse;
     }

};

Vecteur Libre :: position( const ObjetPhysique& Ob)
{
     return Ob.etat(*this);
};

Vecteur Libre :: vitesse( const ObjetPhysique& Ob)
{
     return Ob.derivee(*this);

};
