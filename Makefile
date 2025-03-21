all: testVecteurs testvecteurs2

CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall


testvecteurs2: Vecteurs.o testvecteurs2.o
testvecteurs2.o: testvecteurs2.cc Vecteurs.h
Vecteurs.o: Vecteurs.cc Vecteurs.h
testVecteurs.o: testVecteurs.cc Vecteurs.h
testVecteurs: Vecteurs.o testVecteurs.o

