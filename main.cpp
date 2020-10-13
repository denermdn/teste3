#include <iostream>
#include "hashe.h"
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[])
{
    hashe a;
    int aux1,aux2,aux3,aux,auxx;
    ifstream input_file;
    input_file.open(argv[1]);
    if(!input_file)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        exit(1);
    }
        input_file >> aux1 >> aux2 >> aux3;
    cout << "Numero de elemento da hashe:" << aux1 << endl;
    cout << "Numero de elemento a serem inseridos:" << aux2 << endl;
    cout << "Numero da sondagem (linear(1) ou dupla(2)):" << aux3 << endl;
    srand (time(NULL));
    if(aux1<=0)
    {
        cout << "Numero de tamanho da hash invalido" << endl;
        return 0;
    }
    if(aux3!=2 && aux3!=1)
    {
        cout << "Numero de tipo invalido" << endl;
        return 0;
    }
    if(aux2>aux1)
    {
        cout << "Numero de elementos maior que o da hash" << endl;
        return 0;
    }
    a.create(aux1,aux3);
    cout << "Lista de elementos da hash" << endl;
    for(int i=0;i<aux2;i++)
    {
        input_file>> aux;
        cout << "I_" << i << " = " << aux << endl;
        a.insere(aux);
    }//    a.imprime();
    cout << "Numero de colisoes " << a.getColisao() << endl;
    auxx=a.lookup(59);
    if(auxx<0)
        cout << "Elemento 59 nao pode ser encontrado." << endl;
    else
        cout << "Elemento 59 no indice: " << auxx << endl;
    a.destroy();
    input_file.close();    return 0;
}
