#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include <iostream>

class PointMateriel;

class GravitationConstante : public ChampForces
{
public:
     GravitationConstante()
     : gravitation (g)
     {}
     GravitationConstante(Vecteur Gravitation)
     : gravitation(Gravitation)
     {}
	Vecteur force(const ObjetPhysique& PM, double temps ) const override;
	Vecteur getGr() const {return gravitation;}
	void setGr ( Vecteur Gr){gravitation=Gr ;}
private:
	Vecteur gravitation;
};


class PointMateriel: public ObjetPhysique
{
public:
     PointMateriel(Vecteur P={0, 0, 0}, Vecteur V={0, 0, 0}, double m=0, ChampForces* Gr=new GravitationConstante())
     : ObjetPhysique(P, V, m, Gr)
     {}
     ~PointMateriel()
     {
		delete champ;
		champ = nullptr;
	 }
	 
	 Vecteur evolution(double t) const override;
	 
	 std::ostream& afficher(std::ostream& out) const override;
    
};



