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
  ListPointer q;

  sentinel->entry = x;

  while(p->entry < x){
    p = p->nextNode;
  }

  q = new ListNode;
  if (q == NULL) abort();

  if(p == sentinel){
    p->nextNode = q;
    sentinel = q;
  }
  else{
    *q = *p;
    p->entry = x;
    p->nextNode = q;
  }

  count++;
}