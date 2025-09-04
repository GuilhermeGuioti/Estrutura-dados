#include "DoubleStack.h"
#include <iostream>
using namespace std;

DoubleStack::DoubleStack(){
  top1 = -1;
  top2 = MaxEntry;
}

DoubleStack::~DoubleStack(){
  cout << "Desalocado";
}

bool DoubleStack::full(){
  return top2 - top1 == 1;
}

bool DoubleStack::stack1_empty(){
  return top1 == -1;
}

bool DoubleStack::stack2_empty(){
  return top2 == MaxEntry;
}

void DoubleStack::stack1_clear(){
  top1 = -1;
}

void DoubleStack::stack2_clear(){
  top2 = MaxEntry;
}

int DoubleStack::stack1_size(){
  return top1 + 1;
}

int DoubleStack::stack2_size(){
  return MaxEntry - top2;
}

void DoubleStack::stack1_push(StackEntry x){
  if (full()) abort();

  top1++;
  entry[top1] = x;
}

void DoubleStack::stack2_push(StackEntry x){
  if (full()) abort();

  top2--;
  entry[top2] = x;
}

void DoubleStack::stack1_pop(StackEntry &x){
  if (stack1_empty) abort();

  x = entry[top1];
  top1--;
}

void DoubleStack::stack2_pop(StackEntry &x){
  if (stack2_empty) abort();

  x = entry[top2];
  top1++;
}

void DoubleStack::stack1_getTop(StackEntry &x){
  if (stack1_empty) abort();
  x = entry[top1];
}

void DoubleStack::stack2_getTop(StackEntry &x){
  if (stack2_empty) abort();
  x = entry[top2];
}