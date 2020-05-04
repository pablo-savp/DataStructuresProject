#include "linea.h"
#include <bits/stdc++.h>
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

int linea::enmascararLinea(char n[]){
  int pos;
  int repetidas;
  int cantEnmascaradas = 0;
  for(int i=0; i<lin.size();i++){
    if(lin[i]==n[0]){
      pos = i;
      repetidas=1;
      for(int i=1; i < strlen(n);i++){
        if(lin[pos+i]==n[i]){
          repetidas++;
        }
      }
      if(repetidas==strlen(n)){
        for(int i =0; i < strlen(n); i++){
          lin[i+pos] = 'X';
        }
        cantEnmascaradas++;
      }
      repetidas = 0;
    }
  }
  return cantEnmascaradas;
};

int linea::contarSubSecuencias(char n[]){
  int pos;
  int repetidas;
  int cantAparacidas = 0;
  for(int i=0; i<lin.size();i++){
    if(lin[i]==n[0]){
      pos = i;
      repetidas=1;
      for(int i=1; i < strlen(n);i++){
        if(lin[pos+i]==n[i]){
          repetidas++;
        }
      }
      if(repetidas==strlen(n)){
        cantAparacidas++;
      }
      repetidas = 0;
    }
  }
  return cantAparacidas;
}

