#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "Objetmobile.h"
#include "ChampsForces.h"
#include <iostream>

class Contrainte;
class ChampForces;

class ObjetPhysique: public ObjetMobile
{	
public:
	ObjetPhysique(Vecteur v1={0, 0, 0}, Vecteur v2={0, 0, 0}, double m=0, ChampForces* C=nullptr)
	: ObjetMobile(v1, v2), masse(m), champ(C)
	{
		dimension = v1.size();
	}
	//constructeur de copie ? opérateur = ?
	~ObjetPhysique()
	{
		delete champ;
		champ = nullptr;
	}

     Vecteur force(double t = 0) const ;
     Vecteur position( const Contrainte& ct) const;
     Vecteur vitesse( const Contrainte& ct) const;
     
     double get_masse() const {return masse;} 
     void set_masse(double M) {masse=M;}
     
protected:
     size_t dimension;
     double masse;
     ChampForces* champ;

     
};

