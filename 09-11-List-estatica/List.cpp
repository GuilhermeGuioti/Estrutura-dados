#include "List.h"
#include <iostream>
using namespace std;

List::List(){
  count = 0;
}

List::~List(){
  cout << "Lista destruida" << endl;
}

bool List::empty(){
  return count == 0;
}

bool List::full(){
  return count == MaxList;
}

int List::size(){
  return count;
}

void List::clear(){
  count = 0;
}

void List::insert(int p, listEntry x){
  if(full()) abort(); //Verificar se esta cheio

  if(p < 1 || p > count + 1) abort(); //Verificar se indice é valida (ñ fragmenta)

  for(int i = count; i >= p; i--){ //Abir espaço para o novo elemento 
    entry[i+1] = entry[i];
  }

  entry[p] = x;
  count++;
}

void List::remove(int p, listEntry &x){
  if(empty()) abort();

  if(p < 1 || p > count) abort();

  x = entry[p];

  for(int i = p; i < count; i++){
    entry[i+1] = entry[i];
  }
  
  count--;
}

void List::retrieve(int p, listEntry &x){
  if(empty()) abort();

  if(p < 1 || p > count) abort();

  x = entry[p];
}

void List::replace(int p, listEntry x){
  if(empty()) abort();

  if(p < 1 || p > count) abort();

  entry[p] = x;
}