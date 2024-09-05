#include <iostream>
#include "Llama.h"
using namespace std;

int main(){

  Llama<string,4> stackOne;
  stackOne.push("abc");
  stackOne.push("def");
  stackOne.push("ghi");
  stackOne.dup();
  stackOne.rot();
  stackOne.dump();
  return 0;
}
