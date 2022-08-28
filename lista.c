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
    printf("valore: %d --- indirizzo HEAP: %p\n", current->valore, current);
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
    suf_insert_rec(ptrPtr, val); // valore maggiore di tutti gli altri valori.
  }
}

void suf_insert_rec(Lista **ptrPtr, int val) {
  // implementare la funzione di inserimento in coda con la ricorsione.
  // caso base: ptr->next == null.
  if ((*ptrPtr)->nextPtr == NULL) {
    // creo nuovo_nodo
    Lista *new_node   = (Lista *)malloc(sizeof(Lista));
    new_node->valore  = val;
    new_node->nextPtr = NULL;
    // imposto (*ptrPtr)->nextPtr = nuovo_nodo.
    (*ptrPtr)->nextPtr = new_node;
    return;
  }
  suf_insert_rec(&(*ptrPtr)->nextPtr, val);
}

int count(Lista *ptr) {
  // ritornare il numero di elementi presnti all'interno della lista.
  int node_count = 0;
  for(Lista *current = ptr; current != NULL; current = current->nextPtr) {
    node_count+=1;
  }

  return node_count;
}

Lista *find(Lista *ptr, int val) {
  for (Lista *value = ptr; value != NULL; value = value->nextPtr)
    if (value->valore == val)
      return value;
  return NULL;
}

Lista *find_pos(Lista *ptr, unsigned int pos) {
  int total_nodes = count(ptr); 
  if (pos > total_nodes || pos < 0) // caso in cui la posizione non sia presente nella lista.
    return NULL;
  else {
    for (int i = 0; i < total_nodes; i++) {
      if (i == pos) 
        return ptr;
      ptr = ptr->nextPtr;
    }
    return NULL;
  }
}

Lista *slice(Lista *ptr, int n1, int n2) {

  if (n1 > n2 || n1 > count(ptr) - 1 || n2 > count(ptr) - 1) {
    return NULL;
  } else {
    Lista *first = find_pos(ptr, n1);
    Lista *last = find_pos(ptr, n2);

    printf("first inside function: %p\n", first);
    printf("last inside function: %p\n", last);
    if (first == NULL || last == NULL)
      return NULL;
    else {
      // fare il procedimento.
      Lista *tmp_node = NULL;
      // inizializzazione di una nuova testa.
      Lista *new_head = NULL;

      for (Lista *current = first; current != last->nextPtr; current = current->nextPtr) {          
          
        // creare nuovo nodo della lista.
        Lista *new_node = (Lista *)malloc(sizeof(Lista));
        new_node->valore = current->valore;
        new_node->nextPtr = NULL;

        if (tmp_node == NULL) {
          tmp_node = new_node;    
          new_head = new_node;
        } else {
          tmp_node->nextPtr = new_node;
          tmp_node = new_node;
        }
      }
      return new_head;
    }
  }
}

void clone(Lista *srcPtr, Lista **destPtr) {
  
  // nel caso in cui la lista da copiare
  // sia vuota, non si fa niente.
  if (srcPtr == NULL) 
    return;

  (*destPtr) = srcPtr;
}

void clone_2(Lista *srcPtr, Lista **destPtr) {
  
  // nel caso in cui la lista da copiare
  // sia vuota, non si fa niente.
  if (srcPtr == NULL) 
    return;

  (*destPtr) = (Lista *)malloc(sizeof(Lista));
  (*destPtr)->valore = srcPtr->valore;
  (*destPtr)->nextPtr = NULL;
  Lista *current = (*destPtr);
  
  srcPtr = srcPtr->nextPtr;
  while(srcPtr != NULL) {
    current->nextPtr =  (Lista *)malloc(sizeof(Lista));  
    current->nextPtr->valore = srcPtr->valore;
    current->nextPtr->nextPtr = NULL;
    current = current->nextPtr;
    srcPtr = srcPtr->nextPtr;
  }
}
