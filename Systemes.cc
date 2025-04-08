#include "ObjetPhysique.h"
#include "Systemes.h"
#include "Integrateur.h"
#include "Contraintes.h"
#include "ChampsForces.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void Systeme::ajoute_contrainte(Contrainte const& C)
{
	contraintes.push_back(C.copie());
}

void Systeme::ajoute_force(ChampForces const& F)
{
	champs.push_back(F.copie());
}

void Systeme::ajoute_objet(ObjetPhysique const& O)
{
	objets.push_back(O.copie());
}

void Systeme::remplace_integrateur(Integrateur const& I)
{
	integrateur=I.copie();
}

ostream& Systeme::afficher(ostream& out) const
{
	out<<"Systeme a t="<<temps<<" :"<<endl;
	out<<endl;
	for(size_t i(0); i<objets.size() ; ++i)
	{
		out<<"Objet no "<<i+1<<" : "<<objets[i]->nom_type()<<" :"<<endl;
		out<<*objets[i];
		out<<"Contrainte : "<<objets[i]->get_contraintes().nom_type()<<endl;
		out<<endl;
	}
	for(size_t i(0); i<champs.size() ; ++i)
	{
		out<<"Champ no "<<i+1<<" : ";
		champs[i]->afficher(out);
		out<<endl;
	}
	
	out<<endl;
	
	for(size_t i(0); i<contraintes.size() ; ++i)
	{
		out<<"Contrainte no "<<i+1<<" : "<<contraintes[i]->nom_type()<<endl;
	}
	return out;
}

void Systeme::set_contrainte_objet(size_t i, size_t j)
{
	if(i<objets.size() && j<contraintes.size())
	{
		objets[i]->set_contraintes(*contraintes[j]);
	}
}

void Systeme::set_champ_objet(size_t i, size_t j)
{
	if(i<objets.size() && j<champs.size())
	{
		objets[i]->set_champ(*champs[j]);
	}
}

ostream& operator<<(ostream& out, Systeme const& S)
{
	S.afficher(out);
	return out;
}


void Systeme::evolue(double dt, unsigned int n)
{
	double t(0);
	for(unsigned int i(1); i<=n; ++i)
	{
		t = temps;
		for(auto& ob : objets)
		{
			integrateur->integre(*ob, t, dt);
			t+=dt;
		}	
	}
	temps+=n*dt;
	
}
