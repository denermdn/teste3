#include <iostream>#include "hashe.h"
#include "math.h"
using namespace std;

hashe::hashe()
{
}
hashe::~hashe()
{

}
int hashe::getColisao()
{
    return colisoes;
}
void hashe::create(int n,int t)
{
    m=n;
    m1=n-1;
    lista=new int[m];
    for(int i=0;i<m;i++)
        lista[i]=-1;
    colisoes=0;
    tipo=t;
}
int hashe::lookup(int key)
{
    int cont=0,aux,aux2;
    switch(tipo)
    {
    case 1:
        do{
            aux=divisao(key)+cont;
            aux=divisao(aux);
            cont++;
            if(lista[aux]==-1)
            {
                return -1;
            }
          }
    while(lista[aux]!=key);
    return aux;
    break;
    case 2:
    do{
            aux=divisao(key);
            aux2=divisao2(key);
            aux=aux+cont*aux2;
            aux=aux%m;
            cont++;
            if(lista[aux]==-1)
            {

                return -1;
            }
//            if(key==752)
//                cout << cont << " " << aux << endl;
      }
      while(lista[aux]!=key);
      return aux;
    }
    return -1;
}
void hashe::destroy()
{
    delete [] lista;
}

int hashe::divisao(int key)
{
    return key%m;
}
int hashe::divisao2(int key)
{
    return 1+(key%m1);
}
void hashe::insere(int key)
{
    int cont=0,aux,aux2;
    switch(tipo)
    {
    case 1:
        do{
            aux=divisao(key)+cont;
            aux=divisao(aux);
            cont++;
            if(lista[aux]==key)
                return;
          }
    while(lista[aux]!=-1);
    lista[aux]=key;
    break;
    case 2:
    do{
            aux=divisao(key);
            aux2=divisao2(key);
            aux=aux+cont*aux2;
            aux=aux%m;
            cont++;
            if(lista[aux]==key)
                return;
//            if(key==752)
//                cout << cont << " " << aux << endl;
      }
      while(lista[aux]!=-1);
      lista[aux]=key;
    }
    colisoes=colisoes+cont-1;
    return;
}
void hashe::imprime()
{
    cout << "-1 = indice vazio" << endl;
    for(int i=0;i<m;i++)
        cout <<i << " " << lista[i] << " " << endl;
    return;
}
