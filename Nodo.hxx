#include "Nodo.h"
#include <bits/stdc++.h>
using namespace std;
  void Nodo::eliminarArbol(Nodo *nodo){
    if(nodo->izq)
      eliminarArbol(nodo->izq);
    if(nodo->der)
      eliminarArbol(nodo->der);
    delete(nodo);
  }