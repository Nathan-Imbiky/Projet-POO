//Les commentaires introduisant la classe sont dans le ficihier .h
#include "Vecteurs.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;


void Vecteur::augmente(double x)
{
	coords.push_back(x);
}

void Vecteur::set_coord(size_t i, double x)
{
	if(i>=coords.size())
	{
		cout<<"L'indice indique n'est pas conforme a la dimension"<<endl;
	}
	else
	{
		coords[i]=x;
	}
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
		throw out_of_range("p_scalaire probleme de dimension; ");
	}
	
	for(size_t i(0); i<coords.size(); ++i)
	{
		y += autre.get_coords()[i]*coords[i];
	}

	
	return y;
}


Vecteur Vecteur::prod_vect(Vecteur autre) const
{
	Vecteur v(0);

	
	
	if( not( coords.size()==autre.get_coords().size() && coords.size()==3) )
	{
		throw out_of_range("p_vectoriel probleme de dimension; ");
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

Vecteur::Vecteur(unsigned int n)
{
	for(unsigned int i(0); i<n; ++i)
	{
			augmente(0);
	}
}
	
	
Vecteur::Vecteur(list<double> L)
{
	for (double element : L)
	{
		augmente(element);
	}
}

Vecteur::Vecteur(double x, double y, double z) 
{
	augmente(x);
	augmente(y);
	augmente(z);
}

//-----


bool Vecteur::operator==(Vecteur const& autre)
{
	if(coords.size() != autre.coords.size())
	{
		return false;
	}
	else
	{
		bool b(true);
		
		for(size_t i(0); i<coords.size(); ++i)
		{
			if(coords[i] != autre.coords[i])
			{
				b = false;
			}
		}
		return b;
	}
}


bool Vecteur::operator!=(Vecteur const& autre)
{
	if(*this==autre) return false;
	else return true;
}
	
Vecteur& Vecteur::operator+=(Vecteur const& autre)
{
	size_t m(coords.size());
	
	if(coords.size()<autre.get_coords().size())
	{
		m = autre.get_coords().size();
	}
	
	Vecteur v(m); //on cree un vecteur auxiliaire v de taille max{taille de *this, taille de autre}, puis on lui ajoute les coordonnees des deux autres vecteurs
	
	
	for(size_t i(0); i<coords.size(); ++i)
	{
		v.set_coord(i, coords[i]);
	}
	
	for(size_t i(0); i<autre.get_coords().size(); ++i)
	{
		v.set_coord(i, v.get_coords()[i] + autre.get_coords()[i]);
	}
	
	*this = v;
	
	return *this;
}

Vecteur& Vecteur::operator-=(Vecteur const& autre)
{
	*this+= -autre;
	return *this;
}


double operator*(Vecteur const&v1, Vecteur const& v2)
{
	double x;
	try
	{
	x = v1.prod_scal(v2);	
	}
	catch(out_of_range const& err)
	{
		cout<<err.what()<<"la valeur 0 sera retournee"<<endl;
		x = 0;
	}
	
	return x;
}

Vecteur operator^(Vecteur v1, Vecteur const& v2)
{
	try
	{
	v1 = v1.prod_vect(v2);	
	}
	catch(out_of_range const& err)
	{
		cout<<err.what()<<"le vecteur nul sera retourne"<<endl;
		v1 = {0, 0, 0};
	}
	
	return v1;

}



ostream& operator<<(ostream& out, Vecteur const& v)
{
	vector<double> u = v.get_coords(); //u est un placeholder pour l'attribut prive "v.coords"
	
	if(u.size()==0) 
	{
		out<<"Ce vecteur est vide";
		return out;
	}
	else
	{
		out<<"( ";
		for(size_t i(0) ; i<u.size()-1 ; ++i) //u.size()-1 pour eviter une virgule en trop a la fin
		{
			out<<u[i]<<", ";
		}
		out<<u[u.size()-1]<<" )";
		return out;
	}
} 



Vecteur operator-(Vecteur v) 
{
	
	for (size_t i(0); i<v.get_coords().size(); ++i)
	{
		v.set_coord(i, -v.get_coords()[i]);
	}
	
	return v;
}

Vecteur operator~(Vecteur const& v)
{
	size_t n(0);
	
	for (auto element : v.get_coords())
	{
		if(element==0)
		{
			++n;
		}
	}
	
	if(n==v.get_coords().size()) //ce "n" sert a verifier si toutes les composantes du vecteur sont nulles (auquel cas le vecteur nul de meme dimension sera retourne)
	{
		
		return v;
	}
	else
	{
		return v/v.norme();
	}
}

Vecteur& Vecteur::operator*=(double const& a)
{
	for(size_t i(0); i<coords.size(); ++i)
	{
			coords[i] *=a;
	}
	return *this;
}



Vecteur operator*(Vecteur v, double const& a)
{
	v*=a;
	return v;
}

Vecteur operator*(double const& a, Vecteur v)
{
	v*=a;
	return v;
}

Vecteur& Vecteur::operator/=(double const& a)
{
	if(a==0)
	{
		cout<<"division par 0 impossible, vecteur non modifie"<<endl;
		return *this;
	}
	
	for(size_t i(0); i<coords.size(); ++i)
	{
		coords[i] /=a;
	}
	return *this;
}

Vecteur operator/(double const& a, Vecteur v)
{
	v/=a;
	return v;
}

Vecteur operator/(Vecteur v, double const& a)
{
	v/=a;
	return v;
}



Vecteur operator+(Vecteur v1, Vecteur const& v2)
{
	v1+=v2;
	return v1;
}

Vecteur operator-(Vecteur v1, Vecteur const& v2)
{
	v1-=v2;
	return v1;
}
