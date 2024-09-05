#include <stdlib.h>

// going to learn about ? how to see if each struct is placed
// right after the prevous one, we are making this
// to then observe what happens in the gdb debugger

struct rec{
  char field1[5];
  int field2;
};

int main(){

  struct rec myRec = {"Hi", 47};


  return 0;

}
