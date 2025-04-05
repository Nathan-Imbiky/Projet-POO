#pragma once
#include "Objetmobile.h"
#include <memory>

class Integrateur
{
	public :
	virtual void integre(ObjetMobile& O, double t, double dt, double ordre=2) const =0;
	void repete_integre(unsigned int n, ObjetMobile& O, double t, double dt, double ordre=2) const; //ordre
	virtual std::unique_ptr<Integrateur> copie() const =0;
};

class IntegrateurEulerCromer : public Integrateur
{
	public :
	void integre(ObjetMobile& O, double t, double dt, double ordre=2) const override;
	
	std::unique_ptr<Integrateur> copie() const override {return clonage();}
	std::unique_ptr<IntegrateurEulerCromer> clonage() const {return std::unique_ptr<IntegrateurEulerCromer>(new IntegrateurEulerCromer(*this));}
};
