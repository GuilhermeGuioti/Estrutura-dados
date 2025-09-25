#include "List.h"
#include <iostream>
using namespace std;

List::List(){
  head == NULL;
  count = 0;
}

List::~List(){
  clear();
}

bool List::empty(){
  return head == NULL;
}

bool List::full(){
  return false; //count = 0
}

int List::size(){
  return count;
}

void List::setPosition(int p, ListPointer &current){
  current = head;
  
  for(int i = 2; i <= p; i++){
    current = current->nextNode;
  }
}

void List::insert(int p, ListEntry x){
  if (p < 1 || p > count + 1) abort();

  ListPointer newNode = new ListNode;
  
  if(newNode == NULL) abort();
  newNode->entry = x;
  
  if(p == 1){
    newNode->nextNode = head;
    head = newNode;
  } 
  else{
    ListPointer current;
    setPosition(p - 1, current);
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
  }
  
  count ++;
}

void List::remove(int p, ListEntry &x){
  if(empty) abort();
  if(p < 1 || p > count) abort();

  ListPointer node;

  if(p == 1){
    node = head;
    head = head->nextNode;
  }
  else{
    ListPointer current;
    setPosition(p - 1, current);
    node = current->nextNode;
    current->nextNode = node->nextNode;
  }

  x = node->entry;
  delete node;
  count --;
}