#include "archivo.h"
#include "sequence.h"
#include "linea.h"
#include "Nodo.h"
#include "tablaCodigos.h"
#include <bits/stdc++.h>
#define MAXI 500
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
                            //  cout<<"esta es una seqprin";
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
                                        // cout<<"entro a ultima linea";
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
            // cout<<"esta es una seq ultima";
            for(; now!=verificarjustifi.end(); now++)
            {
                if((now->obtenerLinea().size()!=justificacion))
                {
                    verificar++;
                    verificarultima=false;
                    if(cont==numlineas&&now->obtenerLinea().size()<=justificacion&&verificar==1)
                    {
                        verificarultima=true;
                        //  cout<<"entro a ultima linea";
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

void archivo::Codificar(char n[])
{
    int j=1;
    vector<sequence>::iterator it=sequences.begin();
    for(; it!=sequences.end(); it++)
    {
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
        }
    }
    ListaOrd(listaBases);

    Nodo *aux = listaBases;
    int i = 0;
    while (aux != NULL)
    {
        int ascci=aux->base;
        string resultado = "v" +to_string(ascci)  + "f" +to_string(aux->frecuencia) ;

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
    int nElementos = 0;
    tablaCodigos *auxTabla = tablasBits;
    while(auxTabla)
    {

        nElementos++;
        auxTabla = auxTabla->sig;
    }


    fwrite(&nElementos, sizeof(int)-2, 1, archivoBIN);
    cout<<nElementos<<endl;

    while(tablasBits)
    {

        fwrite(&tablasBits->base, sizeof(char), 1, archivoBIN);
        fwrite(&tablasBits->frecuencias, sizeof(long int), 1, archivoBIN);

        tablasBits = tablasBits->sig;
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

    }
    vector<int> longSeq = listarseq();
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
        auxLinea = sequences[ind].obtenerLineas();
        auxCaracteres = auxLinea[0].obtenerLinea();
        indentacion = auxCaracteres.size();

        fwrite(&indentacion, sizeof(int)-2, 1, archivoBIN);

        for(int Jind = 0; Jind < auxLinea.size(); Jind++)
        {
            auxCaracteres = auxLinea[Jind].obtenerLinea();
            for(int Xind = 0; Xind < auxCaracteres.size(); Xind++)
            {

                caracter = auxCaracteres[Xind];
                tabla = buscaCaracter(caracter);
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

    fclose(archivoBIN);

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
    nuevaTabla=(tablaCodigos *)malloc(sizeof(tablaCodigos));;
    nuevaTabla->base = base;
    nuevaTabla->bits = codigo;
    nuevaTabla->xbits = numBits;
    nuevaTabla->frecuencias = frecuencia;
    cout<<"Base: "<<base<<" codigo: "<<codigo<<" numBits: "<<numBits<<endl;
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
}