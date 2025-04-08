#include "Vecteurs.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include "PointMateriel.h"
#include "Integrateur.h"
#include "Contraintes.h"
#include "Systemes.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	cout<<"Premier test --------------------------------------------"<<endl;
	cout<<endl;
	
	double dt(0.001);
	PointMateriel terre({0.0, 0.0, -6371000}, {0.0, 0.0, 0.0}, 5.972*pow(10, 24)); //hauteur negative pour la distance a la Terre 
	
	ChampNewtonien Poids(terre);
	Libre cl;
	
	PointMateriel pomme({0.0, 0.0, 10.0}, {0.0, 0.0, 0}, 0.1);
	
	
	Systeme S(terre, Poids, cl);
	S.ajoute_objet(pomme);
	S.set_champ_objet(1, 0);
	S.set_contrainte_objet(1, 0);
	
	ofstream out("pommep.txt");
	ofstream out2("pommev.txt"); //utiles pour gnuplot
	cout<<pomme<<endl;
	cout<<"========="<<endl;
	
	for(unsigned int i(1); i<=100; ++i)
	{
		S.evolue(dt);
		cout<<"============"<<endl;
		cout<<*S.get_objet(1)<<endl;
		out<<S.get_objet(1)->get_etat()<<endl;
		out2<<S.get_objet(1)->get_derivee()<<endl;
	}
	
	S.set_temps(0);
	
	out.close();
	out2.close();
	
	S.ajoute_objet(pomme);
	S.set_champ_objet(2, 0);
	S.set_contrainte_objet(2, 0);
	
	cout<<"DeuxiŠme test --------------------------------------------"<<endl;
	cout<<endl;
	
	out.open("pommep2.txt");
	out2.open("pommev2.txt");
	
	for(unsigned int i(1); i<=14; ++i)
	{
		S.evolue(dt, 100);
		cout<<"============"<<endl;
		cout<<*S.get_objet(2)<<endl;
		out<<S.get_objet(2)->get_etat()<<endl;
		out2<<S.get_objet(2)->get_derivee()<<endl;
	}
	
	
	out.close();
	out2.close();
	
	return 0;
}
