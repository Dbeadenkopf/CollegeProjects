#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include "Node.h"
#include <iostream>
using namespace std;


class Polynomial{

 public:
  Polynomial();
  Polynomial(const Polynomial& p);
  ~Polynomial();

  void insertMonomial(long coeff, unsigned int deg);

  Polynomial add(const Polynomial& p) const;
  Polynomial subtract(const Polynomial& p) const;
  Polynomial multiply(const Polynomial& p) const;

  Polynomial modulo(const Polynomial& p) const;

  unsigned int degree() const;
  long evaluate(long x) const;

  Polynomial& operator=(const Polynomail& p);
  friend ostream& operator<<(ostream& sout, const Polynomial& p);

 private:

  Node *m_head;


};
#endif
