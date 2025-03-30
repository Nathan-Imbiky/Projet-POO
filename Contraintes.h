#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>

class Contrainte: 
{
public:
     virtual Vecteur applique_force(const ObjetPhysique& ob, Vecteur Force, double t) const=0;
     virtual Vecteur position(const ObjetPhysique& ob) const=0;
     virtual Vecteur vitesse(const ObjetPhysique& ob) const =0;
};


class Libre: public Contrainte
{
public:
     Vecteur applique_force();
     Vecteur position(const ObjetPhysique& Ob);
     Vecteur vitesse(const ObjetPhysique& Ob);
};

