#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "tablaCodigos.h"
#include "Nodo.h"
#include <bits/stdc++.h>
#include "sequence.h"
class archivo
{
protected:
    vector<sequence> sequences;
    Nodo *nodoArbol;
    tablaCodigos *tablasBits;
    Nodo *listaBases;
public:
    archivo();
    vector<sequence> obtenerArchivo();
    
    void ponerArchivo(vector<sequence> c);
    int leerArchivo(char nombre[]);
    bool guardarArchivo(char nombre[]);
    void imprimirsequencias();
    void listarSeq();
    int subSeq(char n[]);
    int contarSeq();
    vector<int> contarFrecuencias(char n[]);
    sequence buscarSecuencia(char n[]);
    int enmascarar(char n[]);
    vector<int> listarseq();
    Nodo* cargarArchivo(char n[]);
    void Codificar(char n[]);
    void BasesCont(Nodo* &ListaBases, char d);
    void ListaOrd(Nodo* &ListaBases);
    void PonerOrden(Nodo* &NodoInicial, Nodo *n);
    void crearTablaCodigos(Nodo *nodo, int numBits, int codigo);
    void insertarTablaCodigos(char base, int numBits, int codigo,int frecuencia);
    tablaCodigos* buscaCaracter( char c);
};

#include "archivo.hxx"

#endif