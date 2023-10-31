/// @brief Creates a single Scapegoat BST
/// @file BST.h
/// @author Brandon Hughes
/// @course CPSC-350-03 Data Structures and Algorithms
#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;


template <typename T>
class BST{
public:
  BST();
  virtual ~BST();
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  void printInOrder();
  void printPostOrder();
  int getSize();
  T getMedian();
  T getMin();
  T getMax();
private:
  TreeNode<T>* m_root;
  int m_size;
  void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, T d);
  void printInOrderHelper(TreeNode<T>* subTreeRoot);
  void printPostOrderHelper(TreeNode<T>* subTreeRoot);
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  T getSuccessor(TreeNode<T>* node);
  int m_total; // n
  int size(TreeNode<T>* node);
  TreeNode<T>* A;
  void rebuild(TreeNode<T>* key);
  TreeNode<T>* buildSubtree(TreeNode<T>* arrayNums, int sizeOfArray);
  void fillArray();
  void fillArrayHelper(TreeNode<T>* node);
  int depth;
};

//default constructor
template <typename T>
BST<T>::BST(){
  m_root = NULL;
  m_size = 0;
  m_total = 0;
}

//defualt destructor
template <typename T>
BST<T>::~BST(){
  if(m_root != NULL){
    delete m_root;
  }
}

//returns size of the BST
template <typename T>
int BST<T>::getSize(){
  return m_size;
}

//returns size of a single branch
template <typename T>
int BST<T>::size(TreeNode<T>* node) {
  if (node == NULL) {
    return 0;
  }
  else {
    int length = 1;
    length += size(node->m_left);
    length += size(node->m_right);
    return length;
  }
}

//function to calculate log32
double const log32(int total) {
  double const log23 = 2.4663034623764317;
  return (log23 * log(total));
}

//insert method
template <typename T>
void BST<T>::insert(T d){
  depth = 0;
  TreeNode<T>* newNode = new TreeNode<T>(d);
  insertHelper(m_root,newNode);
  ++m_size;
  ++m_total;
  if(depth > log32(m_total)){
    cout << "Attempting to rebuild due to log error" << endl;
    TreeNode<T>* parent = NULL;
    TreeNode<T>* target = NULL;
    target = m_root;
    findTarget(d, target, parent);
    while(3*size(target) <= 2*size(parent)){
      target = parent;
      rebuild(parent);
    }
  }
}

//insert helper
template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
  } else if(newNode->m_data < subTreeRoot->m_data){
    insertHelper(subTreeRoot->m_left,newNode);
    depth++;
  } else{
    insertHelper(subTreeRoot->m_right,newNode);
    depth++;
  }

}

//returns if the BST contains the data
template <typename T>
bool BST<T>::contains(T d){
  return containsHelper(m_root,d);
}

//contains helper function to navigate through the tree
template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, T d){
  if(subTreeRoot == NULL){
    return false;
  } else if (subTreeRoot->m_data == d){
    return true;
  } else if(d < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,d);
  } else{
    return containsHelper(subTreeRoot->m_right,d);
  }
}


//prints the BST in order
template <typename T>
void BST<T>::printInOrder(){
  printInOrderHelper(m_root);
}

//helper function to print in order
template <typename T>
void BST<T>::printInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data << endl;
    printInOrderHelper(subTreeRoot->m_right);
  }
}

//prints it in left tree, right tree, root
template <typename T>
void BST<T>::printPostOrder(){
  printPostOrderHelper(m_root);
}

template <typename T>
void BST<T>::printPostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printPostOrderHelper(subTreeRoot->m_left);
    printPostOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data << endl;
  }
}

//returns root's data
template <typename T>
T BST<T>::getMedian(){
  return m_root->m_data;
}

//returns smallest value (leftmost)
template <typename T>
T BST<T>::getMin(){
  return getMinHelper(m_root);
}

//returns biggest value (rightmost)
template <typename T>
T BST<T>::getMax(){
  return getMaxHelper(m_root);
}

//helper function for getmin
template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}

//helper function for getmax
template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right == NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }
}

//finds the target in the BST
template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data != key){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}

//returns it's child
template <typename T>
T BST<T>::getSuccessor(TreeNode<T>* node){ //assume node starts at right child
  while(node->m_left != NULL){
    node = node->m_left;
  }
  return node->m_data;

}

//removes something from the bst
template <typename T>
void BST<T>::remove(T d){
  //make sure to free memory
  //check for follishness
  TreeNode<T>* parent = NULL; //keep track of what needs to be deleted and patched
  TreeNode<T>* target = NULL;
  //do the remove
  target = m_root;
  findTarget(d,target,parent);
  if(target == NULL){ //not in tree
    return;
  }
  //do some real work
  if(target->m_left == NULL && target->m_right == NULL ){ //it's a leaf
    if(target == m_root){
      m_root = NULL;
    } else{
      if(target == parent->m_left){
        parent->m_left = NULL;
      } else{
        parent->m_right = NULL;
      }
    }
    --m_size;
  } else if(target->m_left != NULL && target->m_right != NULL){ //2 children
    T succValue = getSuccessor(target->m_right);
    remove(succValue);
    target->m_data = succValue;
    --m_size;
  } else{ // 1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    if(target == m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
    --m_size;
  }
  if(m_total > (2 * m_size)){
    cout << "rebuilding" << endl;
    rebuild(m_root);
    m_total = m_size;
  }
}

template <typename T>
void BST<T>::rebuild(TreeNode<T>* key){
    A = new TreeNode<T>[m_size];
    fillArray();
    buildSubtree(A, m_size);
}


template <typename T>
TreeNode<T>* BST<T>::buildSubtree(TreeNode<T>* arrayNums, int sizeOfArray){
    int k = sizeOfArray;

    if(k == 0) {
        return NULL;
    } else {
        int j = floor(k/2);
        TreeNode<T>* medianKey = new TreeNode<T>(arrayNums[j]);
        TreeNode<T>* leftArray = new TreeNode<T>[j];
        TreeNode<T>* rightArray = new TreeNode<T>[j];
         for (int i = 0; i < j-1; ++i) {
            leftArray[i] = A[i];
        }
        for (int i = j+1; i < k-1; ++i) {
            rightArray[i] = A[i];
        }
        medianKey->m_left = buildSubtree(leftArray, j);
        medianKey->m_right = buildSubtree(rightArray, j);
        return medianKey;
    }
}

template <typename T>
void BST<T>::fillArray() {
  fillArrayHelper(m_root);
}

template <typename T>
void BST<T>::fillArrayHelper(TreeNode<T>* node) {
  int i = 0;
  if (node != NULL) {
    fillArrayHelper(node->m_left);
    A[i] = node->m_data;
    ++i;
    fillArrayHelper(node->m_right);
  }
}


#endif
