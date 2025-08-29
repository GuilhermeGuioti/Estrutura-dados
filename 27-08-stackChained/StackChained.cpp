#include "StackChained.h"
#include <iostream>
using namespace std;

Stack::Stack(){
  count = 0;
  top = NULL;
};

Stack::~Stack(){
  clear();
}

bool Stack::empty(){
  return top == NULL;
}

bool Stack::full(){
  return false;
}

void Stack::push(StackEntry x){
  StackPointer p; //ponteiro auxiliar
  p = new StackNode; //alocar dinamicamente
  if(p == NULL){ //verifica se deu certo
    cout << "Sem espaco na memoria";
    abort();
  }

  p->entry = x; //guarda o valor no entry
  p->nextNode = top; //o nextNode vai comecar a apontar para o topo, para o prox vir em cima
  top = p; //topo vai virar o endereco desse novo nextNode
  count++; //aumenta o contador
}

void Stack::pop(StackEntry &x){
  if(empty()){ //verifica se tem algo
    cout << "Nao tem nada";
    abort();
  }

  StackPointer p; //variavel auxilia, pois se nao perdemos o caminho para o prox elemento e nao consiguimos excluir
  x = top->entry; //passando copia do campo de dados para x
  p = top; //ponteiro auxiliar recebe o valor do topo, ou seja, o no que vai ser excluido
  top = top->nextNode; //top vai ter o valor do nextNode, ou seja, o novo topo
  count--; //diminui o contador

  delete p; //deleta o ultimo item
}

int Stack::size(){
  return count;
}

void Stack::getTop(StackEntry &x){
  if(empty()){
    cout << "Nao tem nada";
    abort();
  }
  x = top->entry;
}

void Stack::clear(){
  StackPointer p;
  while(top != NULL){
    p = top;
    top = top->nextNode;
    delete p;
  }
  count = 0;
}