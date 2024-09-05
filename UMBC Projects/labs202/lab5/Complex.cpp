#include <iostream>
#include <sstream>
#include <string>
#include "Complex.h"
using namespace std;
Complex::Complex(){ 
  m_real = 1.0;
  m_imag = 0.0;
}
Complex::Complex(double re, double im){
  m_real = re;
  m_imag = im;
}
double Complex::GetReal() const {
  return m_real;
}
double Complex::GetImag() const {
  return m_imag;
}
Complex Complex::Add(Complex a) const{
  return Complex(m_real + a.GetReal(), m_imag + a.GetImag());
}
Complex Complex::Multiply(Complex b){
  return Complex(m_real*b.GetReal() - m_real*b.GetImag(), m_real*b.GetImag() + m_imag*b.GetReal());
}
Complex Complex::Multiply(Complex a, double b){
  return Complex(a.GetReal()*b, a.GetImag()*b);
}
string Complex::ToString() const {
  stringstream ss;
  if (m_imag > 0) 
    ss << m_real << " + " << m_imag << " i";
  else if (m_imag < 0)
    ss << m_real << " - " << -m_imag << " i";
  else
    ss << m_real;
  return ss.str();
}
