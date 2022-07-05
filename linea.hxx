#include "linea.h"
using namespace std;
linea::linea()
{

};
vector<char> linea::obtenerLinea()
{
    return lin;

};

void linea::ponerLinea(vector<char> v)
{
    lin=v;
};

void linea::enmascararLinea(int pos){
  lin[pos] = 'X';
};

