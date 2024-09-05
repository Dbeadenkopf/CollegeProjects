// This is the header file for
// the class AVL node which will simulate 
// an instance of a single avl node within
// the AVL tree, the avl node will
// have a left and right sub children
// as well as data can be within the node
// each node has a height that must be maintained

#ifndef _AVLNODE_H_
#define _AVLNODE_H_
//#define DTYPE int // macro DTYPE defined as an integer
//#include "AVLTree.h" // including this to use objects of type AVLTree
#include "AVLTreeBase.h"





template <class T, class V>
class AVLNode
{
 public:
  
  // friending so AVLnode can
  // access all private data
  // members of the AVLTree


  friend class AVLTreeBase;

  // The destructor for the node, that
  // will give data members there defualt values
  AVLNode();

  // destructor for memory managmenet
  // destroys data, also could destroy left
  // and right
  ~AVLNode();

  // The constructor/accessor that takes in values of type
  // T and type V
  // and sets them to the designated private data member
  // we may need to template this for passing in anything
  //AVLNode<T,V>(T typeof,V m_data);


  // bool function that will check
  // for the left node inbalance
  bool checkLeftInbalance() const;


  // bool function that will check
  // for the right node inbalance
  bool checkRightInbalance() const;



  // The prototype of the function
  // that does a single right rotation
  // mechanical operation on the tree
  void singleRightRotate();

  // the prototype of the function
  // that does the single left rotation
  // mechinical operation on the tree
  void singleLeftRotate();


  // The height Maintain function
  // bascically maintains the height of 
  // the root node and right/left nodes 
  // of the tree
  void height(AVLTreeBase::DataType x);
  
  // an accessor that will accept 
  // data of type datatype
  AVLNode(AVLTreeBase::DataType x);


  // getter to return the data 
  AVLTreeBase::DataType getData() const;
  
  // acts as the debugger for the class
  void dump();


 private:
  AVLTreeBase::DataType data; // The data member that will hold the data type
  //T type; // the data member that will hold the type of 
  // the data of each node
  //AVLNode left,right;
  AVLNode<T,V> *leftGrab;
  AVLNode<T,V>  *rightGrab;
  int Height; // the varible that will maintain the 
  // heights of each left node 
  
};




#include "AVLNode.cpp"
#endif
