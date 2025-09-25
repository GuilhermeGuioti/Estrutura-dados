//teste
#ifndef STACK_H
#define STACK_H
typedef char StackEntry;
class Stack{
  public:
    Stack(); //contrutor
    ~Stack(); //destrutor
    bool empty(); //retorna true, caso a pilha esteja vazia
    bool full(); //retorna true, caso a pilha estaja cheia
    void push(StackEntry x); //adiciona um novo elemento na estrutura
    void pop(StackEntry &x); //remove um elemento do topo, e armazena uma copia em x, caso a pilha nao esteja cheia
    int size(); //retorna a quantidade de elementos
    void clear(); //descarta todos os elementos da estrutura
    void getTop(StackEntry &x); //armazena uma copia do topo em x
  private:
    static const int MaxEntry = 100;
    StackEntry entry[MaxEntry + 1];
    int top;
};
#endif