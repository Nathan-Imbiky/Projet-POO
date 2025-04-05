#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include <iostream>
#include <memory>
#include <string>

class ObjetPhysique;

class Contrainte
{
public:
     virtual Vecteur applique_force(const ObjetPhysique& ob, Vecteur force, double t) const =0;
     virtual Vecteur position(const ObjetPhysique& ob) const =0;
     virtual Vecteur vitesse(const ObjetPhysique& ob) const =0;
     virtual std::unique_ptr<Contrainte> copie() const=0;
     virtual std::string nom_type() const = 0;
};


class Libre: public Contrainte
{
public:
     Vecteur applique_force(const ObjetPhysique& Ob, Vecteur force, double t) const override;
     Vecteur position(const ObjetPhysique& Ob) const override;
     Vecteur vitesse(const ObjetPhysique& Ob) const override;
     std::unique_ptr<Contrainte> copie() const override;
     std::unique_ptr<Libre> clonage() const;
     std::string nom_type() const override {return "Libre";}
};

