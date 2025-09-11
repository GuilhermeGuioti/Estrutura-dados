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

void Queue::serve(QueueEntry &x){
  if (empty()) abort(); // Se a fila estiver vazia, encerra o programa

  x = head->entry; // Copia o valor armazenado no primeiro nó (head)
  QueuePointer p = head; // Cria um ponteiro auxiliar que aponta para o nó que será removido
  head = head->nextNode; // Atualiza o ponteiro de início (head) para o próximo nó da fila
  delete p; // Libera a memória do nó antigo que foi removido

  if(head == NULL) tail = NULL; // Se a fila ficou vazia após a remoção, atualiza também o tail para NULL (fila está totalmente vazia)
}

int Queue::size(){
  QueuePointer p = head;
  int s = 0;
  while(p != NULL){
    s++;
    p = p->nextNode;
  }
  return s;
}

void Queue::clear(){
  QueuePointer p;
  while (head != NULL){
    p = head;
    head = head->nextNode;
    delete p;
  }
  tail = NULL;
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();

  x = head->entry;
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();

  x = tail->entry;
}