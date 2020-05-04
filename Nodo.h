#ifndef NODO_H
#define NODO_H
#include <bits/stdc++.h>
using namespace std;
struct Nodo{
  char base;
  char codigo[10];
  int frecuencia;
  Nodo *sig;
  Nodo *izq;
  Nodo *der;
  void eliminarArbol(Nodo *nodo);
  
};

#include "Nodo.hxx"

#endif