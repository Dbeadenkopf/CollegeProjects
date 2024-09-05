#include <iostream>
#include "PinHit.h"

using namespace std;
PinHit::PinHit(){
  m_pin = 0;
  m_hits = 3;
}

PinHit::PinHit(int key, int value){
  m_pin = key;
  m_hits = value;
  if (isInRange(m_pin) == true){
    cout << "Pin is in correct range" << endl;
  }
  else{
    cout << "Not in correct range" << endl;
  }
}

void PinHit::SetKey(int pin){
  m_pin = pin;
}

int PinHit::GetKey() const{
  return m_pin;
}

int PinHit::GetValue() const{
  return m_hits;
}


// how will increment hits operate?
void PinHit::IncrementHits(){
  m_hits++;
}


bool PinHit::isInRange(int Pin){
  for (int i = 0; i < checkNum; i++){
    if (Pin == i){
      return true;
    }
  }
  return false;
}


// compare to function works
int PinHit::CompareTo(const PinHit& other)const{
  if (m_hits == other.m_hits){
    return 0;
  }
  if (m_hits < other.m_hits){
    return -1;
  }
  else{
    return 1;
  }
  return 0; // for the moment
}

// equal, equals operator works
bool PinHit::operator==(const PinHit& other){
  if (this->GetKey() == other.m_pin){
    return true;
  }
  else{
    return false;
  }
}
