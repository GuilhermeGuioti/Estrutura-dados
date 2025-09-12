//Nao pode acrescentar em lugares que fragmentam o vetor

#ifndef LIST_H
#define LIST_H

typedef int listEntry;

class List{
  private:
    static const int MaxList = 100;
    listEntry entry[MaxList + 1];
    int count;
  
  public:
    List();
    ~List();
    bool full();
    bool empty();
    void insert(int p, listEntry x);
    void remove(int p, listEntry &x);
    int size();
    void clear();
    void retrieve();
    void replace();  
};

#endif