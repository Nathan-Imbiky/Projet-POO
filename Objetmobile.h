#pragma once
#include "Vecteurs.h"
#include <iostream>

class ObjetMobile
{
	protected :
	Vecteur parametres;
	Vecteur derivee;
	
	public :
	ObjetMobile(Vecteur v1, Vecteur v2={0, 0, 0}) //Constructeur prenant un vecteur pour chaque argument
	: parametres(v1), derivee(v2)
	{}
	
	Vecteur getparametres() const;
	void setparametres(Vecteur const& v); //remplace les parametres par le vecteur v en argument
	void set_parametre(std::size_t n, double x); //la n-ieme coordonnee de la derivee est modifiee en x
	
	Vecteur getderivee() const;
	void setderiveetout(Vecteur const& v); //remplace la derivee par le vecteur v en argument
	void set_derivee(std::size_t n, double x); //la n-ieme coordonnee de la derivee est modifiee en x
	
	virtual Vecteur evolution(double t) const = 0; //retourne l'equation d'evolution de l'objet mobile (qui depend donc de quel sous classe il fait partie)
	virtual void afficher(std::ostream& out) const = 0; //affiche l'objet (depend encore de la sous classe), utile pour l'operateur <<
};

std::ostream& operator<<(std::ostream& out, ObjetMobile const& o); //operateur << surcharge pour les objets mobiles


