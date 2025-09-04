#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
  head = tail = NULL;
}

Queue::~Queue(){
  clear();
}

bool Queue::empty(){
  return head == NULL;
}

bool Queue::full(){
  return false;
}

void Queue::append(QueueEntry x){
  QueuePointer p; // ponteiro auxiliar para o novo nó que será inserido
  p = new QueueNode; // aloca dinamicamente um novo nó
  if(p == NULL) abort(); // verifica se a alocação falhou

  if(empty()){
    head = p; // se a fila estiver vazia, o início (head) aponta para o novo nó
  } else {
    tail->nextNode = p; // caso contrário, o antigo último nó aponta para o novo nó
  }

  p->entry = x;       // armazena o valor no novo nó
  p->nextNode = NULL; // define que este nó não aponta para nenhum próximo (é o último)
  tail = p;           // atualiza o ponteiro de fim (tail) para o novo nó
}
