// The header file that holds the AVL tree
// class. The Class will simulate an entire
// avl Tree which will have a root value,
// nodes within the tree that have sub nodes
// the heights of the tree will need to be maintained
// the tree will take the input that it is given
// to it and text data will need to be parsed into 
// the nodes of the tree, each node will have to know
// the value of what they are recieving

#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <iostream>
#include <stdlib.h>
#include "AVLTreeBase.h"
#include "AVLNode.h"
//#define DTYPE int

using namespace std;
// NEEDS TO BE TEMPLATED SO THEY 
// CAN TEST THE TREE WITH ANY DATA
template <class T, class V>
class AVLNode; // forwarding declaring the node class


template <class T, class V>
class AVLTree : public AVLTreeBase
{
  // forward friending the AVLNode class
  // so we can access all data from that class
  
  friend class AVLNode<T,V>;

  
  friend std::ostream& operator<<(std::ostream& os, const AVLTree<T, V>& obj);
 public:
  // The default constructor 
  // That will set that private
  // data to its default members
  AVLTree();

  // The copy constructor that will 
  // 
  // AVLTree(const AVLTree& other);
  
  // checks if the pointer is null
  bool empty();

  // acts as the debugger of the class
  void dump();

  // the find function acts
  // as the root taker, also
  // checks if the node is null
  // if (find it) return a pointer
  // and your are done
  //  DTYPE* find(DTYPE x);

  // very similar to find
  // if the tree is NULL, make 
  // a new node and that will
  // be where you put the new item
  // member protype that is critical
  // for the tree implementation
  void insert(AVLTreeBase::DataType x);


  // the overloaded assignment operator
  // which will check for self assignment in
  // the tree
  const AVLTree<T,V>& operator=(const AVLTree<T, V>& rhs);



  // the prototype that does
  void inorderPrint();


  // The print_range function that is seperate from
  // the avlforrest print range, the prototype accepts
  // an ostream as one argument, a numerical upperbound as 
  // the second and a numerical lower bound as the third
  void print_range(std::ostream&,int upBound, int lowBound);


 private:
  // a pointer of The avlNode class, will be used
  // to point at things in the node or anything
  // of the node class?
  AVLNode<T,V> *nptr; // the host object will have this pointer
};

// ostream operator to display parts of the tree

//std::ostream& operator<<(std::ostream& os, const AVLTree<T,V>& obj);


#include "AVLTree.cpp"
#endif
