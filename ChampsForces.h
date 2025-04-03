#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>
#include <memory>

class ObjetPhysique;

class ChampForces 
{	
	public:     
     virtual Vecteur force(const ObjetPhysique& PM, double temps) const = 0;
     virtual ~ChampForces() = default;
     virtual std::unique_ptr<ChampForces> copie() const=0;
};

class ForceCentrale: public ChampForces //classe generalisant les forces de type central (gravitation, force de coulomb, etc)
{
	protected :
	ObjetPhysique& centre; //reference vers le centre attracteur 
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
	std::unique_ptr<ChampForces> copie() const override {return clonage();}
	std::unique_ptr<ChampNewtonien> clonage() const {return std::unique_ptr<ChampNewtonien>(new ChampNewtonien(*this));}
};

class ForceNulle : public ChampForces
{
	public:
	Vecteur force(const ObjetPhysique& PM, double temps) const override;
	std::unique_ptr<ChampForces> copie() const override {return clonage();}
	std::unique_ptr<ForceNulle> clonage() const {return std::unique_ptr<ForceNulle>(new ForceNulle(*this));}
};
