//arquivo de declaracao
//fila dinamica (encadeada)
//FIFO

#ifndef QUEUE_H
#define QUEUE_H
typedef int QueueEntry;

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
  void front(QueueEntry &x); //passa um copia do primeiro elemento da fila
  void rear(QueueEntry &x); //passa uma copia do ultimo elemento da fila
  void clear(); //apaga tudo
};

#endif