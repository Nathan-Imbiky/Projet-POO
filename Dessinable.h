#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include "PointMateriel.h"
#include "Systemes.h"
#include <iostream>


class Dessinable
{
public:
   virtual void dessine_sur(SupportADessin& support)
   { 
    support.dessine(*this); 
   }
   virtual ~Dessinable() = default;
};



