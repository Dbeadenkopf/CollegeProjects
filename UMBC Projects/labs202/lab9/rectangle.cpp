#include <cstring>
#include <iostream>
#include "rectangle.h"
#include "Shape.h"
using namespace std;
Rectangle::Rectangle(){
  length = 0;
  width = 0;
}
Rectangle::~Rectangle(){
  cout << "Rectangle destroyed" << endl;
}
Rectangle::Rectangle(int Length, int Width){
  length = Length;
  width = Width;
}
int Rectangle::GetArea()const{
  return (length*width);
}
void Rectangle::Draw()const{
  cout << "Drawing a Rectangle" << endl;
  cout << "----------" << endl;
  cout << "|        |" << endl;
  cout << "----------" << endl;
}
