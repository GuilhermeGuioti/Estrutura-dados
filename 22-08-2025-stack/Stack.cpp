#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
  top = 0;
}

Stack::~Stack(){
  cout << "Pilha destruida!" << endl;
}

bool Stack::empty(){
  return top == 0;
}

bool Stack::full(){
  return MaxEntry == top;
}

int Stack::size(){
  return top;
}

void Stack::clear(){
  top = 0;
}

void Stack::pop(StackEntry &x){
  if(empty()){
    cout << "Pilha vazia";
    abort();
  }  
  x = entry[top];
  top--;
}

void Stack::push(StackEntry x){
  if(full()){
    cout << "Pilha cheia";
    abort();
  }
  top++;
  entry[top] = x;
}

void Stack::getTop(StackEntry &x){
  if(empty()){
    cout << "Pilha vazia";
    abort();
  }
  x = entry[top]; 
}

