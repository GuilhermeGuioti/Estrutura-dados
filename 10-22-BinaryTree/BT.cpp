#include "BT.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Construtor ilustrativo
BinaryTree::BinaryTree(){
    root = new TreeNode;
    root->entry = 'A';

    root->leftNode = new TreeNode;
    root->leftNode->entry = 'B';
    root->rightNode = new TreeNode;
    root->rightNode->entry = 'C';
    
    root->leftNode->leftNode = new TreeNode;
    root->leftNode->leftNode->entry = 'D';
    root->leftNode->leftNode->rightNode = NULL;
    root->leftNode->rightNode = new TreeNode;
    root->leftNode->rightNode->entry = 'E';
    root->leftNode->rightNode->leftNode = NULL;
    root->leftNode->rightNode->rightNode = NULL;

    root->leftNode->leftNode->leftNode = new TreeNode;
    root->leftNode->leftNode->leftNode->entry = 'H';
    root->leftNode->leftNode->leftNode->leftNode = NULL;
    root->leftNode->leftNode->leftNode->rightNode = NULL;

    root->rightNode->leftNode = new TreeNode;
    root->rightNode->leftNode->entry = 'F';
    root->rightNode->rightNode = new TreeNode;
    root->rightNode->rightNode->entry = 'G';
    root->rightNode->rightNode->leftNode = NULL;
    root->rightNode->rightNode->rightNode = NULL;

    root->rightNode->leftNode->leftNode = new TreeNode;
    root->rightNode->leftNode->rightNode = NULL;
    root->rightNode->leftNode->leftNode->entry = 'I';
    root->rightNode->leftNode->leftNode->leftNode = NULL;
    root->rightNode->leftNode->leftNode->rightNode = NULL;
}

//Destrutor ilustrativo
BinaryTree::~BinaryTree(){
    root->rightNode->leftNode->leftNode = new TreeNode;
    root->rightNode->rightNode = new TreeNode;
    root->rightNode->leftNode = new TreeNode;
    root->leftNode->leftNode->leftNode = new TreeNode;
    root->leftNode->rightNode = new TreeNode;
    root->leftNode->leftNode = new TreeNode;
    root->rightNode = new TreeNode;
    root->leftNode = new TreeNode;
    root = new TreeNode;
}

bool BinaryTree::empty(){
    return root == NULL;
}

bool BinaryTree::full(){
    return false;
}

//Função Print

void BinaryTree::print(){
    print(root, 0);
}

void BinaryTree::print(TreePointer &t, int s){
    int i;
    if(t != NULL){
        print(t->rightNode, s+3);
        
        for(i = 1; i <= s; i++){
            cout << " ";
        }

        cout << setw(6) << t->entry <<endl;
        print(t->leftNode, s+3);
    }
}

//Função Nodes

int BinaryTree::nodes(){
  return nodes(root);
}

int BinaryTree::nodes(TreePointer &t){
  if(t == NULL) return 0;

  return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

//Função Leaves

int BinaryTree::leaves(){
  return leaves(root);
}

int BinaryTree::leaves(TreePointer &t){
  if(t == NULL) return 0;
  if(t->leftNode == NULL && t->rightNode == NULL) return 1;
  return leaves(t->leftNode) + leaves(t->rightNode);
}

//Função Height

int BinaryTree::height(){
  return height(root);
}

int BinaryTree::height(TreePointer &t){
  if(t == NULL) return -1;

  int L, R;
  L = height(t->leftNode);
  R = height(t->rightNode);

  if(L > R) return L + 1;
  if(R > L) return R + 1;
}

// Pré-Ordem = R E D
// Em-Ordem  = E R D
// Pós-Ordem = E D R

void BinaryTree::preOrdem(){
  return preOrdem(root);
}

void BinaryTree::preOrdem(TreePointer &t){
  if(t == NULL) return;

  cout << t->entry << endl;
  preOrdem(t->leftNode);
  preOrdem(t->rightNode);
}