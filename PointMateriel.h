#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include <iostream>
#include <memory>

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
	std::unique_ptr<ChampForces> copie() const override {return clonage();}
	std::unique_ptr<GravitationConstante> clonage() const {return std::unique_ptr<GravitationConstante>(new GravitationConstante(*this));}
	std::ostream& afficher(std::ostream& out) const override
	{
		out<<"gravitation constante, acceleration : "<<gravitation;
		return out;
	}
	
	
private:
	Vecteur gravitation;
};


class PointMateriel: public ObjetPhysique
{
public:
     PointMateriel(Vecteur P, Vecteur V, double m, ChampForces const& Gr, Contrainte const& Ctr)
     : ObjetPhysique(P, V, m, Gr, Ctr)
     {}
     PointMateriel(Vecteur P={0, 0, 0}, Vecteur V={0, 0, 0}, double m=0)
     : ObjetPhysique(P, V, m)
     {}
     PointMateriel(PointMateriel const& P)
     : ObjetPhysique(P)
     {}

	 Vecteur evolution(double t) const override;
	 
	 std::ostream& afficher(std::ostream& out) const override;
	 
	 std::unique_ptr<ObjetPhysique> copie() const override {return clonage();}
	 std::unique_ptr<PointMateriel> clonage() const { return std::unique_ptr<PointMateriel>(new PointMateriel(*this));}
	 std::string nom_type() const override {return "Point Materiel";}
    
};



