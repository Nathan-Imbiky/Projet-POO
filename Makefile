all: testPointMateriel

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


testPointMateriel: PointMateriel.o Vecteurs.o testPointMateriel.o Constantes.o
testPointMateriel.o: PointMateriel.cc PointMateriel.h  
PointMateriel.o: PointMateriel.cc PointMateriel.h Vecteurs.o
Constanes.o: Constantes.h Constantes.cc Vecteurs.o
Vecteurs.o: Vecteurs.cc Vecteurs.h

