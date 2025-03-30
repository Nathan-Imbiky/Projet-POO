all: testVecteurs testvecteurs2 testPointMateriel testIntegrateur1 testpomme testpomme2

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall

Vecteurs.o: Vecteurs.cc Vecteurs.h

testvecteurs2: Vecteurs.o testvecteurs2.o
testvecteurs2.o: testvecteurs2.cc Vecteurs.h

testVecteurs.o: testVecteurs.cc Vecteurs.h
testVecteurs: Vecteurs.o testVecteurs.o


testPointMateriel: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.o PointMateriel.o Objetmobile.o ObjetPhysique.o testPointMateriel.o

testPointMateriel.o: PointMateriel.cc PointMateriel.h  
Constantes.o: Constantes.h Constantes.cc Vecteurs.o

Integrateur.o: Objetmobile.o Integrateur.cc Integrateur.h
Objetmobile.o: Objetmobile.cc Objetmobile.h

Contraintes.o: Vecteurs.o Constantes.o ObjetPhysique.o Contraintes.h Contraintes.cc
ObjetPhysique.o: Vecteurs.o Constantes.o Contraintes.o Objetmobile.o ChampsForces.o ObjetPhysique.h ObjetPhysique.cc
PointMateriel.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.o PointMateriel.h PointMateriel.cc
ChampsForces.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.h ChampsForces.cc

testIntegrateur1: Objetmobile.o Constantes.o PointMateriel.o Vecteurs.o Integrateur.o Contraintes.o testIntegrateur1.o
testIntegrateur1.o: Objetmobile.o Constantes.o PointMateriel.o Vecteurs.o Integrateur.o Contraintes.o testIntegrateur1.cc

testpomme: Objetmobile.o Constantes.o Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme.o
testpomme.o: Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme.cc

testpomme2: Objetmobile.o Constantes.o Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme2.o
testpomme2.o: Vecteurs.o ObjetPhysique.o ChampsForces.o PointMateriel.o Integrateur.o testpomme2.cc
