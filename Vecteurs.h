#pragma once
#include <iostream>
#include <vector>
#include <list>
class Vecteur
{
	private :
	std::vector<double> coords; //coordonn‚es du vecteur
	double norme2() const; //calcule le carr‚ de la norme du vecteur
	
	
	public :
	std::vector<double> get_coords() const; //Retourne les coordonn‚es du vecteur
	void augmente(double x=0); //augmente la dimension du vecteur et ajoute une valeur dans la "case" ajout‚e (valeur 0 par d‚faut par pr‚caution)
	void set_coord(std::size_t i, double x); //permet de modifier une coordonn‚e du vecteur (on entre la valeur x … l'indice i)
	void affiche() const; //affiche  le Vecteur dans le terminal
	bool compare(Vecteur v) const; //d‚termine si le Vecteur en argument est ‚gal au n“tre
	
	double norme() const; // calcule la norme
	
	//op‚rations :
	Vecteur addition(Vecteur autre) const; //addition de vecteurs; si les dimensions ne sont pas ‚gales, on ajoute 0 dans toutes les cases finales du vecteur le plus grand [(1, 0) + (0, 0, 1) = (1, 0, 1)]
	Vecteur oppose() const; //retourne le vecteur oppos‚
	Vecteur unitaire() const; // retourne le vecteur unitaire colin‚aire et de mˆme sens
	Vecteur mult(double x) const; // multiplication par un scalaire
	
	
	//produits :
	double prod_scal(Vecteur autre) const; // produit scalaire de vecteurs; si les dimensions ne sont pas ‚gales on lan‡e une exception 
	Vecteur prod_vect(Vecteur autre) const; // produit vectoriel (d‚fini uniquement pour la dimension 3; autrement on lance une exception)
	
	//constructeurs :
	explicit Vecteur(unsigned int n); // ajoute n dimensions au vecteur et initialise chaque coordonn‚e … 0
	Vecteur(double x, double y, double z); //construit le vecteur 3D (x, y, z)
	Vecteur(std::list<double> L); //construit le vecteur … partir d'une liste 
	
	//op‚rateurs :
	bool operator==(Vecteur const& autre); //d‚termine si notre vecteur est ‚gal … "autre", remplace la fonction compare()
	bool operator!=(Vecteur const& autre); //simplement "non v==autre", o— v est notre vecteur
	
	Vecteur& operator+=(Vecteur const& autre); //additionne au notre le vecteur autre
	Vecteur& operator-=(Vecteur const& autre); //soustrait au notre le vecteur autre
	
	Vecteur& operator*=(double const& a);
	Vecteur& operator/=(double const& a);
};

std::ostream& operator<<(std::ostream& out, Vecteur const& v); //affiche v (cout<<v)

Vecteur operator^(Vecteur v1, Vecteur const& v2); //retourne le produit vectoriel de v1 avec v2 (v1^v2)
double operator*(Vecteur const&v1, Vecteur const& v2); //effectue le produit scalaire de v1 et v2
Vecteur operator-(Vecteur v); //retourne -v l'oppos‚ de v
Vecteur operator~(Vecteur const& v); //retourne le vecteur unitaire dans le sens et la direction de v

Vecteur operator*(Vecteur v, double const& a); 
Vecteur operator*(double const& a, Vecteur v); //multiplication scalaire des deux c“t‚s
Vecteur operator/(Vecteur v, double const& a);
Vecteur operator/(double const& a, Vecteur v); //division scalaire des deux c“t‚s

Vecteur operator+(Vecteur v1, Vecteur const& v2); // addition de vecteurs
Vecteur operator-(Vecteur v1, Vecteur const& v2); // soustraction de vecteurs




