#pragma once
#include "Vecteurs.h"
#include <iostream>
#include <string>

class ObjetMobile
{
	protected :
	Vecteur etat;
	Vecteur derivee;
	
	public :
	ObjetMobile(Vecteur v1, Vecteur v2={0, 0, 0}); //Constructeur prenant un vecteur pour chaque argument; ajoute des 0 � la fin du vecteur de dimension plus petite si besoin
	ObjetMobile(ObjetMobile const& O) = default;
	
	virtual ~ObjetMobile() = default;
	virtual ObjetMobile& operator=(const ObjetMobile& O) = default;
	
	Vecteur get_etat() const;
	void set_etat(Vecteur const& v); //remplace le vecteur d'etat par le vecteur v en argument
	void set_parametre(std::size_t n, double x); //la n-ieme coordonnee du vecteur d'etat est modifiee en x
	
	Vecteur get_derivee() const;
	void set_derivee(Vecteur const& v); //remplace la derivee par le vecteur v en argument
	void set_coord_derivee(std::size_t n, double x); //la n-ieme coordonnee de la derivee est modifiee en x
	
	virtual Vecteur evolution(double t) const = 0; //retourne l'equation d'evolution de l'objet mobile (qui depend donc de quel sous classe il fait partie)
	virtual std::ostream& afficher(std::ostream& out) const = 0; //affiche l'objet (depend encore de la sous classe), utile pour l'operateur <<
	virtual std::string nom_type() const = 0; //retourne le type d'une instance sous forme de string (Point Materiel pour un PointMateriel par exemple)
};

std::ostream& operator<<(std::ostream& out, ObjetMobile const& o); //operateur << surcharge pour les objets mobiles


