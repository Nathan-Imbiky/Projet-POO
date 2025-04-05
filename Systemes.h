#include "ObjetPhysique.h"
#include "Integrateur.h"
#include "Contraintes.h"
#include "ChampsForces.h"
#include <iostream>
#include <vector>
#include <memory>

class Systeme
{
	private:
	double temps;
	std::unique_ptr<Integrateur> integrateur;
	std::vector<std::unique_ptr<ObjetPhysique>> objets;
	std::vector<std::unique_ptr<Contrainte>> contraintes;
	std::vector<std::unique_ptr<ChampForces>> champs;
	
	
	public:
	Systeme()
	: temps(0), integrateur(new IntegrateurEulerCromer)
	{}
	Systeme(ObjetPhysique const& O, ChampForces const& F, Contrainte const& Ctr, Integrateur const& I, double t=0)
	: temps(t)
	{
		objets.push_back(O.copie());
		champs.push_back(F.copie());
		contraintes.push_back(Ctr.copie());
		integrateur = I.copie();
	}
	
	Systeme(ObjetPhysique const& O, ChampForces const& F, Contrainte const& Ctr, double t=0)
	: temps(t), integrateur(new IntegrateurEulerCromer)
	{
		objets.push_back(O.copie());
		champs.push_back(F.copie());
		contraintes.push_back(Ctr.copie());
	}
	
	Systeme(std::vector<std::unique_ptr<ObjetPhysique>> const& VO, std::vector<std::unique_ptr<ChampForces>> const& VF, std::vector<std::unique_ptr<Contrainte>> const& VCtr, Integrateur const& I, double t=0)
	: temps(t)
	{
		for(auto& O : VO)
		{
			objets.push_back(O->copie());
		}
		for(auto& F : VF)
		{
			champs.push_back(F->copie());
		}
		for(auto& C : VCtr)
		{
			contraintes.push_back(C->copie());
		}
		integrateur = I.copie();
	}
	
	Systeme(std::vector<std::unique_ptr<ObjetPhysique>> const& VO, std::vector<std::unique_ptr<ChampForces>> const& VF, std::vector<std::unique_ptr<Contrainte>> const& VCtr, double t=0)
	: temps(t), integrateur(new IntegrateurEulerCromer)
	{
		for(auto& O : VO)
		{
			objets.push_back(O->copie());
		}
		for(auto& F : VF)
		{
			champs.push_back(F->copie());
		}
		for(auto& C : VCtr)
		{
			contraintes.push_back(C->copie());
		}
	}
	
	
	void ajoute_contrainte(Contrainte const& C);
	void ajoute_force(ChampForces const& F);
	void ajoute_objet(ObjetPhysique const& O);
	void remplace_integrateur(Integrateur const& I);
	
	void set_contrainte_objet(size_t i, size_t j);
	void set_champ_objet(size_t i, size_t j);
	
	std::ostream& afficher(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, Systeme const& S);
