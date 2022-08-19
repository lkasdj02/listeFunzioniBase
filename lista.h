#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

// PRE: **ptrPtr: riferimento ad un puntatore a Lista.
// POST: inizializza il puntatore a Lista passato per riferimento a NULL.
void init(Lista **ptrPtr);
int isempty(Lista *ptr);
void print_list(Lista *ptr);
// void print_list_rec(Lista *ptr); opzionale
void pre_insert(Lista **ptrPtr, int val);
void suf_insert(Lista **ptrPtr, int val);
void ord_insert(Lista **ptrPtr, int val);
