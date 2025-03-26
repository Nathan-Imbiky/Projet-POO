#pragma once
#include <iostream>
#include <vector>
#include <list>
class Vecteur
{
	private :
	std::vector<double> coords; //coordonnees du vecteur
	double norme2() const; //calcule le carre de la norme du vecteur
	
	
	public :
	std::vector<double> get_coords() const; //Retourne les coordonnees du vecteur
	void augmente(double x=0); //augmente la dimension du vecteur et ajoute une valeur dans la "case" ajoutee (valeur 0 par defaut par precaution)
	void set_coord(std::size_t i, double x); //permet de modifier une coordonnae du vecteur (on entre la valeur x a l'indice i)
	
	double norme() const; // calcule la norme
	
	//produits :
	double prod_scal(Vecteur autre) const; // produit scalaire de vecteurs; si les dimensions ne sont pas egales on lance une exception 
	Vecteur prod_vect(Vecteur autre) const; // produit vectoriel (defini uniquement pour la dimension 3; autrement on lance une exception)
	
	//constructeurs :
	explicit Vecteur(unsigned int n); // ajoute n dimensions au vecteur et initialise chaque coordonnee a 0
	Vecteur(double x, double y, double z); //construit le vecteur 3D (x, y, z)
	Vecteur(std::list<double> L); //construit le vecteur a partir d'une liste; pour cause d'ambiguite, preferer l'utilisation du constructeur de la ligne precedente pour 3 dimensions
	
	//operateurs internes :
	bool operator==(Vecteur const& autre); //determine si notre vecteur est egal a "autre", remplace la fonction compare()
	bool operator!=(Vecteur const& autre); //simplement "non v==autre", ou v est notre vecteur
	
	Vecteur& operator+=(Vecteur const& autre); //additionne au notre le vecteur autre
	Vecteur& operator-=(Vecteur const& autre); //soustrait au notre le vecteur autre
	
	Vecteur& operator*=(double const& a); //multiplication interne par un scalaire
	Vecteur& operator/=(double const& a); //division interne par un scalaire
};


//operateurs externes :
std::ostream& operator<<(std::ostream& out, Vecteur const& v); //affiche v (cout<<v)


double operator*(Vecteur const&v1, Vecteur const& v2); //effectue le produit scalaire de v1 et v2; elle utilisera la methode prod_scal, que j'ai decide de garder, et va catch son exception puis retourner 0 en cas de probleme
Vecteur operator^(Vecteur v1, Vecteur const& v2); //retourne le produit vectoriel de v1 avec v2 (v1^v2); elle utilisera elle aussi la methode prod_vect correspondante, et retournera le vecteur 3d nul en cas d'exception
Vecteur operator-(Vecteur v); //retourne -v l'oppose de v
Vecteur operator~(Vecteur const& v); //retourne le vecteur unitaire dans le sens et la direction de v

Vecteur operator*(Vecteur v, double const& a); 
Vecteur operator*(double const& a, Vecteur v); //multiplication scalaire des deux cotes
Vecteur operator/(Vecteur v, double const& a);
Vecteur operator/(double const& a, Vecteur v); //division scalaire des deux cotes

Vecteur operator+(Vecteur v1, Vecteur const& v2); // addition de vecteurs
Vecteur operator-(Vecteur v1, Vecteur const& v2); // soustraction de vecteurs




