#include "sequence.h"
#include "linea.h"
#include <bits/stdc++.h>
using namespace std;
sequence::sequence(){
};

char* sequence::obtenerNombre(){
return nombre;
};

void sequence::ponerNombre(char n[]){
strcpy(nombre,n);

};
void sequence::ponerSeq(linea v){
  seq.push_back(v);
};
void sequence::ponerSequence(vector<linea> v){
  seq=v;
};
vector<linea> sequence::obtenerSeq(){
  return seq;
};

int sequence::obtenerBase(){
return base;
};
void sequence::ponerBase(int b){
  base=b;
};
char sequence::obtenerIdentificador(){
  return identificador;
};
void sequence::ponerIdentificador(char c){
  identificador=c;
};
vector<linea> sequence::obtenerLineas(){
  return seq;
};
void sequence::listarSeq(){

  vector<char> codigosc;
  codigosc.push_back('A');
  codigosc.push_back('C');
  codigosc.push_back('U');
  codigosc.push_back('G');
  codigosc.push_back('T');
  codigosc.push_back('R');
  codigosc.push_back('Y');
  codigosc.push_back('K');
  codigosc.push_back('M');
  codigosc.push_back('S');
  codigosc.push_back('W');
  codigosc.push_back('B');
  codigosc.push_back('D');
  codigosc.push_back('V');
  codigosc.push_back('H');
  codigosc.push_back('N');
  codigosc.push_back('X');
  vector<char> codigosi;
  codigosi.push_back('-');
  int cont=0;

  vector<char>::iterator it4=codigosi.begin();
  bool incompleta=false;
  for(;it4!=codigosi.end();it4++){
       vector<linea>::iterator it=seq.begin();    
      for(;it!=seq.end();it++){
    vector<char> temp=it->obtenerLinea();
    vector<char>::iterator it2=temp.begin();
    for(;it2!=temp.end();it2++){
        if(*it2==*it4){
          incompleta=true;
        }
    }
  }

  }
if(incompleta==true){
  identificador='I';
  
}else{
  identificador='C';
}

int conporbase=0;
  vector<char>::iterator it3=codigosc.begin();


  for(;it3!=codigosc.end();it3++){
    conporbase=0;
      vector<linea>::iterator it=seq.begin();
  for(;it!=seq.end();it++){
    vector<char> temp=it->obtenerLinea();
    vector<char>::iterator it2=temp.begin();
    for(;it2!=temp.end();it2++){
        if(*it2==*it3){
          cont++;
          conporbase++;
          
          break;
        }
    }
    if(conporbase==1){
      break;
    }
    
  }
 
  }
    base=cont;
};
vector<int> sequence::contarFrecuencias()
{
    vector<char> codigos;
    codigos.push_back('A');
    codigos.push_back('C');
    codigos.push_back('U');
    codigos.push_back('G');
    codigos.push_back('T');
    codigos.push_back('R');
    codigos.push_back('Y');
    codigos.push_back('K');
    codigos.push_back('M');
    codigos.push_back('S');
    codigos.push_back('W');
    codigos.push_back('B');
    codigos.push_back('D');
    codigos.push_back('V');
    codigos.push_back('H');
    codigos.push_back('N');
    codigos.push_back('X');
    codigos.push_back('-');
    
    vector<char>::iterator codes=codigos.begin();
    vector<int> repeticiones;
    vector<linea> moverse = seq;
    vector<char> temp;
    vector<char>::iterator iC;
    vector<linea>::iterator M1=moverse.begin();
    for(; codes!=codigos.end(); codes++)
    {
      int repetidos=0;
      M1=moverse.begin();
        for(; M1!=moverse.end(); M1++)
        {
            temp=M1->obtenerLinea();
            iC=temp.begin();
            for(; iC!=temp.end(); iC++)
            {
                if(*codes==*iC)
                {
                    repetidos++;
                }
            }
        }
        repeticiones.push_back(repetidos);
    }
    return repeticiones;
};

int sequence::contarFrecuencias(char n[]){
  int cantRepetidas = 0;
  vector<linea>::iterator lineas = seq.begin();
  vector<char> linea;
  for(; lineas != seq.end(); lineas++){
    cantRepetidas += lineas->contarSubSecuencias(n);
  }
  return cantRepetidas;
}

int sequence::enmascararSeq(char n[]){
  int cantEnmascaradas = 0;
  vector<linea>::iterator lineas = seq.begin();
  vector<char> linea;
  for(; lineas != seq.end(); lineas++){
    cantEnmascaradas += lineas->enmascararLinea(n);
  }
  return cantEnmascaradas;
};

int sequence::listarseq(){
  vector<linea>::iterator it= seq.begin();
  int acum=0;
  for(;it!=seq.end();it++)
  {
    acum=acum+it->obtenerLinea().size();
  }
  return acum;
};