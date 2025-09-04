#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H
typedef int StackEntry;
class DoubleStack{
  public:
    DoubleStack();
    ~DoubleStack();
    bool full();

    bool stack1_empty();
    bool stack2_empty();

    void stack1_clear();
    void stack2_clear();

    void stack1_push(StackEntry x);
    void stack2_push(StackEntry x);

    void stack1_pop(StackEntry &x);
    void stack2_pop(StackEntry &x);

    void stack1_getTop(StackEntry &x);
    void stack2_getTop(StackEntry &x);

    int stack1_size();
    int stack2_size();

    private:
      static const int MaxEntry = 100;
      StackEntry entry[MaxEntry];
      int top1; //primeiro elemento em 0
      int top2; //primeiro elemento em MaxEntry-1
};
#endif