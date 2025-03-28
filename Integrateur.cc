#include "Objetmobile.h"
#include "Integrateur.h"
#include "Vecteurs.h"


void IntegrateurEulerCromer::integre(ObjetMobile& O, double t, double dt, double ordre) const
{
	if(ordre==2)
	{
		Vecteur p(O.getparametres());
		Vecteur d(O.getderivee());
	
		O.setderiveetout(d + dt*O.evolution(t));
		O.setparametres(p + dt*O.getderivee());
	}
	if(ordre==1)
	{
		Vecteur p(O.getparametres());
		O.setparametres(p + dt*O.evolution(t));
	}
}


