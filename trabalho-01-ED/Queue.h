#include <string>
using namespace std;

struct Cards {
  string model;
  int curb_weight;
  int engine_size;
  int horse_power;
  int price;
  string group;
};

#ifndef QUEUE_H
#define QUEUE_H
typedef Cards QueueEntry;

class Queue{
private:
  struct QueueNode;
  typedef QueueNode* QueuePointer;
  struct QueueNode{
    QueueEntry entry;
    QueuePointer nextNode;
  };

  QueuePointer head; //informar primeiro elemento da estrutura
  QueuePointer tail; //informar ultimo elemento da estrutura

public:
  Queue(); //construtor
  ~Queue(); //destrutor
  bool empty(); //vazio
  bool full(); //cheio
  void append(QueueEntry x); //acrescenta um novo elemento no final da fila
  void serve(QueueEntry &x); //remove o elemento do inicio da fila
  void getFront(QueueEntry &x); //passa um copia do primeiro elemento da fila
  void getRear(QueueEntry &x); //passa uma copia do ultimo elemento da fila
  void clear(); //apaga tudo
  int size();
};

#endif