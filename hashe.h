#ifndef HASHE_H_INCLUDED
#define HASHE_H_INCLUDED
class hashe{

public:
    hashe();
    ~hashe();
    void create(int n,int t);
    void destroy();
    void imprime();
    int getColisao();
    int divisao(int key);
    void insere(int key);
    int divisao2(int key);
    int getcolisao();
    int lookup(int key);
private:
    int m,tipo,m1;
    int *lista;
    int colisoes=0;
};

#endif // HASHE_H_INCLUDED
