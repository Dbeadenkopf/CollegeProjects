#include <iostream>
#include <cstring>
#include <exception>
#include "iterator_ex.h"
#include "sorted.h"
using namespace std;

iterator_ex::iterator_ex(): singleV("empty") {
  // no code
};
iterator_ex::iterator_ex(const char* message){
  singleV = message;
}
const char* iterator_ex::what() const throw(){
  return singleV; // returing c-string
}


