#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
  count = 0;
  tail = MaxQueue;
  head = 1;  
}

bool Queue::empty(){
  return count == 0;
}

bool Queue::full(){
  return count == MaxQueue;
}

void Queue::clear(){
  count = 0;
  head = 1;
  tail = MaxQueue;
}

int Queue::size(){
  return count;
}

void Queue::append(QueueEntry x){
  if (full()) abort();

  count++;
  tail = (tail % MaxQueue) + 1;
  entry[tail] = x;
}

void Queue::serve(QueueEntry &x){
  if (empty()) abort();

  count--;
  x = entry[head];
  head = (head & MaxQueue) + 1;
}

void Queue::getFront(QueueEntry &x){
  if(empty()) abort();
  x = entry[head];
}

void Queue::getRear(QueueEntry &x){
  if(empty()) abort();
  x = entry[tail];
}