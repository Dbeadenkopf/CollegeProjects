#include <iostream>
#include <cstring>
#include <cstdlib>
#include "PinHit.h"
#include "Heap.h"
#include "MinValueHeap.h"
#include <fstream>

using namespace std;

int main(){
  // the only error with testing the in range
  // is that I cant do a ending 8 or 9
  PinHit obj(0227, 791);
  PinHit obj2(8256, 792);

  int hold;
  int result;
  result = 5;
  Heap<PinHit, 8> test;
  MinHeap<PinHit, 8> makeHeap;

  //hold = 8;
  // insert is not working correctly

  // test.Insert(hold);
  //test.dump();
  hold = obj.CompareTo(obj2);
  switch(hold){
  case 0:
    cout << "object hit values are the same" << endl;
    break;
  case -1:
    cout << "obj1 hit value is less than obj2 hit_V" << endl;
    break;
  case 1:
    cout << "obj1 values are greater" << endl;
    break;
  }
  if (obj == obj2){
    cout << "the key values are the same" << endl;
  }
 
  


  return 0;
}

