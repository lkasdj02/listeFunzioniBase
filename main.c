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
  Lista *first = find(lista, 4);
  Lista *last = find(lista, 20);
  (isempty(first)) ? printf("nodo non trovato\n") : printf("nodo: %d\n", first->valore);
  (isempty(last)) ? printf("nodo non trovato\n") : printf("nodo: %d\n", last->valore);

  // TESTING FIND_POS
  last = find_pos(lista, count(lista) - 1);
  (last == NULL) ?  printf("posizione non corretta\n") : printf("puntatore: %p \t valore: %d\n", last, last->valore);


  // TESTING SLICE
  Lista *nuova_slice = slice(lista, 7, 9);
  if (nuova_slice == NULL) {
    printf("controllare di aver immesso delle poizioni corrette\n");
  } else {
    print_list(nuova_slice);
  }

  // TESTING CLONE VERA
  Lista *new_list = NULL;
  clone_2(lista, &new_list);
  print_list(new_list);
}
