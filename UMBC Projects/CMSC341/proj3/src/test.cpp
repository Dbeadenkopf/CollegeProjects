#include <iostream>
#include <cstring>
#include "AVLTree.h"
#include "AVLNode.h"
#include "AVLTreeBase.h"
using namespace std;


int main(){
  AVLNode<int,char> obj;
  obj.height(AVLTreeBase::CHARACTER);
  obj.height(AVLTreeBase::STRING);
  //obj.dump();
  
  AVLTree<int,int> obj2;
  obj2.insert(AVLTreeBase::CHARACTER);
  


  return 0;
}
