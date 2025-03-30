#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include "ChampsForces.h"
#include <iostream>

class PointMateriel;

class GravitationConstante : public ChampForces
{
public:
     GravitationConstante()
     : gravitation (g)
     {}
     GravitationConstante( Vecteur Gravitation)
     : gravitation(Gravitation)
     {}
	Vecteur force(const PointMateriel& p, double temps ) const;
	Vecteur getGr() const{return gravitation;}
	void setGr ( Vecteur Gr){gravitation=Gr ;}
private:
	Vecteur gravitation;
};

std::ostream& operator<<(std::ostream& out, PointMateriel const& pnt);

class PointMateriel: public ObjetPhysique
{
public:
     PointMateriel()
     : VecteurPosition(0, 0, 0),VecteurVitesse (0,0,0), G(g), masse(0)
     {}
     PointMateriel( Vecteur P, Vecteur V , GravitationConstante Gr,double m)
     : VecteurPosition(P), VecteurVitesse (V), G(Gr), masse(m) 
     {}
     Vecteur position() const;
     Vecteur vitesse() const;
     Vecteur evolution(double t);
     Vecteur getPosition () const {return VecteurPosition;}
     void setPosition (Vecteur VP) {VecteurPosition = VP;}
     Vecteur getVitesse () const {return VecteurVitesse;}
     void setVitesse (Vecteur VV) {VecteurVitesse = VV;}
     double getMasse() const {return masse;}
     void setMasse(double M){masse=M;}
    
private:
     Vecteur VecteurPosition;
     Vecteur VecteurVitesse;
     GravitationConstante G;
     double masse;	
};



