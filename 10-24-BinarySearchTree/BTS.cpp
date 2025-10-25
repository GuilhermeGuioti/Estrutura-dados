#include "BTS.h"
#include <iostream>
#include <iomanip>
using namespace std;

BinarySearchTree::BinarySearchTree(){
  root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
  clear();
}

bool BinarySearchTree::empty(){
  return root == NULL;
}

bool BinarySearchTree::full(){
  return false;
}

//Função Clear

void BinarySearchTree::clear(){
  clear(root);
  root = NULL;
}

void BinarySearchTree::clear(TreePointer &t){
  //algoritimo feito em pós-ordem
  if(t != NULL){
    clear(t->leftNode);
    clear(t->rightNode);
    delete t;
  } 
}

//Função Print

void BinarySearchTree::print(){
  print(root, 0);
}

void BinarySearchTree::print(TreePointer &t, int s){
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

int BinarySearchTree::nodes(){
  return nodes(root);
}

int BinarySearchTree::nodes(TreePointer &t){
  if(t == NULL) return 0;

  return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

//Função Leaves

int BinarySearchTree::leaves(){
  return leaves(root);
}

int BinarySearchTree::leaves(TreePointer &t){
  if(t == NULL) return 0;
  if(t->leftNode == NULL && t->rightNode == NULL) return 1;
  return leaves(t->leftNode) + leaves(t->rightNode);
}

//Função Height

int BinarySearchTree::height(){
  return height(root);
}

int BinarySearchTree::height(TreePointer &t){
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

void BinarySearchTree::preOrdem(){
  return preOrdem(root);
}

void BinarySearchTree::preOrdem(TreePointer &t){
  if(t == NULL) return;

  cout << t->entry << endl;
  preOrdem(t->leftNode);
  preOrdem(t->rightNode);
}

//Função insert

void BinarySearchTree::insert(TreeEntry x){
  TreePointer p = NULL;
  TreePointer q = root;
  
  //Posicionamento dos ponteiros
  while(q != NULL){
    p = q;
    
    if(x < q->entry) q = q->leftNode;
    if(x > q->entry) q = q->rightNode;
  }

  //Alocação dinâmica e inicilização do novo nó
  TreePointer newNode = new TreeNode;
  if(newNode == NULL) abort();
  newNode->entry = x;
  newNode->leftNode = newNode->rightNode = NULL;

  //Encadeamento do nó
  if(p == NULL){
    root = newNode;
  } 
  else{
    if(x < p->entry) p->leftNode = newNode;
    if(x > p->entry) p->rightNode = newNode;
  }
}