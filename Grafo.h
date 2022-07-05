#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <map>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include "sequence.h"

using namespace std;

template < class T, class C >
class Grafo {
  public:
  typedef vector<T> TVertice;
  typedef map<unsigned long, C> TFila;
  typedef map<unsigned long, TFila> TMatriz;
  typedef vector<bool> TMarca;
  
  Grafo();
  ~Grafo();
  unsigned long InsertarVertice(T v);
  void InsertarArista(unsigned long i, unsigned long j, C costo);

  unsigned long ObtenerNumVertices();
  unsigned long ObtenerNumAristas();
  unsigned long ObtenerNumerodeAristas();
  T ObtenerVertice(unsigned long i);
  C ObtenerCostoArista(unsigned long i, unsigned long j);
  bool BuscarVertice(T v);
  bool BuscarArista(unsigned long i, unsigned long j);
 

  bool EliminarVertice(T v);
  bool EliminarArista(unsigned long i, unsigned long j);

  vector<unsigned long> Dijkstra(unsigned long indiceInicio, unsigned long indiceFinal);
  vector<unsigned long> baseRemota(unsigned long indiceInicio);

  protected:
  TVertice l_vertices;
  TMatriz m_costos;
};

#include "Grafo.hxx"

#endif  