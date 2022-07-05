#include "Grafo.h"


template < class T, class C >
Grafo<T,C>::Grafo()
{
    this->l_vertices.clear();
    this->m_costos.clear();
}

template < class T, class C >
Grafo<T,C>::~Grafo()
{
    if (this->l_vertices.empty() !=false && this->m_costos.empty()!=false)
    {
        this->l_vertices.clear();
        this->m_costos.clear();
    }
}

template < class T, class C >
unsigned long Grafo<T,C>::InsertarVertice(T v)
{
    this->l_vertices.push_back(v);
    return (this->l_vertices.size()-1);
}

template < class T, class C >
void Grafo<T,C>::InsertarArista(unsigned long i, unsigned long j, C costo)
{
  
    this->m_costos[i][j] = costo;
   // cout<<"vertice Inicial:  "<<i<<"  vertice Final: "<<j<<"  costo= "<<m_costos[i][j]<<endl;
    
}

template < class T, class C >
unsigned long Grafo<T,C>::ObtenerNumVertices()
{
    return this->l_vertices.size();
}

template < class T, class C >
unsigned long Grafo<T,C>::ObtenerNumAristas()
{
    unsigned long acum = 0;
    for(auto const &ent1 : this->m_costos)
    {
        for(auto const &ent2 : ent1.second)
        {
            acum += ent2.second;
        }
    }
    return acum;
}
template < class T, class C >
unsigned long Grafo<T,C>::ObtenerNumerodeAristas()
{
    unsigned long acum = 0;
    for(auto const &ent1 : this->m_costos)
    {
        for(auto const &ent2 : ent1.second)
        {
            acum ++;
        }
    }
    return acum;
}
template < class T, class C >
T Grafo<T,C>::ObtenerVertice(unsigned long i)
{
    return this->l_vertices[i];
}

template < class T, class C >
C Grafo<T,C>::ObtenerCostoArista(unsigned long i, unsigned long j)
{
    return this->m_costos[i][j];
}

template < class T, class C >
bool Grafo<T,C>::BuscarVertice(T v)
{
    if(find(l_vertices.begin(), l_vertices.end(),v) != l_vertices.end())
        return true;
    else
        return false;
}

template < class T, class C >
bool Grafo<T,C>::BuscarArista(unsigned long i, unsigned long j)
{
    if(m_costos.find(i) != m_costos.end())
    {
        auto const &ent1 = this->m_costos.second;
        if(ent1.find(j) != ent1.end())
            return true;
        else
            return false;
    }
    else
        return false;
}

template < class T, class C >
bool Grafo<T,C>::EliminarVertice(T v)
{
    if(BuscarVertice(v))
    {
        auto const &ent1 = this->m_costos.second;
        if(m_costos.erase(v) && ent1.erase(v))
            return true;
    }
    else
        return false;
}

template < class T, class C >
bool Grafo<T,C>::EliminarArista(unsigned long i, unsigned long j)
{
    if(BuscarVertice(i))
    {
        if(BuscarVertice(j))
        {
            m_costos[i][j]=0;
        }
        else
            return false;
    }
    else
        return false;
}



template< class T, class C >
vector<unsigned long> Grafo<T,C>::Dijkstra(unsigned long indiceInicio, unsigned long indiceFinal)
{
 vector<unsigned long> cola;
  TMarca marcas (this->l_vertices.size(), false);
  vector<long> predecesores (this->l_vertices.size(), -1);
  vector<C>distancias (this->l_vertices.size(), 99999999);
  vector<unsigned long> ruta;
  for(int i = 0; i < this->l_vertices.size();i++){
    cola.push_back(i);
  }
    
  distancias[indiceInicio] = 0;
  unsigned long indiceMenor;
  predecesores[indiceInicio] = indiceInicio;
  vector<unsigned long> temp;
  unsigned long contVertice = 0;
  while(contVertice != this->l_vertices.size()){
     C menor = 9;
     indiceMenor = 99999;
    for(int i = 0; i < l_vertices.size(); i++){
      if(!marcas[i]){
       if(distancias[i]< menor){
         menor = distancias[i];
         indiceMenor = i;
       }
      }
    }
    contVertice++;
    marcas[indiceMenor] = true;
    for(int i = 0 ; i < this->l_vertices.size(); i++){
      if(m_costos[indiceMenor][i] != 0 ){
        if(distancias[i] > (distancias[indiceMenor] + m_costos[indiceMenor][i])){
          distancias[i] = (distancias[indiceMenor] + m_costos[indiceMenor][i]);
          predecesores[i] = indiceMenor;
        }
      }
    }
  }
  if(marcas[indiceFinal]){
    unsigned long ind = indiceFinal;
    ruta.push_back(indiceFinal);
    while(predecesores[ind] != indiceInicio){
      ruta.push_back(predecesores[ind]);
      ind = predecesores[ind];
    }
    ruta.push_back(indiceInicio);
    reverse(ruta.begin(), ruta.end());
  }
  return ruta;
};

template<class T, class C>
vector<unsigned long> Grafo<T,C>::baseRemota(unsigned long indiceInicio){
  unsigned long indiceFinal=8;
   vector<unsigned long> cola;
  TMarca marcas (this->l_vertices.size(), false);
  vector< long> predecesores (this->l_vertices.size(), -1);
  vector<C>distancias (this->l_vertices.size(), 99999999);
  vector<unsigned long> ruta;
  for(int i = 0; i < this->l_vertices.size();i++){
    cola.push_back(i);
  }
    
  distancias[indiceInicio] = 0;
  unsigned long indiceMenor;
  predecesores[indiceInicio] = indiceInicio;
  vector<unsigned long> temp;
  unsigned long contVertice = 0;
  while(contVertice != this->l_vertices.size()){
     C menor = 9;
     indiceMenor = 99999;
    for(int i = 0; i < l_vertices.size(); i++){
      if(!marcas[i]){
       if(distancias[i]< menor){
         menor = distancias[i];
         indiceMenor = i;
       }
      }
    }
    contVertice++;
    marcas[indiceMenor] = true;
    for(int i = 0 ; i < this->l_vertices.size(); i++){
      if(m_costos[indiceMenor][i] != 0 ){
        if(distancias[i] > (distancias[indiceMenor] + (m_costos[indiceMenor][i]))*(-1)){
          distancias[i] = (distancias[indiceMenor] +( m_costos[indiceMenor][i])*-1);
          predecesores[i] = indiceMenor;
        }
      }
    }
  }
  vector<unsigned long> vertices;
  for(int i=0;i<l_vertices.size();i++)
  {
    if(l_vertices[i]==l_vertices[indiceInicio]&&(i!=indiceInicio))
    {
        vertices.push_back(i);
    }
  }
  unsigned long indiceMayor;
  C costoMayor = -1.0;
for(int i=0;i<vertices.size();i++)
{
    if(marcas[vertices[i]]){
    unsigned long ind = vertices[i];
    ruta.push_back(vertices[i]);
    while(predecesores[ind] != indiceInicio){
      ruta.push_back(predecesores[ind]);
      ind = predecesores[ind];
      
    }
    ruta.push_back(indiceInicio);
    reverse(ruta.begin(), ruta.end());
  }
  C cosTotal=0.0;
  for(unsigned int j = 0; j < ruta.size( ) - 1; ++j )
  {
      cosTotal += ObtenerCostoArista( ruta[ j ], ruta[ j + 1 ] );
  }
  if(cosTotal > costoMayor){
    costoMayor = cosTotal;
    indiceMayor = vertices[i];
  }
  ruta.clear();
}
  if(marcas[indiceMayor]){
      unsigned long ind = indiceMayor;
      ruta.push_back(indiceMayor);
      while(predecesores[ind] != indiceInicio){
        ruta.push_back(predecesores[ind]);
        ind = predecesores[ind];
        
      }
      ruta.push_back(indiceInicio);
      reverse(ruta.begin(), ruta.end());
    }
  return ruta;
};
