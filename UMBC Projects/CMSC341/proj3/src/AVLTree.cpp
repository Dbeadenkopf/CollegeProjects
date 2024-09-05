#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include "AVLTree.h"
#include "AVLNode.h"

using namespace std;


template <class T, class V>
AVLTree<T,V>::AVLTree(){
  nptr = NULL;
}




// how can I make this class replicate
// the find of the data type enumeration
/*DTYPE* AVLTree::find(DTYPE x){
if (empty()){
    return NULL;
  }
  if (nptr->data == x){
    return &(nptr->data);
  }
  if (nptr->data < x){
    // this isnt returning the right node data
    // this isnt correct at all
    return right.nptr->data; // go into the right node and find
    // the data?
  }
  return left.nptr->data; // changed these from find() to insert 
  }*/

template <class T,class V>
// the parameters would have to correspond to 
// the templates
void AVLTree<T,V>::insert(AVLTreeBase::DataType x){
  if (empty()){
    nptr = new AVLNode<T,V>(x);
  }
  else{ 
    nptr->height(x);
  }
}

template <class T, class V>
const AVLTree<T,V>& AVLTree<T,V>::operator=(const AVLTree<T,V>& rhs){
  if (this == &rhs){
    return *this;
    delete nptr;
  }
  if(rhs.nptr == NULL){
    nptr = NULL;
  }
  else{
    nptr = new AVLNode<T,V>( *(rhs.nptr));
  }
  return *this;
}



template <class T, class V>
bool AVLTree<T,V>::empty(){
  nptr = NULL; // why is this set to null?
  return true; // return true signifies that 
  // the spot is empty
}


template <class T, class V>
void AVLTree<T,V>::dump(){
  cout << "***** AVLTree::dump()\n";
  cout << "      this = " << this << endl;
  cout << "      nptr = " << nptr << endl;
  if(!empty()){
    nptr->dump(); // whats up with this?
  }
}

template <class T,class V>
std::ostream& operator<<(std::ostream& os, const AVLTree<T,V>& obj){
  os << obj.nptr;
  //os << obj.left;
  //os << obj.right;
  return os;
}



#endif
