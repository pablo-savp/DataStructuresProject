#include<vector>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include <stdlib.h>
#include "archivo.h"
#define MAX 10000
using namespace std;
void Ayuda();
void Dividir(char direccion[], char* parte1[], char* parte2[], char* parte3[], char* parte4[],char* parte5[], char* parte6[]);

void enmascarar(char* part2[]);
void codificar(char*parte2[]);
void decodificar(char*parte2[]);
void ruta_mas_corta(char* parte2[], char* parte3[], char* parte4[], char* parte5[], char* parte6[]);
void base_remota(char* parte2[], char* parte3[], char* parte4[]);
void ayudaComando(char* parte2[]);
void ayudas(string comando);
bool EsUnNumero(char* parte3[], char* parte4[], char* parte5[], char* parte6[]);
int main()
{
    archivo arch;
    char direccion[MAX];
    char* parte1[MAX];
    char* parte2[MAX];
    char* parte3[MAX];
    char* parte4[MAX];
    char* parte5[MAX];
    char* parte6[MAX];
    *parte2=NULL;
    *parte3=NULL;
    *parte4=NULL;
    *parte5=NULL;
    *parte6=NULL;
    string comando;
    char buffer[30];
    cout<<"-----------------------------------------------"<<endl;
    cout<<"                Proyecto FASTA                  "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Digite el comando "<<char(34)<<"ayuda"<<char(34)<<" para desplegar el menu de interacciones :)"<<endl;
    do
    {
        cout<<"$ ";
        cin.getline(direccion,MAX,'\n');
        Dividir(direccion, parte1, parte2,parte3,parte4,parte5,parte6);
        comando=*parte1;
        int igu=0;
        int y=0;


        strcpy(buffer,comando.c_str());
        for(int i=0; i<5; i++)
        {
            if(buffer[i]=='a' && igu==0)
            {
                igu++;
            }
            else if(buffer[i]=='y' && igu==1)
            {
                igu++;
            }
            else if(buffer[i]=='u' && igu==2)
            {
                igu++;
            }
            else if(buffer[i]=='d' && igu==3)
            {
                igu++;
            }
            else if(buffer[i]=='a' && igu==4)
            {
                igu++;
            }

        }




        //Componente 1
        if(igu==5 && *parte2==NULL)
        {
            ayudas(comando);


        }

        if(comando.compare("ayuda")==0 && *parte2!=NULL)
        {

            ayudaComando(parte2);


        }

        else if(comando.compare("cargar")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                int abrir=arch.leerArchivo(*parte2);
                if(abrir==-1)
                {
                    cout<<"El archivo no existe"<<endl;
                }
                if(abrir==0)
                {
                    cout<<"'"<<*parte2<<"'"<<" No contiene ninguna secuencia"<<endl;
                }
                if(abrir==1)
                {
                    if(arch.contarSeq()==1)
                    {
                        cout<<"1 secuencia cargada correctamente desde: "<<*parte2<<endl;
                        // arch.imprimirsequencias();

                    }
                    else if(arch.contarSeq()>=2)
                    {
                        cout<<arch.contarSeq()<<" secuencias cargadas correctamente desde: "<<*parte2<<endl;
                        //arch.imprimirsequencias();
                    }
                }

            }
            else
            {
                cout<<"Parametros no validos"<<endl;
            }

        }
        else if(comando.compare("conteo")==0)
        {
            int ban;
            ban=arch.contarSeq();
            if(ban==0)
            {
                cout<<"NO hay secuencias cargadas en memoria."<<endl;
            }
            if(ban==1)
            {
                cout<<"1 secuencia en memoria"<<endl;
            }
            if(ban>=2)
            {
                cout<<ban<<" secuencias cargadas en memoria."<<endl;
            }

        }
        else if(comando.compare("listar_secuencias")==0)
        {
            if(arch.contarSeq()>0)
            {
                vector<int> temp= arch.listarseq();
                vector<int>::iterator it2=temp.begin();
                arch.listarSeq();
                vector<sequence> contenedor=arch.obtenerArchivo();
                vector<sequence>::iterator it=contenedor.begin();
                for(; (it!=contenedor.end())&&it2!=temp.end(); it++)
                {
                    if(it->obtenerIdentificador()=='C')
                    {
                        cout<<"Secuencia '"<<it->obtenerNombre()<<"'"<<" contiene "<<*it2<<" bases"<<endl;
                    }
                    if(it->obtenerIdentificador()=='I')
                    {
                        cout<<"Secuencia '"<<it->obtenerNombre()<<"'"<<" contiene al menos "<<*it2<<" bases"<<endl;
                    }
                    it2++;
                }
            }
            else
            {
                cout<<"NO hay secuecias cargadas en memoria"<<endl;
            }

        }
        else if(comando.compare("histograma")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                vector<int> ban=arch.contarFrecuencias(*parte2);
                if(ban.size()==0)
                {
                    cout<<"Secuencia Invalida."<<endl;
                }
                else if(ban.size()>0)
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
                    vector<char>:: iterator letras=codigos.begin();
                    vector<int>::iterator iRep = ban.begin();
                    for(; (iRep!=ban.end()&&letras!=codigos.end()); iRep++)
                    {
                        if(*iRep!=0)
                        {
                            cout<<*letras<<" : "<<*iRep<<endl;

                        }

                        letras++;
                    }
                }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }

        }
        else if(comando.compare("es_subsecuencia")==0)
        {
            //cout<<"Entro subsecuencia"<<endl;
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                int ban=arch.subSeq(*parte2);
                if(arch.contarSeq()==0)
                {
                    cout<<"NO hay secuencias cargadas en memoria"<<endl;
                }
                else if( ban ==0)
                {
                    cout<<"La secuencia dada no existe"<<endl;
                }
                else if(ban==1)
                {
                    cout<<"La secuencia dada se repite: "<<ban<<" vez"<<endl;
                }
                else if(ban>1)
                {
                    cout<<"La secuencia dada se repite: "<<ban<<" veces"<<endl;
                }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }

        }
        else if(comando.compare("enmascarar")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                int ban=-1;
                ban=arch.enmascarar(*parte2);
                if(arch.contarSeq()==0)
                {
                    cout<<"No hay secuencias cargadas en memoria"<<endl;
                }
                else if( ban ==0)
                {
                    cout<<"La secuencia dada no existe"<<endl;
                }
                else if(ban==1)
                {
                    cout<<""<<ban<<" secuencia ha sido enmascarada"<<endl;
                }
                else if(ban>1)
                {
                    cout<<""<<ban<<" secuencias han sido enmascaradas"<<endl;
                }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }

        }
        
        else if(comando.compare("guardar")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                if(arch.contarSeq()==0)
                {
                    cout<<"NO hay secuencias cargadas en memoria"<<endl;
                }
                else
                {
                    bool ban=arch.guardarArchivo(*parte2);
                    if(ban==true)
                    {
                        cout<<"Las secuencias han sido guardadas en: "<<*parte2<<endl;
                    }
                    else if(ban==false)
                    {
                        cout<<"Error guardando en: "<<*parte2<<endl;
                    }
                }

            }

        }
        else if(comando.compare("salir")==0)
        {
            cout<<"Regrese pronto :)"<<endl;
        }

        //Componente 2

        else if(comando.compare("codificar")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
              if(arch.contarSeq()==0)
              {

                cout<<" NO hay Secuencias ccargadas en memoria \n";
              }
              else{
                bool funciono;
                funciono=arch.Codificar(*parte2);
                if(funciono == true){
                   cout<<"Secuencias codificadas y almacenadas en: "<<*parte2<<endl;
                 }
                 else{
                   cout<<"No se pueden guardar las secuencias cargadas en: "<<*parte2<<endl;
                 }

              }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;
            }

        }
        else if(comando.compare("decodificar")==0)
        {
            if(*parte2!=NULL&&*parte3==NULL&&*parte4==NULL&&*parte5==NULL&&*parte6==NULL)
            {
                bool funciono;
                funciono=arch.Decodificar(*parte2);
                if(funciono == true){
                   cout<<"Secuencias decodificadas desde "<<*parte2<<" y cargadas en memoria."<<endl;
                 }
                 else{
                   cout<<"No se pueden cargar las secuencias en: "<<*parte2<<endl;
                 }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }
        }

        //Componente 3

        else if(comando.compare("ruta_mas_corta")==0)
        {
            if(*parte2 != NULL && *parte3 !=NULL && *parte4 != NULL && *parte5 != NULL && *parte6 != NULL)
            {
                bool sonNumericos;
                sonNumericos=EsUnNumero(parte3,parte4,parte5,parte6);
                if(sonNumericos==true)
                {
                  int i = atoi(*parte3);
                  int j = atoi(*parte4);
                  int x = atoi(*parte5);
                  int y = atoi(*parte6);

                  int validar = arch.RutaMasCorta(*parte2, i, j, x,y);
                  if(validar == 0)
                    cout<<"La secuencia dada no existe."<<endl;
                  else if(validar == 1)
                    cout<<"La base en la posición ["<<i<<", "<<j<<"] no existe."<<endl;
                  else if(validar == 2)
                    cout<<"La base en la posición ["<<x<<", "<<y<<"] no existe."<<endl;
                  else if(validar == 3){
                    cout<<"La ruta más corta entre la base en ["<<i<<", "<<j<<"] y la base en ["<<x<<", "<<y<<"] es: ";
                    arch.ImprimirRutaCorta();
                    cout<<"\n"<<"El costo total de la ruta es: ";
                    arch.ImprimirCosto(*parte2);
                  }
                }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }

        }
        else if(comando.compare("base_remota")==0)
        {
            if(*parte2!=NULL && *parte3!=NULL && *parte4!=NULL && *parte5==NULL && *parte6==NULL)
            {
                int par3=*parte3[0];
                int par4=*parte4[0];
                int validar=0;
                int i = atoi(*parte3);
                int j = atoi(*parte4);
                //Este a y b son para probar, deben adoptar el valor de la posicion de la base remota.
                vector<long> pos;
                 unsigned long fin;
                if(!std::isdigit(par3) || !std::isdigit(par4))
                {
                    cout<<"Los parametros deben ser numericos, ingresarlos nuevamente"<<endl;
                }
                else
                {
                  validar=arch.BaseRemota(*parte2,i,j);

                  if(validar == 0)
                    cout<<"La secuencia dada no existe."<<endl;

                  else if(validar == 1)
                    cout<<"La base en la posición ["<<i<<", "<<j<<"] no existe."<<endl;
                    
                  else if(validar == 2){
                    cout<<"entro a base remota"<<endl;
                     fin = arch.ObtenerIndiceFinal();
                     pos = arch.EncontrarAB(fin,*parte2);
                     cout<<"La base remota esta ubicada en["<<pos[0]<<", "<<pos[1]<<"] y ruta entre la base en ["<<i<<", "<<j<<"] y la base remota en ["<<pos[0]<<", "<<pos[1]<<"] es: ";
                     arch.ImprimirRutaCorta();
                     cout<<"\n"<<"El costo total de la ruta es: ";
                     arch.ImprimirCosto(*parte2);
                  }
                    

                }
            }
            else
            {
                cout<<"Parametros invalidos"<<endl;

            }
        }

        

        else if(comando.compare("ayuda")==0)
        {
            if(*parte2!=NULL)
            {
                ayudaComando(parte2);
            }

        }
        else
        {
            cout<<"Comando incorrecto, por favor ingreselo nuevamente"<<endl;
        }




    }
    while(comando.compare("salir")!=0);
    return 0;
}


void Dividir(char direccion[], char* parte1[], char* parte2[], char* parte3[], char* parte4[],char* parte5[], char* parte6[])
{


    char *aux;
    aux = strtok(direccion, " ");
    *parte1 = aux;
    aux = strtok(NULL, " ");
    *parte2 = aux;
    aux= strtok(NULL," ");
    *parte3= aux;
    aux= strtok(NULL," ");
    *parte4= aux;
    aux= strtok(NULL," ");
    *parte5= aux;
    aux= strtok(NULL," ");
    *parte6= aux;

    




}
void Cargar(char* parte2[])
{
    cout<<"Entro cargar: nombre archivo:  "<<*parte2<<endl;
}
void Conteo()
{
    cout<<"No hay secuencias cargadas en memoria"<<endl;
}

void listar_secuencias()
{
    cout<<"no hay listas cargadas en el sistema.";
}

void histograma(char* parte2[])
{
    cout<<"histograma nombre: "<<*parte2<<endl;

}

void es_subsecuencia(char* parte2[])
{
    cout<<"No hay secuencias cargadas en memoria"<<endl;
    cout<<"La secuencia dad no existe"<<endl;
    cout<<"La secuencia dada se repite s veces"<<endl;
}


void enmascarar(char* parte2[])
{

    cout<<"No hay secuencias cargadas en memoria"<<endl;

}
void guardar(char* parte2[])
{
    cout<<"No hay secuencias cargadas en memoria"<<endl;
    cout<<"Las secuencias han sido guardadas en "<<char(34)<<*parte2<<char(34)<<endl;
    cout<<"Error guardando en "<<char(34)<<*parte2<<char(34)<<endl;
}

void codificar(char*parte2[])
{
    cout<<"No se pueden guardar las secuencias cargadas en el archivo.fabin"<<endl;
}

void decodificar(char*parte2[])
{
    cout<<"No se pueden cargar las secuencias en nombre_archivo.fabin ."<<endl;
}

void ruta_mas_corta(char* parte2[], char* parte3[], char* parte4[], char* parte5[], char* parte6[])
{
    cout<<"La secuencia dada no existe"<<endl;
}

void base_remota(char* parte2[], char* parte3[], char* parte4[])
{
    cout<<"La secuencia dada no existe"<<endl;
}


void ayudas(string comando)
{
    if(comando.compare("ayuda")==0)
    {
        cout<<"Los comandos existentes son:"<<endl;
        cout<<"1. cargar "<<endl;
        cout<<"2. conteo"<<endl;
        cout<<"3. listar_secuencias"<<endl;
        cout<<"4. histograma"<<endl;
        cout<<"5. es_subsecuencia"<<endl;
        cout<<"6. enmascarar"<<endl;
        cout<<"7. codificar"<<endl;
        cout<<"8. decodificar"<<endl;
        cout<<"9. ruta_mas_corta"<<endl;
        cout<<"10. base_remota"<<endl;
        cout<<"11. salir"<<endl;
    }
}

void ayudaComando(char* parte2[])
{
    bool bandera=false;

    if(strcmp("cargar",*parte2)==0)
    {
        cout<<endl;
        cout<<"Este comando Carga en memoria los datos contenidos en el archivo identificado por nombre_archivo"<<endl;

        cout<<"Para llamar el comando se digita: cargar nombre_archivo"<<endl;
        bandera=true;

    }
    if(strcmp("conteo",*parte2)==0)
    {
        cout<<endl;
        cout<<"Este comando imprime por pantalla la cantidad de secuencias cargadas en memoria."<<endl;

        cout<<"Para llamar el comando se digita: conteo"<<endl;
        bandera=true;

    }
    if(strcmp("listar_secuencias",*parte2)==0)
    {
        cout<<endl;
        cout<<"Este comando  Imprime en n líneas (una para secuencia) la información básica (cantidad de bases) de cada secuencia" <<endl;

        cout<<"Para llamar el comando se digita: listar_secuencias"<<endl;
        bandera=true;

    }
    if(strcmp("histograma",*parte2)==0)
    {
        cout<<endl;
        cout<<"Imprime el histograma de una secuencia, en caso de que exista. El histograma se define como el conteo (frecuencia) de cada código en la secuencia. Por cada línea (’\n’ es el caracter de saltode línea) se escribe el código y la cantidad de veces que aparece en la secuencia"<<endl;

        cout<<"Para llamar el comando se digita: histograma descripcion_secuencia"<<endl;
        bandera=true;

    }
    if(strcmp("es_subsecuencia",*parte2)==0)
    {
        cout<<endl;
        cout<<" Determina si una secuencia, dada por el usuario, existe dentro de las secuencias cargadas.Si es así, determina la cantidad de veces en las que esta secuencia dada se repite"<<endl;

        cout<<"Para llamar el comando se digita: es_subsecuencia secuencia"<<endl;
        bandera=true;

    }
    if(strcmp("enmascarar",*parte2)==0)
    {
        cout<<endl;
        cout<<"Enmascara una secuencia dada por el usuario, si existe. Los elementos que pertenecen ala subsecuencia se enmascaran cambiando cada código por el código ’X’."<<endl;

        cout<<"Para llamar el comando se digita: enmascarar secuencia"<<endl;
        bandera=true;

    }
    if(strcmp("guardar",*parte2)==0)
    {
        cout<<endl;
        cout<<"Guarda en el archivo nombre_archivo las secuencias cargadas en memoria. Se debe teneren cuenta la justificación (de líneas) del archivo inicial."<<endl;

        cout<<"Para llamar el comando se digita: guardar nombre_archivo"<<endl;
        bandera=true;

    }

    if(strcmp("codificar",*parte2)==0)
    {
        cout<<endl;
        cout<<"El comando debe generar el archivo binario con la correspondiente codificación de Huffmanen el formato descrito más arriba, almacenándolo en disco bajo el nombre nombre_archivo.fabin. "<<endl;

        cout<<"Para llamar el comando se digita: codificar nombre_archivo.fabin"<<endl;
        bandera=true;

    }

    if(strcmp("ruta_mas_corta",*parte2)==0)
    {
        cout<<endl;
        cout<<"El comando debe imprimir en pantalla la secuencia de vértices del grafo que describen la ruta más corta entre la base ubicada en la posición [i ,j ] de la matriz de la secuenciadescripcion_secuencia y la base ubicada en la posición [x ,y ] de la misma matriz. Así mismo,debe imprimir el costo total de la ruta, teniendo en cuenta el peso que tiene cada conexión entre bases."<<endl;

        cout<<"Para llamar el comando se digita: ruta_mas_corta descripcion_secuencia i j x y"<<endl;
        bandera=true;

    }


    if(strcmp("base_remota",*parte2)==0)
    {
        cout<<endl;
        cout<<"Para la base ubicada en la posición [i ,j ] de la matriz de la secuencia descripcion_secuencia, el comando busca la ubicación de la misma base (misma letra) más lejana dentro de la matriz. Para esta base remota, el comando debe imprimir en pantalla su ubicación, la secuencia de vértices que describenla ruta entre la base origen y la base remota, y el costo total de la ruta."<<endl;

        cout<<"Para llamar el comando se digita: base_remota descripcion_secuencia i j"<<endl;
        bandera=true;


    }
    if(bandera==false)
    {
        cout<<endl;
        cout<<"Parametro invalido"<<endl;
        cout<<"Los parametros validos son:"<<endl;
        cout<<"cargar, histograma, base, ruta, listarsec, codificar, guardar, enmascarar, subsecuencia"<<endl;

    }

}




bool EsUnNumero(char* parte3[], char* parte4[], char* parte5[], char* parte6[])
{


    int par3=*parte3[0];
    int par4=*parte4[0];
    int par5=*parte5[0];
    int par6=*parte6[0];

    if( !std::isdigit(par3)||!std::isdigit(par4)||!std::isdigit(par5)||!std::isdigit(par6))
    {
        cout<<"Los parametros deben ser numericos, ingresarlos nuevamente"<<endl;
        return false;

    }



    return true;
}