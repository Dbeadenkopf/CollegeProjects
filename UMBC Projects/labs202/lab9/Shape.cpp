#include <iostream>
#include <cstring>
#include "Shape.h"
using namespace std;
Shape::Shape(){
  // do nothing
}
Shape::~Shape(){
  // do nothing
}

void Shape::Draw() const{
  cout << "Drawing a shape: " << endl;
}
