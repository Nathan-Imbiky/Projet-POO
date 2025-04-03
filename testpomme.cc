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
	PointMateriel terre({0.0, 0.0, -6371000}, {0.0, 0.0, 0.0}, 5.972*pow(10, 24)); //hauteur negative pour la distance a la Terre 
	
	ChampNewtonien Poids(terre);
	Libre cl;
	
	PointMateriel pomme({0.0, 0.0, 10.0}, {0.0, 0.0, 0}, 0.1, Poids, cl);
	

	
	
	IntegrateurEulerCromer I;
	
	ofstream out("pommep.txt");
	ofstream out2("pommev.txt"); //utiles pour gnuplot
	cout<<pomme<<endl;
	cout<<"========="<<endl;
	
	for(unsigned int i(1); i<=100; ++i)
	{
		t+=dt;
		I.integre(pomme, t, dt);
		cout<<pomme<<endl;
		cout<<"============"<<endl;
		out<<pomme.get_etat()<<endl;
		out2<<pomme.get_derivee()<<endl;
	}
	
	out.close();
	out2.close();
	
	return 0;
}
