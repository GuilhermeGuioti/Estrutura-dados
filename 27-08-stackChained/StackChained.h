#ifndef STACK_H
#define STACK_H
typedef char StackEntry;
class Stack{
  public:
    Stack(); //construtor
    ~Stack(); //destrutor
    bool full();
    bool empty();
    void push(StackEntry x);
    void pop(StackEntry &x);
    void clear();
    int size();
    void getTop(StackEntry &x);

  private:
    struct StackNode;
    typedef StackNode* StackPointer;
    StackPointer top;
    struct StackNode{
      StackEntry entry;
      StackPointer nextNode;
    };
    int count;
};
#endif