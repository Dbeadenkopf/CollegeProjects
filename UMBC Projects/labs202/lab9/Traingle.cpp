#include <cstring>
#include <iostream>
#include "Traingle.h"
#include "Shape.h"
using namespace std;
Triangle::Triangle(){
  length = 0;
  height = 0;
}
Triangle::~Triangle(){
  cout << "Triangle destroy" << endl;                                         
}
Triangle::Triangle(int Length, int Height){
  length = Length;
  height = Height;
}
int Triangle::GetArea()const{
  return ((length*height)*0.5);
}
void Triangle::Draw()const{
  cout << "Drawing a Traingle" << endl;
  cout << "  / \\" << endl;
  cout << " /   \\" << endl;
 cout << "/_____\\" << endl;
}
