#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "Contraintes.h"
#include "Objetmobile.h"
#include "ChampsForces.h"
#include <iostream>
#include <vector>
#include <memory>


class ChampForces;
class Contrainte;


class ObjetPhysique: public ObjetMobile
{	
public:
	ObjetPhysique(Vecteur v1, Vecteur v2, double m, ChampForces const& C, Contrainte const& Ctr)
	: ObjetMobile(v1, v2), masse(m)
	{
		set_champ(C);
		set_contraintes(Ctr);
		dimension = v1.size();
	}
	ObjetPhysique(Vecteur v1={0, 0, 0}, Vecteur v2={0, 0, 0}, double m=0)
	: ObjetMobile(v1, v2), masse(m)
	{
		dimension = v1.size();
		champ=std::unique_ptr<ChampForces>(new ForceNulle);
		contraintes=std::unique_ptr<Contrainte>(new Libre);
	}
	ObjetPhysique(ObjetPhysique const& O)
	: ObjetMobile(O)
	{
		masse = O.masse;
		dimension = O.dimension;
		
		ChampForces& C(*O.champ);
		Contrainte& Ctr(*O.contraintes);
		
		set_champ(C);
		set_contraintes(Ctr);
	}
	
	ObjetPhysique& operator=(ObjetPhysique const& O);
	//constructeur de copie ? opérateur = ?


     Vecteur force(double t = 0) const ;
     Vecteur position() const;
     Vecteur vitesse() const;
     
     double get_masse() const {return masse;} 
     ChampForces& get_champ() const {return *champ;}
     Contrainte& get_contraintes() const {return *contraintes;}
     void set_masse(double M) {masse=M;}
     void set_champ(ChampForces const& C) { champ = C.copie();}
     void set_contraintes(Contrainte const& ctr);
     
     
protected:
     size_t dimension;
     double masse;
     std::unique_ptr<ChampForces> champ;
     std::unique_ptr<Contrainte> contraintes;
};



