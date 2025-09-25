#ifndef LIST_H
#define LIST_H

typedef int ListEntry;

class List{
  private:
    struct ListNode;
    typedef ListNode* ListPointer;
    struct ListNode{
      ListEntry entry;
      ListPointer nextNode;
    };

    int count;
    ListPointer head;

    void setPosition(int p, ListPointer &current);

  public:
    List();  
    ~List();
    bool empty();
    bool full();
    int size();
    void insert(int p, ListEntry x);  
    void remove(int p, ListEntry &x);
    void clear();
};

#endif