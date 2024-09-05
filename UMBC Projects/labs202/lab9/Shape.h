#ifndef SHAPE_H
#define SHAPE_H
class Shape{
 public:
  Shape();
  ~Shape();
  // pure virtual 
  virtual int GetArea() const = 0; // no body is inside
  virtual void Draw() const; 









};


#endif
