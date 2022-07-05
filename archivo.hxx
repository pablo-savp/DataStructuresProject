#include "archivo.h"
#define MAXI 1000000
using namespace std;

archivo::archivo()
{
    sequences.clear();
};
vector<sequence> archivo::obtenerArchivo()
{
    return sequences;
};
void archivo::ponerArchivo(vector<sequence> c)
{
    sequences=c;
}
int archivo::leerArchivo(char nombre[])
{
    sequence secuencia;
    char palabras[MAXI];
    bool bandera=false;
    archivo arch;
    int verificar=0;
    bool verificarultima=true;
    vector <char> temp;
    linea frecu;
    int abrir=-1;
    ifstream archO(nombre, ios::in);
    if(archO.is_open())
    {
        archivo borrar;
        sequences=borrar.obtenerArchivo();

        archO.seekg(0,ios::end);
        if(archO.tellg()!=0)
        {
            abrir=1;
            archO.seekg(0,ios::beg);
            while(!archO.eof())
            {

                if(archO.getline(palabras, sizeof(palabras), '\n'))
                {

                    if(palabras[0]=='>')
                    {

                        if(bandera==true)
                        {
                            verificar=0;
                            verificarultima=true;

                            vector<linea> verificarjustifi=secuencia.obtenerSeq();
                            vector<linea>::iterator now=verificarjustifi.begin();
                            int justificacion=now->obtenerLinea().size();
                            int numlineas=verificarjustifi.size();
                            int cont=1;
                            for(; now!=verificarjustifi.end(); now++)
                            {
                                if((now->obtenerLinea().size()!=justificacion))
                                {
                                    verificar++;
                                    verificarultima=false;
                                    if(cont==numlineas&&now->obtenerLinea().size()<=justificacion&&verificar==1)
                                    {
                                        verificarultima=true;

                                    }

                                }
                                cont++;
                            }
                            if(verificarultima)
                            {
                                sequences.push_back(secuencia);
                            }
                        }
                        if(bandera==false)
                        {
                            bandera=true;
                        }

                        char aux[MAXI];
                        secuencia.obtenerSeq().clear();
                        strcpy(aux,strtok(palabras, ">"));
                        secuencia.ponerNombre(aux);

                        strcpy(palabras,"");
                        linea f;
                        frecu.ponerLinea(f.obtenerLinea());
                        sequence s;
                        secuencia.ponerSequence(s.obtenerSeq());

                    }
                    else
                    {


                        for(int i=0 ; i<strlen(palabras); i++)
                        {
                            temp.push_back(palabras[i]);
                        }
                        strcpy(palabras,"");
                        frecu.ponerLinea(temp);
                        secuencia.ponerSeq(frecu);
                        temp.clear();
                    }
                    strcpy(palabras,"");
                }

            }
            verificar=0;
            verificarultima=true;
            vector<linea> verificarjustifi=secuencia.obtenerSeq();
            vector<linea>::iterator now=verificarjustifi.begin();
            int justificacion=now->obtenerLinea().size();
            int numlineas=verificarjustifi.size();
            int cont=1;

            for(; now!=verificarjustifi.end(); now++)
            {
                if((now->obtenerLinea().size()!=justificacion))
                {
                    verificar++;
                    verificarultima=false;
                    if(cont==numlineas&&now->obtenerLinea().size()<=justificacion&&verificar==1)
                    {
                        verificarultima=true;

                    }

                }
                cont++;
            }
            if(verificarultima)
            {
                sequences.push_back(secuencia);
            }
        }
        else
        {
            abrir=0;
        }




        archO.close();

    }
    else
    {
        // cout<<"No se pudo abrir el archivo :("<<endl;
    }
//imprimirsequencias();


   if(abrir!=-1) {
     llenarGrafos();
   }
    return abrir;
};
void archivo::imprimirsequencias()
{
    cout<<sequences.size()<<endl;
    vector<sequence>::iterator it=sequences.begin();
    for(; it!=sequences.end(); it++)
    {
        cout<<it->obtenerNombre()<<endl;
        vector<linea> temo=it->obtenerSeq();
        vector<linea>::iterator it2=temo.begin();
        for(; it2!=temo.end(); it2++)
        {
            vector<char> temo2=it2->obtenerLinea();
            vector<char>::iterator it3=temo2.begin();
            for(; it3!=temo2.end(); it3++)
            {
                cout<<*it3;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
void archivo::listarSeq()
{
    vector<sequence>::iterator it=sequences.begin();
    for(; it!=sequences.end(); it++)
    {
        it->listarSeq();
    }

};
int archivo::subSeq(char n[])
{
    int numSecuencias = 0;
    vector<sequence>::iterator it=sequences.begin();
    if(sequences.size()!=0)
    {
        for(; it!=sequences.end(); it++)
        {
            numSecuencias+=it->contarFrecuencias(n);
        }
    }

    return numSecuencias;
};
int archivo::contarSeq()
{
    return sequences.size();
};
vector<int>archivo::contarFrecuencias(char n[])
{
    sequence sec=buscarSecuencia(n);
    vector<int> repetidosXsecuencia;
    if(sec.obtenerLineas().size()!=0)
    {
        repetidosXsecuencia = sec.contarFrecuencias();
    }
    return repetidosXsecuencia;

};

sequence archivo::buscarSecuencia(char n[])
{
    sequence s;
    vector<sequence>:: iterator iSec = sequences.begin();
    for(; iSec!=sequences.end(); iSec++)
    {
        if(strcmp(iSec->obtenerNombre(),n)==0)
        {
            s=*iSec;
        }
    }
    return  s;
};
bool archivo::guardarArchivo(char nombre[])
{
    fstream archiG;
    archiG.open(nombre, ios::out);
    if(archiG.is_open())
    {
        string mayor=">";
        vector<sequence>:: iterator iSec=sequences.begin();
        bool b=true;
        for(; iSec!=sequences.end(); iSec++)
        {
            vector<linea> l=iSec->obtenerLineas();
            vector<linea>:: iterator iLinea=l.begin();
            archiG<<mayor;
            string nombre=iSec->obtenerNombre();
            archiG<<nombre<<endl;
            for(; iLinea!=l.end(); iLinea++)
            {
                vector<char> c=iLinea->obtenerLinea();
                vector<char>:: iterator iCod=c.begin();
                for(; iCod!=c.end(); iCod++)
                {
                    archiG.put(*iCod);
                }
                string salto="\n";
                if((iCod)==c.end()&&(iLinea+1)==l.end()&&(iSec+1)==sequences.end())
                {
                    b=false;
                }
                if(b==true)
                {
                    archiG<<salto;
                }


            }
        }
        return true;
    }
    else
    {
        return false;
    }
    archiG.close();
};

int archivo::enmascarar(char n[])
{
    int numSecuencias = 0;
    vector<sequence>::iterator it=sequences.begin();
    if(sequences.size()!=0)
    {
        for(; it!=sequences.end(); it++)
        {
            numSecuencias+=it->enmascararSeq(n);
        }
    }

    return numSecuencias;
};
vector<int> archivo::listarseq()
{
    int acum=0;
    vector<int> temp;
    vector<sequence>::iterator it=sequences.begin();
    for(; it!=sequences.end(); it++)
    {
        temp.push_back(it->listarseq());
    }

    return temp;
};

bool archivo::Codificar(char n[])
{

    int j=1;

//cout<<sequences.size()<<endl;
    vector<sequence>::iterator it=sequences.begin();
    for(; it!=sequences.end(); it++)
    {
        //cout<<it->obtenerNombre()<<endl;
        vector<linea> temo=it->obtenerSeq();
        vector<linea>::iterator it2=temo.begin();
        for(; it2!=temo.end(); it2++)
        {
            vector<char> temo2=it2->obtenerLinea();
            vector<char>::iterator it3=temo2.begin();
            for(; it3!=temo2.end(); it3++)
            {
                BasesCont(listaBases,*it3);
                j++;
            }
            //cout<<endl;
        }
        //cout<<endl;
    }
    ListaOrd(listaBases);

    Nodo *aux = listaBases;
    int i = 0;
    while (aux != NULL)
    {
        int ascci=aux->base;
        string resultado = "v" +to_string(ascci)  + "f" +to_string(aux->frecuencia) ; // concatenar

        strcpy(aux->codigo,resultado.c_str());
        if(aux->sig->sig==NULL)
        {
            aux->sig=NULL;
        }
        aux=aux->sig;
    }

    nodoArbol=listaBases;
    Nodo* nuevo;

    while(nodoArbol && nodoArbol->sig)
    {
        nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->base = 0;
        nuevo->der = nodoArbol;
        nodoArbol = nodoArbol->sig;
        nuevo->izq = nodoArbol;
        nodoArbol = nodoArbol->sig;
        nuevo->frecuencia = nuevo->der->frecuencia + nuevo->izq->frecuencia;
        PonerOrden(nodoArbol, nuevo);
    }


    tablasBits=NULL;
    crearTablaCodigos(nodoArbol, 0, 0);

    FILE *archivoBIN;
    archivoBIN=fopen(n,"wb");
    if(!archivoBIN)
    {
        return false;
    }
    int nElementos = 0;
    tablaCodigos *auxTabla = tablasBits;
    while(auxTabla)
    {
        nElementos++;
        auxTabla = auxTabla->sig;
    }

    fwrite(&nElementos, sizeof(int)-2, 1, archivoBIN);
    auxTabla = tablasBits;
    while(auxTabla)
    {
        fwrite(&auxTabla->base, sizeof(char), 1, archivoBIN);
        fwrite(&auxTabla->frecuencias, sizeof(long int), 1, archivoBIN);

        auxTabla = auxTabla->sig;
    }
    int cantSeq = contarSeq();
    fwrite(&cantSeq, sizeof(int),1, archivoBIN);
    int tamNombre;
    char* nombreSecuencia;
    for(int ind = 0; ind < sequences.size(); ind++)
    {
        tamNombre= strlen(sequences[ind].obtenerNombre());
        fwrite(&tamNombre, sizeof(int)-2, 1, archivoBIN);

        nombreSecuencia=sequences[ind].obtenerNombre();
        fputs(nombreSecuencia,archivoBIN);
    }
    vector<int> longSeq=listarseq();
    vector<linea> auxLinea;
    vector<char> auxCaracteres;
    int indentacion;
    tablaCodigos *tabla;
    int acumBits=0;
    int valor=0;
    char caracter;
    for(int ind = 0; ind < sequences.size(); ind++)
    {
        fwrite(&longSeq[ind], sizeof(long int), 1, archivoBIN);
        cout<<"Longitud: "<<longSeq[ind]<<endl;
        auxLinea = sequences[ind].obtenerLineas();
        auxCaracteres = auxLinea[0].obtenerLinea();
        indentacion = auxCaracteres.size();

        fwrite(&indentacion, sizeof(int)-2, 1, archivoBIN);
        for(int Jind = 0 ; Jind < auxLinea.size(); Jind++)
        {
            auxCaracteres = auxLinea[Jind].obtenerLinea();
            for(int Xind = 0 ; Xind < auxCaracteres.size(); Xind++)
            {
                caracter = auxCaracteres[Xind];
                tabla = buscaCaracter(caracter);
                while(acumBits + tabla->xbits > 32)
                {
                    caracter = valor >>(acumBits-8);
                    fwrite(&caracter,sizeof(char),1,archivoBIN);
                    acumBits-=8;
                }
                valor <<= tabla->xbits;
                valor |= tabla->bits;
                acumBits += tabla->xbits;
            }
        }
        while(acumBits>0)
        {
            if(acumBits>=8)
            {
                caracter = valor >> (acumBits-8);
            }
            else
            {
                caracter = valor << (8-acumBits);
            }
            fwrite(&caracter, sizeof(char), 1, archivoBIN);
            acumBits -= 8;
        }
        indentacion = 0;
    }
    fclose(archivoBIN);
    return true;

};

bool archivo::Decodificar(char n[])
{

///////////////////////////////////////////////////////
    long int longitud;
    int cantBases;
    tablaCodigos *r, *s;
    int i,j;
// listaBases = NULL;
    FILE* ArchivoBIN;
//cout<<"antes de abrir";
    ArchivoBIN = fopen(n, "rb");
    if(!ArchivoBIN)
    {
        return false;
    }

    fread(&cantBases, sizeof(int)-2, 1, ArchivoBIN);

    Nodo *aux = listaBases;
    char auxBase;
    long int auxFrecuencias;
    for(int p=0; p<cantBases; p++)
    {
        Nodo *nuevo;
        nuevo = new Nodo();
        fread(&auxBase, sizeof(char), 1, ArchivoBIN);
        // cout<<"car:"<<auxBase<<endl;
        fread(&auxFrecuencias, sizeof(long int), 1, ArchivoBIN);
        //cout<<"frec:"<<auxFrecuencias<<endl;

        nuevo->frecuencia = auxFrecuencias;
        nuevo->base = auxBase;

        aux->sig=nuevo;

        aux=aux->sig;

    }
    ListaOrd(listaBases);

    Nodo *aux2 = listaBases;
    while (aux2 != NULL)
    {
        if(aux2->sig->sig==NULL)
        {
            aux2->sig=NULL;
        }
        // cout<<"Base:"<<aux2->base<<"    Frec:"<<aux2->frecuencia<<endl;;
        aux2=aux2->sig;
    }
    ////////////////////////////////////////////////////////////////
    nodoArbol=listaBases;
    Nodo* nuevo;
    while(nodoArbol && nodoArbol->sig)
    {
        nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->base = 0;
        nuevo->der = nodoArbol;
        nodoArbol = nodoArbol->sig;
        nuevo->izq = nodoArbol;
        nodoArbol = nodoArbol->sig;
        nuevo->frecuencia = nuevo->der->frecuencia + nuevo->izq->frecuencia;
        PonerOrden(nodoArbol, nuevo);
    }


    tablasBits=NULL;
    crearTablaCodigos(nodoArbol, 0, 0);
    //   tablaCodigos *auxTabla = tablasBits;
    //   while(auxTabla != NULL){
    //    cout<<"Base: "<<auxTabla->base<<" Codigo: "<<auxTabla->bits<<" cantBits: "<<auxTabla->xbits<<endl;
    //    auxTabla=auxTabla->sig;
    //  }

    int cantSecuencias;
    char nombreSecuencia;
    fread(&cantSecuencias, sizeof(int), 1, ArchivoBIN);

    char c;
    char nombre[100];
    int tamNombre=0;
    int acum;
    for(int s=0; s<cantSecuencias; s++)
    {
        char nombre[100];
        sequence secuencia;
        fread(&tamNombre, sizeof(int)-2, 1, ArchivoBIN);
        for(int n=0; n<tamNombre; n++)
        {
            fread(&c, sizeof(char), 1, ArchivoBIN);
            nombre[n]=c;

        }



        // cout<<"Nombre:"<<nombre<<endl;

        secuencia.ponerNombre(nombre);
        for(int i=0; i<100; i++)
        {
            nombre[i]='\0';
        }
        // cout<<"Nombre secuencia:"<<secuencia.obtenerNombre()<<endl;

        sequences.push_back(secuencia);
    }

    long int bits;
    vector<int>longitudes;
    vector<int>indentaciones;
    long int longSecuencia;
    int indentacionSecuencia;
    aux = nodoArbol;
    int num2;
    int cont2 = 0;
    char aBase;
    vector<sequence>::iterator ms=sequences.begin();
    for(int t=0; t<cantSecuencias; t++)
    {
        vector<char> nuevoCarac;
        linea nuevoLineas;
        vector<linea> nuevoLineas2;
        fread(&longSecuencia, sizeof(long int), 1, ArchivoBIN);
        fread(&indentacionSecuencia, sizeof(int)-2,1, ArchivoBIN);

        longitudes.push_back(longSecuencia);
        indentaciones.push_back(indentacionSecuencia);

        for(int i=0; i<longSecuencia; i++)
        {

            if(bits & 0x80000000)
            {
                aux = aux->der;
            }
            else
            {
                aux = aux->izq;
            }
            bits <<= 1;
            j++;
            if(8 == j)
            {
                num2 = fread(&auxBase, sizeof(char), 1, ArchivoBIN);
                bits |= auxBase;
                j = 0;
            }
            if(!aux->der && !aux->izq)
            {
                aBase=aux->base;
                aux=nodoArbol;
            }
            if(cont2 < indentacionSecuencia)
            {
                nuevoCarac.push_back(aBase);
                cont2++;
            }
            else
            {

                nuevoLineas.ponerLinea(nuevoCarac);
                nuevoLineas2.push_back(nuevoLineas);
                nuevoCarac.clear();
                cont2 = 0;
                i--;
            }

        }
        ms->ponerSequence(nuevoLineas2);
        ms++;


        nuevoLineas2.clear();
    }

    tablaCodigos* taux;
    taux=tablasBits;
    while(taux!=NULL)
    {
        taux->base='\0';
        taux->bits=0;
        taux->xbits=0;
        taux->frecuencias=0;
        taux=taux->sig;
    }
    Nodo* laux;
    laux=listaBases;
    while(laux!=NULL)
    {
        laux->base='\0';
        laux->frecuencia=0;

        laux=laux->sig;
    }
    free(nodoArbol);
    free(tablasBits);
    return true;

};

void archivo::BasesCont(Nodo* &ListaBases, char d)
{

    Nodo *w, *e, *r;


    if(!ListaBases)
    {
        ListaBases = (Nodo *)malloc(sizeof(Nodo));
        ListaBases->base = d;
        ListaBases->frecuencia = 1;
        ListaBases->sig = ListaBases->izq = ListaBases->der = NULL;
    }
    else
    {

        w = ListaBases;
        e = NULL;
        while(w && w->base < d)
        {
            e = w;
            w = w->sig;
        }


        if(w && w->base == d)
            w->frecuencia++;
        else

        {

            r = (Nodo *)malloc(sizeof(Nodo));
            r->base = d;
            r->frecuencia = 1;
            r->izq = r->der = NULL;
            r->sig = w;
            if(e)
                e->sig = r;
            else
                ListaBases = r;
        }
    }

};


void archivo::ListaOrd(Nodo* &ListaBases)
{
    Nodo *ListaBases2, *b;

    if(!ListaBases)
        return;
    ListaBases2 = ListaBases;
    ListaBases = NULL;
    while(ListaBases2)
    {
        b = ListaBases2;
        ListaBases2 = b->sig;
        PonerOrden(ListaBases, b);
    }
};



void archivo::PonerOrden(Nodo* &NodoInicial, Nodo *n)
{
    Nodo *b, *f;

    if(!NodoInicial)
    {
        NodoInicial = n;
        NodoInicial->sig = NULL;
    }
    else
    {

        b = NodoInicial;
        f = NULL;
        while(b && b->frecuencia < n->frecuencia)
        {
            f = b;
            b = b->sig;
        }

        n->sig = b;
        if(f)
            f->sig = n;
        else
            NodoInicial = n;
    }
};

void archivo::crearTablaCodigos(Nodo *nodo, int numBits, int codigo)
{
    if(nodo->der)
    {
        crearTablaCodigos(nodo->der, numBits+1, (codigo<<1)|1);
    }

    if(nodo->izq)
    {
        crearTablaCodigos(nodo->izq, numBits+1, codigo<<1);
    }


    if(!nodo->der && !nodo->izq)
    {
        insertarTablaCodigos(nodo->base, numBits, codigo, nodo->frecuencia);
    }

};

void archivo::insertarTablaCodigos(char base, int numBits, int codigo, int frecuencia)
{
    tablaCodigos *nuevaTabla, *tabla2, *tabla3;
    nuevaTabla=(tablaCodigos *)malloc(sizeof(tablaCodigos));
    nuevaTabla->base = base;
    nuevaTabla->bits = codigo;
    nuevaTabla->xbits = numBits;
    nuevaTabla->frecuencias = frecuencia;

    if(!tablasBits)
    {
        tablasBits = nuevaTabla;
        tablasBits->sig = NULL;
    }
    else
    {
        tabla2 = tablasBits;
        tabla3 = NULL;
        while(tabla2 && tabla2->base < nuevaTabla->base)
        {
            tabla3 = tabla2;
            tabla2= tabla2->sig;
        }
        nuevaTabla->sig = tabla2;
        if(tabla3)
            tabla3->sig = nuevaTabla;
        else
            tablasBits = nuevaTabla;
    }
};

tablaCodigos* archivo::buscaCaracter(char c)
{
    tablaCodigos *t;

    t = tablasBits;
    while(t && t->base != c)
        t = t->sig;
    return t;
};
 bool archivo::llenarGrafos(){
   vector<sequence>::iterator ms=sequences.begin();
for(;ms!=sequences.end();ms++)
{
  grafos.push_back(ms->crearGrafo());
}
 
 return true;
 };

long archivo::BuscarIndiceVertice(unsigned long i, unsigned long j,char n[] ){

  long indVertice = -1;
  long retornar = -1;
  vector<linea> seq = buscarSecuencia(n).obtenerSeq();
  vector<char> car;

  for(long f = 0 ; f < seq.size(); f++){
    car = seq[f].obtenerLinea();
    for(long c = 0;c <car.size(); c++){
      indVertice++;
      if(f == i && c == j){
        return indVertice;
      }
    }
  }

  return retornar;
};



int archivo::RutaMasCorta(char n[], unsigned long i, unsigned long j, unsigned long x, unsigned long y){

  unsigned long inicio = 0;
  unsigned long fin = 0;
  this->ruta.clear();
   for(int a = 0; a < this->sequences.size(); a++){
     if(strcmp(n, sequences[a].obtenerNombre())==0){
       if(BuscarIndiceVertice(i,j,n)!= -1){
         if(BuscarIndiceVertice(x,y,n)!= -1){
           inicio = BuscarIndiceVertice(i,j,n);
           fin = BuscarIndiceVertice(x,y,n);
           ruta = grafos[a].Dijkstra(inicio, fin);
           return 3;
         }
         else{
           return 2;
         }
       }
       else{
         return 1;
       }
     }
   }
  return 0;
 };

void archivo::ImprimirRutaCorta(){
  for(int i = 0; i < this->ruta.size(); i++)
    cout<<this->ruta[i]<<"-";
}

void archivo::ImprimirCosto(char n[]){
  double cosTotal = 0.0;
   for(int a = 0; a < this->sequences.size(); a++){
     if(strcmp(n, sequences[a].obtenerNombre())==0){
    for( unsigned int i = 0; i < ruta.size( ) - 1; ++i )
      cosTotal += grafos[a].ObtenerCostoArista( ruta[ i ], ruta[ i + 1 ] );
    cout << cosTotal <<endl;
     }
    }
    
}

int archivo::BaseRemota(char n[], unsigned long i, unsigned long j){
  unsigned long inicio = 0;
  this->ruta.clear();
  for(int a = 0; a < this->sequences.size(); a++){
     if(strcmp(n, sequences[a].obtenerNombre())==0){
       if(BuscarIndiceVertice(i,j,n)!= -1){
         inicio = BuscarIndiceVertice(i,j,n);
         ruta = grafos[a].baseRemota(inicio);
         return 2;
       }
       else
        return 1;
     }
  }
  return 0;
}

vector<long> archivo::EncontrarAB(unsigned long indiceFinal, char n[]){
  unsigned long cont = -1;
  vector<long> pos;
  vector<linea> seq = buscarSecuencia(n).obtenerSeq();
  vector<char> car;
   for(long f = 0 ; f < seq.size(); f++){
    car = seq[f].obtenerLinea();
    for(long c = 0;c <car.size(); c++){
      cont++;
      if(cont == indiceFinal){
        pos.push_back(f);
        pos.push_back(c);
      }
    }
  }
  return pos;
}

unsigned long archivo::ObtenerIndiceFinal(){

  return this->ruta[ruta.size()-1];
}