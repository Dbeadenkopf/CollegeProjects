#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"

class Rectangle : public Shape{
 public:
  Rectangle();
  Rectangle(int Length, int Width);
  int GetArea()const;
  void Draw()const;
  ~Rectangle();
 private:
  int length;
  int width;
};

#endif
