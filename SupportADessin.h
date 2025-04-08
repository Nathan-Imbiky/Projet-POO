#pragma once 
#include "Vecteurs.h"
#include "Constantes.h"
#include "ObjetPhysique.h"
#include "PointMateriel.h"
#include "Systemes.h"
#include <iostream>


class SupportADessin
{
public:
  virtual ~SupportADessin() = default; // on suppose ici que les supports ne seront ni copiés ni déplacés

  virtual void dessine(PointMateriel const&) = 0;
  virtual void dessine(Systeme const&) = 0;
};

class TextViewer: public SupportADessin
{
public:
    TextViewer( std::ostream& out) 
    : out(out){};
    void dessine(PointMateriel const& pm) override;
    void dessine(Systeme const& sys) override;
    virtual ~TextViewer()= default;
private:
    std::ostream& out;
};

void TextViewer::dessine(PointMateriel const& pm) 
{
    out << pm << std::endl;  
}


void TextViewer::dessine(Systeme const& sys) 
{
    out << sys << std::endl;
}
