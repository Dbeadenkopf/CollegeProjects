#ifndef _AVLTREEBASE_H_
#define _AVLTREEBASE_H_
//#include "AVLTree.h"


class AVLTreeBase
{
  // dummy class required to remove template dependency
 public:

  /*
   * IN = in-order print
   * PRE = pre-order print
   * POST = post-order print
   * LEVEL = level-order print
   */
  // an enumeratoin that will that has indexes 
  // that simulate each major travers print
  // orders of a avl tree, when traversing the tree
  // the AVL tree has to do a a printOder of
  // its tree based off of this enumeration
  // 
  enum PrintOrder{IN, PRE, POST, LEVEL};
  // what
  /*
   * types for template instantiations
   */
  
  enum DataType{CHARACTER, STRING};
  // is this number feild going
  // to be templated 
  enum NumberType{INTEGER, FLOAT};
};

#endif /* _AVLTREEBASE_H_ */
