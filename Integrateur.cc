#include "Objetmobile.h"
#include "Integrateur.h"
#include "Vecteurs.h"


void IntegrateurEulerCromer::integre(ObjetMobile& O, double t, double dt, double ordre) const
{
	if(ordre==2)
	{
		Vecteur p(O.get_etat());
		Vecteur d(O.get_derivee());
	
		O.set_derivee(d + dt*O.evolution(t));
		O.set_etat(p + dt*O.get_derivee());
	}
	if(ordre==1)
	{
		Vecteur p(O.get_etat());
		O.set_etat(p + dt*O.evolution(t));
	}
}

void Integrateur::repete_integre(unsigned int n, ObjetMobile& O, double t, double dt, double ordre) const
{
	for(unsigned int i(1); i<=n; ++i)
	{
		integre(O, t, dt, ordre);
	}
}

