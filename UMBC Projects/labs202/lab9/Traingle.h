#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle : public Shape{
 public:
  Triangle();
  Triangle(int Length, int Height);
  int GetArea()const;
  void Draw()const;
  ~Triangle();
 private:
  int length;
  int height;
};

#endif
