#include "sequence.h"
#include <math.h>
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
void sequence::ponerSequence(vector<linea> temp){
  seq = temp;
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
  int pos;
  int repetidas;
  vector<linea>::iterator lineas = seq.begin();
  vector<char> lin;
  vector<linea> seqTemp;
  vector<char>secuenTemp;
  for(; lineas != seq.end(); lineas++){
      lin = lineas->obtenerLinea();
      for(int i = 0; i < lin.size(); i++){
        secuenTemp.push_back(lin[i]);
      }
   }
   for(int i = 0; i < secuenTemp.size();i++){
     if(secuenTemp[i]==n[0]){
       pos = i;
       repetidas = 1;
       for(int j = 1; j < strlen(n); j++){
         if(secuenTemp[pos+j]==n[j]){
            repetidas++;
         }
       }
       if(repetidas == strlen(n)){
         cantRepetidas++;
       }
       repetidas = 0;
     }
   }
  return cantRepetidas;
}

int sequence::enmascararSeq(char n[]){
  int cantEnmascaradas = 0;
  int pos;
  int repetidas;
  vector<linea>::iterator lineas = seq.begin();
  vector<char> lin;
  vector<linea> seqTemp;
  vector<char>secuenTemp;
  for(; lineas != seq.end(); lineas++){
      lin = lineas->obtenerLinea();
      for(int i = 0; i < lin.size(); i++){
        secuenTemp.push_back(lin[i]);
      }
   }
   for(int i = 0; i < secuenTemp.size();i++){
     if(secuenTemp[i]==n[0]){
       pos = i;
       repetidas = 1;
       for(int j = 1; j < strlen(n); j++){
         if(secuenTemp[pos+j]==n[j]){
            repetidas++;
         }
       }
       if(repetidas == strlen(n)){
         for(int j = 0; j < strlen(n);j++){
           secuenTemp[j+pos] = 'X';
         }
         cantEnmascaradas++;
       }
       repetidas = 0;
     }
   }
   int temp = 0;
   for(lineas = seq.begin(); lineas != seq.end(); lineas++){
     lin = lineas->obtenerLinea();
      for(int i = 0; i < lin.size(); i++){
        if(secuenTemp[temp] == 'X'){
          lineas->enmascararLinea(i);
        }
        temp++;
      }
   }
  return cantEnmascaradas;
};

int sequence::listarseq(){
  vector<linea>::iterator it= seq.begin();
  vector<char> caracteres;
  int acum=0;
  for(;it!=seq.end();it++)
  {
    caracteres = it->obtenerLinea();
    for(int i = 0; i < caracteres.size();i++){
      if(caracteres[i] != '-'){
        acum++;
      }
    }
  }
  return acum;
};
Grafo<char,double> sequence::crearGrafo(){

  Grafo<char,double> t;
    
    vector<linea>::iterator it=seq.begin();
    for(;it!=seq.end();it++)
    {
      vector<char> temp= it->obtenerLinea();
      for(int i=0;i<temp.size();i++)
      {
          t.InsertarVertice(temp[i]);
      }
    }
    int verticeH=0;
    float n;
   //cout<<t.ObtenerNumVertices()<<endl;
   for(int i=0;i<seq.size();i++)
   {
     for(int j=0;j<seq[i].obtenerLinea().size();j++)
     {
       if(verticeH<t.ObtenerNumVertices()&&(verticeH+1)!=((seq[0].obtenerLinea().size()*(i+1))-((seq[0].obtenerLinea().size()-(seq[i].obtenerLinea().size())))))
       {
         // n=1/(1+abs((int(t.ObtenerVertice(verticeH))-int(t.ObtenerVertice(verticeH+1)))));
          //cout<<n<<endl;
          double resta1=(int(t.ObtenerVertice(verticeH))-int(t.ObtenerVertice(verticeH+1)));
          double a =1/(1+abs(resta1));
          double resta2=(int(t.ObtenerVertice(verticeH+1))-int(t.ObtenerVertice(verticeH)));
          double b=1/(1+abs(resta2));
          //cout<<a<<"+"<<endl;
        // cout<<verticeH<<"+"<<verticeH+1<<endl;
          t.InsertarArista(verticeH,verticeH+1,a);
          t.InsertarArista(verticeH+1,verticeH,b);
          
       }
       verticeH++;
     }
   }
   //cout<<t.ObtenerNumerodeAristas()<<endl;

 for(int i=0;i<seq.size();i++)  
   {

     for(int j=0;j<seq[i].obtenerLinea().size();j++)
     {
      if(i<(seq.size()-1))
      {
        if(j<seq[i+1].obtenerLinea().size())
        {
          
          unsigned long verticeA=((seq[0].obtenerLinea().size()*(i+1))-(seq[0].obtenerLinea().size()-((j-1)+1)));
          unsigned long verticeB=((seq[0].obtenerLinea().size()*(i+1+1))-(seq[0].obtenerLinea().size()-((j-1)+1)));
          //cout<<)<<" + ";
          //cout<<<<endl;
          double negativo=t.ObtenerVertice(verticeA)-t.ObtenerVertice(verticeB);
          double negativo2=t.ObtenerVertice(verticeB)-t.ObtenerVertice(verticeA);
          double va=1/(1+abs(negativo));
          double vb=1/(1+abs(negativo2));
           t.InsertarArista(verticeA,verticeB,va);
          t.InsertarArista(verticeB,verticeA,vb);
        }
        
      }
       
       

     }


   }
  
 //cout<<t.ObtenerNumerodeAristas()<<endl;
return t;
};