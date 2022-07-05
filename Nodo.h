#ifndef NODO_H
#define NODO_H
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
struct Nodo{
  char base;
  char codigo[10];
  int frecuencia;
  Nodo *sig;
  Nodo *izq;
  Nodo *der;
  
};

#include "Nodo.hxx"

#endif