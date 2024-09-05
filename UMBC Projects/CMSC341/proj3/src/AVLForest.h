#ifndef _AVLFOREST_H_
#define _AVLFOREST_H_

/* include your tree implementation  */
#include "AVLTree.h" // tree implementation
#include <vector>
#include <string>

class AVLForest
{
  // vector of trees
  // we use a non-templated base class so we can hold all template instantiations
  // once the templated AVL tree implementation
  // is derived from the the AVLTreeBase, the AVLforrest
  // can then make an instance vector of tree pointers
  // so this vector will hold our created trees
  // then when outputed, it will use this vector 
  // and match up what was inserted with the string
  // of the input files, to get the correct output
  std::vector<AVLTreeBase*> repopulate;

  // other data memebers
  
 public:
  // default constructor
  AVLForest();

  // destructor for memory management
  ~AVLForest();
  
  // this will insert what is 
  // to be put into the tree 
  // based on the input file
  // it takes the input formats as strings
  void insert(std::string);


  
  
  // prototype for the member, function that
  // will take in a regular cout for the ostream
  // to act on as IO output and, the lines of 
  // the range file that is opened which are converted
  // to string types(we may need to template late(yes)
  void print_range(std::ostream& outStream, std::string);

  // the ostream operator that will print
  // all the trees in the vector (in sequence in 
  // which they were first encountered in the input
  // file), so display them based on
  // how they were added in the input file
  friend std::ostream& operator << (std::ostream&, AVLForest&);

  // other member functions

};




#endif /* _AVLFOREST_H_ */
