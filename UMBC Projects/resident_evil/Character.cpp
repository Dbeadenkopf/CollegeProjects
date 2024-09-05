#ifndef _CHARACTER_CPP
#define _CHARCTER_CPP


#include "Character.h"
#include <iostream>

using namespace std;


Character::Character(){
  m_id = 0;
  m_counter = 0;
}


Character::~Character(){
  
}

void Character::encounter(Character *ptr) = 0;


void Character::biteMe(Character *ptr) = 0;



void Character::hitMe() = 0;



void Character::cureMe() = 0;


Character Character::*morph() = 0;



bool Character::migrates(){
  return false;
}

string Character::identify() = 0;



unsigned int Character::getID(){
  return m_id;
}


bool Character::isDead(){
  return m_isDead;
}


#endif
