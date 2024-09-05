#ifndef AVLNODE_H_
#define AVLNODE_H_



#include <iostream>
#include <cstring>
#include "AVLNode.h"
//#include "AVLTree.h"
//#define DTYPE int
using namespace std;


template <class T, class V>
AVLNode<T,V>::AVLNode(){
  data = AVLTreeBase::CHARACTER;
  Height = 1;
  rightGrab = NULL;
  leftGrab = NULL;
}


template <class T, class V>
AVLNode<T,V>::AVLNode(AVLTreeBase::DataType x){
  data = x;
}


template <class T, class V>
AVLNode<T,V>::~AVLNode(){
  cout << "AVLNode destructor, this = " << this << endl;
  // do nothing else
}


template <class T, class V>
void AVLNode<T,V>::height(AVLTreeBase::DataType x){
  if(data > x){
    if(rightGrab == NULL){
      // go ahead and put on the right side of the node
      // occurs here
      rightGrab = new AVLNode<T,V>(x); // base case
    }
    else{
      rightGrab->height(x); // recursion occurs here
    }
  }
  else{
    if (leftGrab == NULL){
      leftGrab = new AVLNode<T,V>(x);
    }
    else{
      leftGrab->height(x);
    }
  }
  if (leftGrab == NULL  && rightGrab == NULL){
    Height = 1;
  }
  else if(leftGrab == NULL && rightGrab!= NULL){
    Height = rightGrab->Height + 1; // making root height greater 
    // than the right node
  }
  else if (leftGrab!= NULL && rightGrab == NULL){
    Height = leftGrab->Height + 1; // making root height greater 
    // than the left node
  }
  else{
    // handles the heights
    if (leftGrab->Height > rightGrab->Height){
      Height = leftGrab->Height + 1;
    }
    else{
      Height = rightGrab->Height + 1;
    }
  }

}

template <class T, class V>
bool AVLNode<T,V>::checkLeftInbalance() const{
  if (leftGrab->Height > (rightGrab->Height + 1)){
    return true; // true indicates that there is an inbalance
  }
  return false;
}


template <class T, class V>
void AVLNode<T,V>::dump(){
  cout << "===== AVLNode::dump()\n";

  cout << "          this = " << this << endl;
  cout << "          Height = " << Height << endl;
  cout << "          right = " << rightGrab->getData() << endl;

  cout << "          left = " << leftGrab->getData() << endl;

  cout << "          data = " << data << endl;
  //cout << "here " << endl;
  //  rightGrab->dump();
  //leftGrab->dump();
}


template <class T, class V>
bool AVLNode<T,V>::checkRightInbalance() const{
  if (rightGrab->Height > (leftGrab->Height + 1)){
    return true; // true will indicate the inbalance
  }
  return false;
}


template <class T, class V>
AVLTreeBase::DataType AVLNode<T,V>::getData() const{
  return data;
}




#endif
