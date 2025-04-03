#include "Vecteurs.h"
#include "Constantes.h"
#include "Objetmobile.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include "PointMateriel.h"
#include "Contraintes.h"
#include <iostream>
using namespace std;

int main()
{
	GravitationConstante ChampGravitation;
	Libre cl;
	GravitationConstante gr(g);
	
	cout<<"Nous avons :"<<endl;
	cout<<"un champ de force :"<< ChampGravitation.getGr()<<endl;
	cout<<endl;
	
	PointMateriel M1({1.0, 2.0, 3.0}, {0, 0.1, 0.2}, 0.1, ChampGravitation, cl);
	PointMateriel M2({-1.1, 1.2, 1.8}, {0.2, 0.1, 5}, 0, gr, cl);
	
	M1.set_masse(0.1);
	M1.set_etat(Vecteur(1,2,3));
	M1.set_derivee(Vecteur(0,0.1,0.2));
	
	M2.set_masse(2);
	M2.set_etat(Vecteur(-1.1,1.2,1.3));
	M2.set_derivee(Vecteur(0.2,0.1,0));
	
	Vecteur P1 = ChampGravitation.force(M1,0);
	Vecteur P2 = ChampGravitation.force(M2,0);
	
	cout<<"un point materiel : " << endl;
	cout<<M1<<P1<<" #force "<<endl;
	cout<<endl;
	cout<<"et un autre point materiel : " << endl;
	cout<<M2<<P2<<" #force "<<endl;
	
	
	return 0;
}
