//Les commentaires introduisant la classe sont dans le ficihier .h
#include "Vecteurs.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void Vecteur::augmente(double x)
{
	coords.push_back(x);
}

void Vecteur::set_coord(size_t i, double x)
{
	if(i>=coords.size())
	{
		cout<<"L'indice indiqu‚ n'est pas conforme … la dimension"<<endl;
	}
	else
	{
		coords[i]=x;
	}
}

void Vecteur::affiche() const
{
	if(coords.size()==0)
	{
		cout<<"Ce vecteur est vide"<<endl; //Pr‚caution prise en cas de vecteur vide
	}	
	else
	{
		
		cout<<"( ";
		for(size_t i(0) ; i< coords.size()-1 ; ++i)
		{
			cout<<coords[i]<<", ";
		}
		cout<<coords[coords.size()-1]<<" )"<<endl;
	}
}

bool Vecteur::compare(Vecteur v) const
{
	if(coords.size() != v.coords.size())
	{
		return false;
	}
	else
	{
		bool b(true);
		
		for(size_t i(0); i<coords.size(); ++i)
		{
			if(coords[i] != v.coords[i])
			{
				b = false;
			}
		}
		return b;
	}
}



Vecteur Vecteur::addition(Vecteur autre) const
{
	Vecteur v;
	size_t m(coords.size());
	
	if(coords.size()<autre.get_coords().size())
	{
		m = autre.get_coords().size();
	}
	
	for(size_t i(0); i<m; ++i)
	{
		v.augmente(0);
	}
	
	for(size_t i(0); i<coords.size(); ++i)
	{
		v.set_coord(i, coords[i]);
	}
	
	for(size_t i(0); i<autre.get_coords().size(); ++i)
	{
		v.set_coord(i, v.get_coords()[i] + autre.get_coords()[i]);
	}
	
	return v;
}


Vecteur Vecteur::oppose() const
{
	Vecteur v;
	
	for (auto element : coords)
	{
		v.augmente(-element);
	}
	
	return v;
}

Vecteur Vecteur::unitaire() const
{
	Vecteur v;
	size_t n(0);
	
	for (auto element : coords)
	{
		if(element==0)
		{
			++n;
		}
	}
	
	if(n==coords.size())
	{
		for(size_t i(0); i<coords.size(); ++i)
		{
			v.augmente(0);
		}
		
		return v;
	}
	else
	{
		for (auto element : coords)
		{
				v.augmente(element);
		}
	
		return v.mult((1/v.norme()));
	}
	
}

Vecteur Vecteur::mult(double x) const
{
	Vecteur v;
	
	for (auto element : coords)
	{
		v.augmente(x*element);
	}
	
	return v;
}


double Vecteur::norme2() const
{
	double y(0);
	
	for (auto element : coords)
	{
		y+= element*element;
	}
	return y;
}

double Vecteur::norme() const
{
	double y(sqrt(norme2()));
	return y;
}

vector<double> Vecteur::get_coords() const
{
	return coords;
}

double Vecteur::prod_scal(Vecteur autre) const
{
	double y(0);
	
	if(coords.size() != autre.get_coords().size())
	{
		throw out_of_range("p_scalaire probleme de dimension;");
	}
	
	for(size_t i(0); i<coords.size(); ++i)
	{
		y += autre.get_coords()[i]*coords[i];
	}

	
	return y;
}


Vecteur Vecteur::prod_vect(Vecteur autre) const
{
	Vecteur v;

	
	
	if( not( coords.size()==autre.get_coords().size() && coords.size()==3) )
	{
		throw out_of_range("p_vectoriel probleme de dimension;");
	}
	
	double x1(coords[1]*autre.get_coords()[2] - coords[2]*autre.get_coords()[1]);
	double x2(coords[2]*autre.get_coords()[0] - coords[0]*autre.get_coords()[2]);
	double x3(coords[0]*autre.get_coords()[1] - coords[1]*autre.get_coords()[0]);
	
	v.augmente(x1);
	v.augmente(x2);
	v.augmente(x3);
	
	return v;
	
}
//------





