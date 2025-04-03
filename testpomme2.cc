#include "Vecteurs.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include "PointMateriel.h"
#include "Integrateur.h"
#include "Contraintes.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	double dt(0.001);
	double t(0);
	PointMateriel terre({0.0, 0.0, -6371*pow(10, 3)}, {0.0, 0.0, 0.0}, 5.972*pow(10, 24)); 
	
	ChampNewtonien Poids(terre);
	Libre cl;
	
	PointMateriel pomme({0.0, 0.0, 10.0}, {0.0, 0.0, 0}, 0.1, Poids, cl);
	

	
	
	IntegrateurEulerCromer I;
	
	ofstream out("pommep2.txt");
	cout<<pomme<<endl;
	cout<<"========="<<endl;
	
	for(unsigned int i(1); i<=14; ++i)
	{
		t+=0.1;
		I.repete_integre(100, pomme, t, dt);
		cout<<pomme<<endl;
		cout<<"============"<<endl;
		out<<pomme.get_etat()<<endl;
	}
	
	out.close();
	
	return 0;
}
