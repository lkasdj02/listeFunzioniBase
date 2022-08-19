#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void init(Lista **ptrPtr) {
  (*ptrPtr) = NULL; // inizializzare una lista.
}

int isempty(Lista *ptr) {
  return (ptr == NULL);
}

void print_list(Lista *ptr) {
  for (Lista *current = ptr; current != NULL; current = current->nextPtr)
    printf("valore: %d\n", current->valore);
}

void pre_insert(Lista **ptrPtr, int val) {
  // fare inserimento in testa.
  if ((*ptrPtr) == NULL) { // nessun elmento nella lista.
    (*ptrPtr) = (Lista *)malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;  
    (*ptrPtr)->nextPtr = NULL;
  } else { // lista non vuota => avente almeno un elemento.
    Lista *oldHead = (*ptrPtr); // vecchia testa.
    (*ptrPtr) = (Lista *)malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = oldHead; // connetto la nuova testa con la vecchia.
    // la vecchia testa ora corrisponde al secondo lemento della lista.
  }
}

void suf_insert(Lista **ptrPtr, int val) {
  if (isempty(*ptrPtr)) { // nessun elemento nella lista.
    (*ptrPtr) = (Lista *)malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;  
    (*ptrPtr)->nextPtr = NULL;
  } else {
    Lista *current = (*ptrPtr);

    for(current = (*ptrPtr); current->nextPtr != NULL;)
      current = current->nextPtr;

    Lista *new_node = (Lista *)malloc(sizeof(Lista));
    new_node->valore = val;
    new_node->nextPtr = NULL;

    current->nextPtr = new_node;
  }
}

void ord_insert(Lista **ptrPtr, int val) {
  Lista *current = (*ptrPtr);

  if (val <= current->valore) { // elemento minore della testa.
    pre_insert(ptrPtr, val); // inserimento in testa.
  } else { // altri due sottocasi.
    for(current = (*ptrPtr); current->nextPtr != NULL; current = current->nextPtr) {
      if (val <= current->nextPtr->valore) {
        // inizializzare il nuovo_nodo
        Lista *new_node = (Lista *)malloc(sizeof(Lista));
        new_node->valore = val;
        // connetterlo a current->nextPtr
        new_node->nextPtr = current->nextPtr;
        // connettere current->nextPtr a nuovo_nodo
        current->nextPtr = new_node;
        return;
      }
    }
    // arrivati alla fine del ciclo, siamo giunti al terzo sotto caso della funzione.
    suf_insert(ptrPtr, val); // valore maggiore di tutti gli altri valori.
  }
}
