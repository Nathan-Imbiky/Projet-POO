#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>

class ObjetPhysique;

class ChampForces 
{	
	public:     
     virtual Vecteur force(const ObjetPhysique& PM, double temps) const = 0;
     virtual ~ChampForces() = default;
};

class ForceCentrale: public ChampForces //classe generalisant les forces de type central (gravitation, force de coulomb, etc)
{
	protected :
	ObjetPhysique& centre; //le centre attracteur 
	Vecteur quadratique_inverse(ObjetPhysique const& ob) const;
	
	public:
	ForceCentrale(ObjetPhysique& ob)
	: centre(ob)
	{}
};

class ChampNewtonien : public ForceCentrale
{
	public:
	ChampNewtonien(ObjetPhysique& ob)
	: ForceCentrale(ob)
	{}
	
	Vecteur force(const ObjetPhysique& PM, double temps) const override;
};

class ForceNulle : public ChampForces
{
	public:
	Vecteur force(const ObjetPhysique& PM, double temps) const override;
};
