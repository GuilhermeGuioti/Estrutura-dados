#include "OrderedList.h"
#include <iostream>
using namespace std;

OrderedList::OrderedList(){
  count = 0;

  sentinel = new ListNode;
  if(sentinel == NULL) abort();

  head = sentinel;
}

OrderedList::~OrderedList(){
  clear();
  delete sentinel;
}

bool OrderedList::empty(){
  return head == sentinel; //count == 0
}

bool OrderedList::full(){
  return false;
}

void OrderedList::insert(ListEntry x){
  ListPointer p = head;
  ListPointer newNode;

  sentinel->entry = x;

  while(p->entry < x){
    p = p->nextNode;
  }

  newNode = new ListNode;
  if (newNode == NULL) abort();

  if(p == sentinel){
    p->nextNode = newNode;
    sentinel = newNode;
  }
  else{
    *newNode = *p;
    p->entry = x;
    p->nextNode = newNode;
  }

  count++;
}

void OrderedList::remove(ListEntry x){
  ListPointer p = NULL;
  ListPointer q = head;

  sentinel->entry = x;

  while(q->entry < x){
    p = q;
    q = q->nextNode;
  } 

  if(q->entry != x || q == sentinel) abort();

  if(q == head){
    head = head->nextNode;
  }
  else{
    p->nextNode = q->nextNode;
    delete q;
  }

  count--;
}

int OrderedList::search(ListEntry x){
  ListPointer q = head;
  int posicao = 1;

  sentinel->entry = x;

  while(q->entry < x){
    q = q->nextNode;
    posicao++;
  }

  if(q->entry != x || q == sentinel) return 0;

  return posicao;
}

void OrderedList::clear(){
  ListPointer q = head;

  while(head != sentinel){
    q = head;
    head = head->nextNode;
    delete q;
  }
}