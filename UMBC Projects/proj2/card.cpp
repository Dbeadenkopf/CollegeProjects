/* File: card.cpp
0;136;0c
   CMSC 202 Computer Science II
   Spring 2016 Project 2

   Implementation of Card member functions.
   See card.h for documentation.

*/

#include <iostream>
#include <cstring>
#include "card.h"
#include <stdlib.h>// added these to use random number
#include <stdio.h>// instantiation
#include <time.h> // time include to use time(NULL)

using namespace std;


// Default constructor marks card as invalid
//
Card::Card(){
  srand (time(NULL));
  m_suit = Invalid;// given the Invalid suit because not initilized  
  m_points = 0; // host card(not initilized)
  randomSuit = rand() % 4 + 1; 
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
  switch (m_points){
  case 0:
    if (m_points == 0){
      cout << "found bug card " << endl;
      break;
    }
    cout << ":           :" << endl;
    cout << m_points << " of " << m_suit << endl;
    cout << " here" << endl;
    cout << ":           :" << endl;
    break;
  case 1:
    cout << ":           :" << endl;
    cout << m_points << " of " << m_suit << endl;
    
    break;
  case 2:
    if (m_suit == 1){
      cout << ":         :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
      break;
    }
    else if (m_suit == 3){
      cout << ":        :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 3:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
      cout << ":       :" << endl;
      break;
    }
  case 4:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " <<  "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     

      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 5:// need to increment the cases prob
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " <<  "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 6:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     

      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 7:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " <<  "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " <<  "\u2665" << endl;
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 8:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     
     

      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 9:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 10:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << m_points << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 11:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << "Jack" << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << "Jack" << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << "Jack" << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << "Jack" << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 12:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << "Queen" << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << "Queen" << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << "Queen" << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << "Queen" << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 13:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << "King" << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << "King" << " of " << "Diamonds " << "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << "King" << " of " << "Hearts " << "\u2665" << endl;
     
  
      break;
    }
    else if (m_suit == 4){
      cout << ":       :" << endl;
      cout << "King" << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
  case 14:
    if (m_suit == 1){
      cout << ":       :" << endl;
      cout << "Ace" << " of " << "Clubs " << "\u2663" << endl;
  
      break;
    }
    else if (m_suit ==  2){
      cout << ":       :" << endl;
      cout << "Ace" << " of " << "Diamonds " <<  "\u2666" << endl;
  
      break;
    }
    else if (m_suit == 3){
      cout << ":       :" << endl;
      cout << "Ace" << " of " << "Hearts " << "\u2665" << endl;
  
      break;
    }
    else if (m_suit == 4){
      cout << ":          :" << endl;
      cout << "Ace" << " of " << "Spades " << "\u2660" << endl;
  
      break;
    }
      break;
  }      
}


