#include "Integrateur.h"
#include "PointMateriel.h"
#include "Vecteurs.h"
#include "Contraintes.h"
#include "Constantes.h"
#include "Objetmobile.h"
#include "ChampsForces.h"
#include "ObjetPhysique.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	GravitationConstante gr(g);
	Libre cl;
	PointMateriel p({0, 0, 1}, {0, 1, 2}, 0.127, gr, cl);
	IntegrateurEulerCromer I;
	double t(0);
	double dt(0.01);
	
	ofstream out("test1.txt");
	
	cout<<p<<endl;
	for(int i(0); i<68; ++i) //affiche 68 fois l'etat du point materiel, a comparer avec le fichier mentionne en P6
	{
		cout<<"====================="<<endl;
		t+=dt;
		I.integre(p, t, dt);
		cout<<"t = "<<t<<endl;
		cout<<p<<endl;
		
		if(not(out.fail()))
		{
			out<<p.get_etat()<<endl;
		}
	}
	out.close();
	
	cout<<endl;
	cout<<"Changement de point; ------------------------------------------------------------------------------"<<endl; //Les traits sont presents pour un reperage plus facile dans le terminal
	cout<<endl;
	
	out.open("test2.txt");
	
	PointMateriel p2({1, 0, 5}, {0, 0, 0}, 10, gr, cl);
	IntegrateurEulerCromer I2;
	double t2(0);
	double dt2(0.5);
	
	cout<<p2<<endl;
	for(int i(0); i<50; ++i) //nouveau test avec vitesse nulle et un plus grand pas de temps
	{
		cout<<"====================="<<endl;
		t2+=dt2;
		I.integre(p2, t2, dt2);
		cout<<"t = "<<t2<<endl;
		cout<<p2<<endl;
		if(not(out.fail()))
		{
			out<<p2.get_etat()<<endl;
		}
	}
	
	out.close();
	
	cout<<endl;
	cout<<"Changement de point; ------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	
	out.open("test3.txt");
	
	PointMateriel p3({5, 0, 1}, {0, 0, 30}, 1, gr, cl);
	IntegrateurEulerCromer I3;
	double t3(0);
	double dt3(0.1);
	
	cout<<p2<<endl;
	for(int i(0); i<50; ++i) //nouveau test avec vitesse vers le haut
	{
		cout<<"====================="<<endl;
		t3+=dt3;
		I.integre(p3, t3, dt3);
		cout<<"t = "<<t3<<endl;
		cout<<p3<<endl;
		if(not(out.fail()))
		{
			out<<p3.get_etat()<<endl;
		}
	}
	
	return 0;
}
