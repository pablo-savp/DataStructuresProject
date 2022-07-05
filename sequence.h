#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <vector>
#include <string.h>
#include <iostream>
#include "linea.h"
#include "Grafo.h"

using namespace std;
class sequence
{
protected:
    char nombre[1000];
    vector<linea> seq;
    int base;
    char identificador;

public:
    sequence();
    char* obtenerNombre();
    vector<linea> obtenerSeq();
    void ponerSequence(vector<linea> temp);
    int obtenerBase();
    void ponerBase(int b);
    char obtenerIdentificador();
    vector<linea> obtenerLineas();
    void ponerIdentificador(char c);
    void ponerNombre(char n[]);
    void ponerSeq(linea v);
    int contarFrecuencias(char n[]);
    void listarSeq();
    vector<int> contarFrecuencias();
    int enmascararSeq(char n[]);
    int listarseq();
    Grafo<char,double> crearGrafo();
};

#include "sequence.hxx"

#endif