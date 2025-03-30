#include "Integrateur.h"
#include "PointMateriel.h"
#include "Vecteurs.h"
#include "Contraintes.h"
#include "Constantes.h"
#include "Objetmobile.h"
using namespace std;

int main()
{
	PointMateriel p({0, 0, 1}, {0, 1, 2}, 0.127);
	IntegrateurEulerCromer I;
	double t(0);
	double dt(0.01);
	
	cout<<p<<endl;
	for(int i(0); i<68; ++i) //affiche 68 fois l'etat du point materiel, a comparer avec le fichier mentionne en P6
	{
		cout<<"====================="<<endl;
		t+=dt;
		I.integre(p, t, dt);
		cout<<"t = "<<t<<endl;
		cout<<p<<endl;
	}
	
	cout<<endl;
	cout<<"Changement de point; ------------------------------------------------------------------------------"<<endl; //Les traits sont presents pour un reperage plus facile dans le terminal
	cout<<endl;
	
	
	PointMateriel p2({0, 0, 60}, {0, 0, 0}, 10);
	IntegrateurEulerCromer I2;
	double t2(0);
	double dt2(0.5);
	
	cout<<p2<<endl;
	for(int i(0); i<10; ++i) //nouveau test avec vitesse nulle et un plus grand pas de temps
	{
		cout<<"====================="<<endl;
		t2+=dt2;
		I.integre(p2, t2, dt2);
		cout<<"t = "<<t2<<endl;
		cout<<p2<<endl;
	}
	
	cout<<endl;
	cout<<"Changement de point; ------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	
	PointMateriel p3({0, 0, 60}, {0, 0, 30}, 1);
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
	}
	
	return 0;
}
