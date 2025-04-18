all: testVecteurs testvecteurs2 testPointMateriel testIntegrateur1 testpomme testpomme2 testSystem exerciceP9

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall

Vecteurs.o: Vecteurs.cc Vecteurs.h

testvecteurs2: Vecteurs.o testvecteurs2.o
testvecteurs2.o: testvecteurs2.cc Vecteurs.h

testVecteurs.o: testVecteurs.cc Vecteurs.h
testVecteurs: Vecteurs.o testVecteurs.o


testPointMateriel: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.o Contraintes.o PointMateriel.o Objetmobile.o ObjetPhysique.o testPointMateriel.o
testPointMateriel.o: PointMateriel.cc PointMateriel.h  
Constantes.o: Constantes.h Constantes.cc Vecteurs.o

Integrateur.o: Objetmobile.o Integrateur.cc Integrateur.h
Objetmobile.o: Objetmobile.cc Objetmobile.h

Contraintes.o: Vecteurs.o Constantes.o ObjetPhysique.o Contraintes.h Contraintes.cc
ObjetPhysique.o: Vecteurs.o Constantes.o Contraintes.o Objetmobile.o ChampsForces.o ObjetPhysique.h ObjetPhysique.cc
PointMateriel.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.o PointMateriel.h PointMateriel.cc
ChampsForces.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.h ChampsForces.cc

testIntegrateur1: Objetmobile.o ObjetPhysique.o Constantes.o PointMateriel.o Vecteurs.o Integrateur.o Contraintes.o ChampsForces.o testIntegrateur1.o
testIntegrateur1.o: Objetmobile.o Constantes.o PointMateriel.o Vecteurs.o Integrateur.o Contraintes.o testIntegrateur1.cc

testpomme: Objetmobile.o Contraintes.o Constantes.o Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme.o
testpomme.o: Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme.cc

testpomme2: Objetmobile.o Contraintes.o Constantes.o Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme2.o
testpomme2.o: Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme2.cc

Systemes.o: ObjetPhysique.o Systemes.o Integrateur.o Contraintes.o ChampsForces.o Systemes.cc Systemes.h

testSystem: Systemes.o Integrateur.o Contraintes.o ChampsForces.o PointMateriel.o Vecteurs.o Objetmobile.o ObjetPhysique.o Constantes.o testSystem.o
testSystem.o: Systemes.o Integrateur.o Contraintes.o ChampsForces.o PointMateriel.o Vecteurs.o testSystem.cc

exerciceP9: Objetmobile.o Contraintes.o Constantes.o Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o Systemes.o exerciceP9.o
exerciceP9.o: Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o Systemes.o exerciceP9.cc
