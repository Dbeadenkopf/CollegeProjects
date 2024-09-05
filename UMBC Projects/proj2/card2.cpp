/* File: card.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 2

   Implementation of Card member functions.
   See card.h for documentation.

*/

#include <iostream>
#include <cstring>
#include "card.h"
#include "pokerhand.h"
using namespace std;


// Default constructor marks card as invalid
//
Card::Card(){
  m_suit = Invalid;// given the Invalid suit because not initilized  
  m_points = 0; // host card(not initilized)
}

Card::Card(cSuit s, cPoints p){
  m_suit = s;
  m_points = p;
  if (m_points < 2 || m_points > 14){// cannot enter a certain suit as well Im asuming ?
    m_suit = Invalid;
    m_points = 0;
  }// your code goes here
}

Card::cPoints Card::points(){
  return Card::m_points;// your code goes here
}

Card::cSuit Card::suit(){
  return Card::m_suit;// your code goes here
}
// coult use a switch statement for print function for all of the points 
void Card::print(){
  // could use a counter for suits and set the m_suit == to the counter and increment the counter getting out each suit 
  // just have to make a bunch of if else statements
  switch (Card::m_points){
  case 0:
    cout << m_points << " of " << m_suit << endl;
    break;
  case 1:
    cout << m_points << " of " << m_suit << endl;
    break;
  case 2:
    if (Card::m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
      if (Card::m_suit ==  2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (Card::m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (Card::m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 3:
    if (Card::m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 4:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 5:// need to increment the cases prob
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 6:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 7:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 8:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 9:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 10:
    if (m_suit == 1){
      cout << m_points << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << m_points << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << m_points << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << m_points << " of " << "Spades" << endl;
	break;
      }
    }
  case 11:
    if (m_suit == 1){
      cout << "Jack" << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << "Jack" << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << "Jack" << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << "Jack" << " of " << "Spades" << endl;
	break;
      }
    }
  case 12:
    if (m_suit == 1){
      cout << "Queen" << " of " << "Clubs" << endl;
      break;
      
      if (m_suit == 2){
	cout << "Queen" << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << "Queen" << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << "Queen" << " of " << "Spades" << endl;
	break;
      }
    }
  case 13:
    if (m_suit == 1){
      cout << "Kings" << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << "Kings" << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << "Kings" << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << "Kings" << " of " << "Spades" << endl;
	break;
      }
    }
  case 14:
    if (m_suit == 1){
      cout << "Ace" << " of " << "Clubs" << endl;
      break;
    
      if (m_suit == 2){
	cout << "Ace" << " of " << "Diamonds" << endl;
	break;
      }
      if (m_suit == 3){
	cout << "Ace" << " of " << "Hearts" << endl;
	break;
      }
      if (m_suit == 4){
	cout << "Ace" << " of " << "Spades" << endl;
	break;
      }      
    }
  }

}
