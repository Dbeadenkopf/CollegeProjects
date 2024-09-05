#include <iostream>
#include "Shape.h"
#include "rectangle.h"
#include "Traingle.h"
using namespace std;

int main(){

  Shape *shapePtr;       // Base class pointer 
  Rectangle aRectangle(5,4);  // creating a rectangle object
  Triangle aTriangle(4,4);    // creating a triangle object

  shapePtr = &aRectangle;// Write code to perform dynamic binding here
  cout << "Area of rectangle = " << shapePtr->GetArea() << endl;
  shapePtr->Draw(); // using Shape pointer to invoke the traingles draw function
  shapePtr = &aTriangle; 
  cout << "Area of Traingle = " << shapePtr->GetArea() << endl;
  shapePtr->Draw();
  return 0;
}
