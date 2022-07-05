#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "archivo.h"
#include "sequence.h"
#include "Grafo.h"
#include "linea.h"
#include "Nodo.h"
#include "tablaCodigos.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>
class archivo
{
protected:
    vector<sequence> sequences;
    Nodo *nodoArbol;
    tablaCodigos *tablasBits;
    Nodo *listaBases;
    vector<Grafo<char,double>> grafos;
    vector<unsigned long> ruta;
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
    bool Codificar(char n[]);
    bool Decodificar(char n[]);
    void BasesCont(Nodo* &ListaBases, char d);
    void ListaOrd(Nodo* &ListaBases);
    void PonerOrden(Nodo* &NodoInicial, Nodo *n);
    void crearTablaCodigos(Nodo *nodo, int numBits, int codigo);
    void insertarTablaCodigos(char base, int numBits, int codigo,int frecuencia);
    long BuscarIndiceVertice(unsigned long i, unsigned long j, char n[]);
    tablaCodigos* buscaCaracter(char c);
    bool llenarGrafos();
    int RutaMasCorta(char n[], unsigned long i, unsigned long j, unsigned long x, unsigned long y);
    int BaseRemota(char n[], unsigned long i, unsigned long j);
    void ImprimirRutaCorta();
    void ImprimirCosto(char n[]);
    vector<long> EncontrarAB(unsigned long indiceFinal, char n[]);
    unsigned long ObtenerIndiceFinal();
};

#include "archivo.hxx"

#endif