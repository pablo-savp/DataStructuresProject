#ifndef LINEA_H
#define LINEA_H
#include <bits/stdc++.h>
using namespace std;
class linea
{
protected:
    vector<char> lin;
public:
    linea();
    vector<char> obtenerLinea();
    void ponerLinea(vector<char> v);
    int enmascararLinea(char n[]);
    int contarSubSecuencias(char n[]);
};

#include "linea.hxx"

#endif