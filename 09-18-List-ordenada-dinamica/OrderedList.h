#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

typedef int ListEntry;

class OrderedList{
  private:
    struct ListNode;
    typedef ListNode* ListPointer;
    struct ListNode{
      ListEntry entry;
      ListPointer nextNode;
    };

    int count;
    ListPointer head;
    ListPointer sentinel;

  public:
    OrderedList();
    ~OrderedList();
    bool empty();
    bool full();
    void insert(ListEntry x);
    void remove(ListEntry x);
    void clear();
    int search(ListEntry x);
};

#endif