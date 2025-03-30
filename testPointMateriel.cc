#include "Constantes.h"
#include "PointMateriel.h"
#include <iostream>
using namespace std;

int main()
{
	GravitationConstante ChampGravitation;
	ChampGravitation.setGr(g);
	
	cout<<"Nous avons :"<<endl;
	cout<<"un champ de force :"<< ChampGravitation.getGr()<<endl;
	cout<<endl;
	
	PointMateriel M1;
	PointMateriel M2;
	
	M1.setMasse(0.1);
	M1.setPosition(Vecteur(1,2,3));
	M1.setVitesse(Vecteur(0,0.1,0.2));
	
	M2.setMasse(2);
	M2.setPosition(Vecteur(-1.1,1.2,1.3));
	M2.setVitesse(Vecteur(0.2,0.1,0));
	
	Vecteur P1 = ChampGravitation.force(M1,0);
	Vecteur P2 = ChampGravitation.force(M2,0);
	
	cout<<"un point matériel : " << endl;
	cout<< M1<<P1 <<" #forces "<<endl;
	cout<<endl;
	cout<<"et un autre point matériel : " << endl;
	cout<<M2<<P2<<" #forces "<<endl;
	
	return 0;
}
