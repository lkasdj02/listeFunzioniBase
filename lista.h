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
void suf_insert_rec(Lista **ptrPtr, int val);
// PRE: ptr = puntatore a nodo lista.
// POST: la funzione ritorna il numero di elementi della lista. 
int count(Lista *ptr);
// PRE: ptr = puntatore a nodo lista.
// POST: la funzione ritorna:
// 1. un puntatore all'elemento trovato
// 2. NULL in caso l'elemento cercato non esista
// all'interno della lista.
Lista *find(Lista *ptr, int val);
// PRE: ptr = puntatore a nodo lista.
// POST: la funzione ritorna:
// 1. un puntatore all'elemento trovato nella posizione pos.
// 2. NULL in caso l'elemento cercato non esista (all'interno della lista)
// o la posizione
// sia troppo bassa o alta.
Lista *find_pos(Lista *ptr, unsigned int pos);
// PRE: ptr = puntatore a nodo della lista
// n1 = inizio dello slice
// n2 = fine dello slice.
// POST: la funzione ritorna un puntatore ad
// una nuova lista creata contenente i nodoLista
// che vanno dal nodo avente n1 come valore
// al nodo avente n2 come valore (n2 compreso).
Lista *slice(Lista *ptr, int n1, int n2);

void clone(Lista *srcPtr, Lista **destPtr);

void clone_2(Lista *srcPtr, Lista **destPtr);
