#ifndef LINEA_H
#define LINEA_H
#include <vector>
#include <string.h> 
using namespace std;
class linea
{
protected:
    vector<char> lin;
public:
    linea();
    vector<char> obtenerLinea();
    void ponerLinea(vector<char> v);
    void enmascararLinea(int pos);
};

#include "linea.hxx"

#endif