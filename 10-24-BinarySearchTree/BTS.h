#include <string>
#ifndef BTS_H
#define BTS_H

typedef int TreeEntry;

class BinarySearchTree{
  public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool empty();
    bool full();
    void print();
    int nodes();
    int leaves();
    int height();
    void clear();
    void preOrdem();
    void insert(TreeEntry x);
    TreeEntry minimum();
    TreeEntry maximum();
    bool search(TreeEntry x);
    bool remove(TreeEntry x);

  private:
    struct TreeNode;
    typedef TreeNode* TreePointer;

    struct TreeNode{
      TreeEntry entry;
      TreePointer leftNode, rightNode;
    };
    
    TreePointer root;

    void print(TreePointer &t, int s);
    int nodes(TreePointer &t);
    int leaves(TreePointer &t);
    int height(TreePointer &t);
    void clear(TreePointer &t);
    void preOrdem(TreePointer &t);
    bool remove(TreeEntry x, TreePointer &p);
    void removeMin(TreePointer &q, TreePointer &r);
};

#endif