all: testVecteurs

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


Vecteurs.o: Vecteurs.cc Vecteurs.h
testVecteurs.o: testVecteurs.cc Vecteurs.h
testVecteurs: Vecteurs.o testVecteurs.o
