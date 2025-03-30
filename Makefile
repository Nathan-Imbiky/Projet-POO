all: testVecteurs testvecteurs2 testPointMateriel

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall

Vecteurs.o: Vecteurs.cc Vecteurs.h

testvecteurs2: Vecteurs.o testvecteurs2.o
testvecteurs2.o: testvecteurs2.cc Vecteurs.h

testVecteurs.o: testVecteurs.cc Vecteurs.h
testVecteurs: Vecteurs.o testVecteurs.o


testPointMateriel: PointMateriel.o Vecteurs.o testPointMateriel.o Constantes.o
testPointMateriel.o: PointMateriel.cc PointMateriel.h  
Constantes.o: Constantes.h Constantes.cc Vecteurs.o

Integrateurs.o: Integrateurs.cc Integrateurs.h
Objetmobile.o: Objetmobile.cc Objetmobile.h

Contraintes.o: Vecteurs.o Constantes.o ObjetPhysique.o Contraintes.h Contraintes.cc
ObjetPhysique.o: Vecteurs.o Constantes.o Contraintes.o Objetmobile.o ChampsForces.o ObjetPhysique.h ObjetPhysique.cc
PointMateriel.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.o PointMateriel.h PointMateriel.cc
ChampsForces.o: Vecteurs.o Constantes.o ObjetPhysique.o ChampsForces.h ChampsForces.cc

