#ifndef ITERATOR_EX_H_
#define ITERATOR_EX_H_
#include <exception>
using namespace std;
class iterator_ex : public exception{
 public:
  // Default constructor
  iterator_ex();
  
  // Non-default constructor
  iterator_ex(const char* message);
  
  // Accessor function
  const char* what() const throw();
  
 private:
  const char* singleV;

};

#endif
