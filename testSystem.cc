#include "Systemes.h"
#include "Integrateur.h"
#include "Contraintes.h"
#include "ChampsForces.h"
#include "PointMateriel.h"
#include "Vecteurs.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	Systeme S1;
	
	PointMateriel origine({0, 0, 0}, {0, 0, 0}, 1);
	PointMateriel test({7.0, -2, 5}, {-0.1, 6, 1.0}, 45);
	
	IntegrateurEulerCromer I;
	
	ChampNewtonien Poids(origine);
	ChampNewtonien Poids2(test);
	GravitationConstante mars({0.0, 0.0, -3.711});
	
	Libre cl, cl2;
	
	Systeme S2(test, Poids, cl, I);
	Systeme S3(test, Poids, cl, 7);
	S3.ajoute_force(mars);
	S2.ajoute_objet(origine);
	S3.ajoute_contrainte(cl2);
	
	cout<<"Premier systeme : "<<endl;
	cout<<S1<<endl;
	
	cout<<"Second systeme : "<<endl;
	cout<<S2<<endl;
	
	cout<<"Troisieme systeme : "<<endl;
	cout<<S3<<endl;
	
	S1.ajoute_force(mars);
	S1.ajoute_force(Poids2);
	S1.ajoute_objet(test);
	S1.ajoute_objet(origine);
	S1.ajoute_contrainte(cl2);
	
	S1.set_champ_objet(0, 1);
	S1.set_contrainte_objet(1, 0);
	S1.set_champ_objet(1, 0);
	
	cout<<"Premier systeme mis a jour :"<<endl;
	cout<<S1<<endl;
	
	//Nous testerons la methode de changement d'integrateur lorsqu'il y aura plus de sous classes
	
	return 0;
}
