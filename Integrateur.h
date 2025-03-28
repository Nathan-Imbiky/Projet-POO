#pragma once
#include "Objetmobile.h"

class Integrateur
{
	public :
	virtual void integre(ObjetMobile& O, double t, double dt, double ordre=2) const =0;
};

class IntegrateurEulerCromer : public Integrateur
{
	public :
	void integre(ObjetMobile& O, double t, double dt, double ordre=2) const override;
};
