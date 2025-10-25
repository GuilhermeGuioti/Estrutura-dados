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
    void preOrdem();
    void clear();
    void insert(TreeEntry x);

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
};

#endif