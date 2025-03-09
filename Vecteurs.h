#pragma once
#include <vector>
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
	
	//op‚rations :
	Vecteur addition(Vecteur autre) const; //addition de vecteurs; si les dimensions ne sont pas ‚gales, on ajoute 0 dans toutes les cases finales du vecteur le plus grand [(1, 0) + (0, 0, 1) = (1, 0, 1)]
	Vecteur oppose() const; //retourne le vecteur oppos‚
	Vecteur unitaire() const; // retourne le vecteur unitaire colin‚aire et de mˆme sens
	Vecteur mult(double x) const; // multiplication par un scalaire
	double prod_scal(Vecteur autre) const; // produit scalaire de vecteurs; si les dimensions ne sont pas ‚gales on lan‡e une exception 
	Vecteur prod_vect(Vecteur autre) const; // produit vectoriel (d‚fini uniquement pour la dimension 3; autrement on lance une exception)
	double norme() const; // calcule la norme
	
	
};


