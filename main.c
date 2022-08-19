#include "lista.h"
#include <stdio.h>

int main() {
  Lista *lista;
  init(&lista);


  // LISTA AVENTE UNICAMENTE NUMERI PARI.
  
  // TESTING PRE_INSERT
  for(int i = 4; i > 0; i-=2)
    pre_insert(&lista, i);

  // TESTING SUF_INSERT
  for(int i = 6; i <= 10; i+=2)
    suf_insert(&lista, i);

  // TESTING ORD_INSERT 
  ord_insert(&lista, 20);
  
  // TESTING IS EMPTY FUNCTION
  (isempty(lista)) ? printf("lista vuota\n") : print_list(lista);

  // TESTING COUNT FUNCTION
  printf("il numero degli elementi della lista: %d\n", count(lista));

  // TESTING FIND FUNCTION:
  Lista *nodo = find(lista, 10);
  (isempty(nodo)) ? printf("nodo non trovato") : print_list(nodo);
}
