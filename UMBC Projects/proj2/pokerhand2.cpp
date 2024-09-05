/* File: pokerhand.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 2
   
   Implementation of PokerHand class.
   See pokerhand.h for documentation.
*/

#include <cstring>
#include <iostream>
using namespace std ;
#include "pokerhand.h" // created static array of indxs to be used throughout entire code
PokerHand::PokerHand (){
  m_valid = false ; //  what is m_valid 
  m_rank = NoRank ; // =  hand is not valid m_valid = false?
  
  m_lastCardPoints = 0; // for two pair point valie
  m_firstPairPoints = 0; // for one pair point value, two pair point value of higher pair
  m_secondPairPoints = 0; // two pair points
  m_tripletPoints = 0 ; // 3 of a kind points
  m_quadrupletPoints = 0; // 4 of a kind points
}

PokerHand::PokerHand (Card c0, Card c1, Card c2, Card c3, Card c4){
  // Store cards
  m_cards[0] = c0 ; // each card is being stored in the parameters
  m_cards[1] = c1 ;
  m_cards[2] = c2 ;
  m_cards[3] = c3 ;
  m_cards[4] = c4 ;// going to be comaring each card i this array which would make the implementation eaiser


  // We have cards.
  // Note: this assumes c0, ..., c4 are valid
  //
  m_valid = true;
  m_rank = NoRank;

  // Default values for "additional information"
  //
  m_lastCardPoints = 0 ; // are these the point values given to the cards in the arrays ?each card in the array will get these points
  m_firstPairPoints = 0 ; // 
  m_secondPairPoints = 0 ; // 
  m_tripletPoints = 0 ; // 
  m_quadrupletPoints = 0 ; // 

  // Don't forget to sort
  //
  sort(); 

  // IF YOU WANT THE ALTERNATE CONSTRUCTOR
  // TO DO MORE, PLACE THE CODE AFTER THIS
  // LINE:
  // --------------------------------------
}

PokerHand::pRank PokerHand::getRank(){
  return PokerHand::m_rank;
}

void PokerHand::printRank(){
  PokerHand obj;
  cout << "Current pick:  " << obj.getRank() << endl;
}

void PokerHand::sort(){
  int indxholder;
  for (int i = 0; i < FIVE; i++){
    if (m_cards[i].points() > m_cards[i+1].points()){
      indxholder = m_cards[i].points();
      m_cards[i].points() = m_cards[i+1].points();
      m_cards[i+1].points() = indxholder;
    }
  }

}



void PokerHand::printCards(){
  for (int i = 0; i < FIVE; i++){
    m_cards[i].print();
  }
}

bool PokerHand::isRoyalFlush(){
  bool royalCheck = isAllOneSuit();
  if (m_cards[0].points() == 10 && m_cards[1].points() == 11
      && m_cards[2].points() == 12 && m_cards[3].points() == 13
      && m_cards[4].points() == 14 && royalCheck == true){
    m_rank  = RoyalFlush;
    return true;
  }
  return 0;
}


bool PokerHand::isAllOneSuit(){// maybe im using this boolan funcion wrong?
  if (m_cards[0].suit() == 1 && m_cards[1].suit() == 1 && m_cards[2].suit() == 1 && m_cards[3].suit() == 1 && m_cards[4].suit() == 1){
    return true;
  }
  else if (m_cards[0].suit() == 2 && m_cards[1].suit() == 2 && m_cards[2].suit() == 2 && m_cards[3].suit() == 2 && m_cards[4].suit() == 2){
    return true;
  }
  else if (m_cards[0].suit() == 3 && m_cards[1].suit() == 3 && m_cards[2].suit() == 3 && m_cards[3].suit() == 3 && m_cards[4].suit() == 3){
    return true;
  }
  else if (m_cards[0].suit() == 4 && m_cards[1].suit() == 4 && m_cards[2].suit() == 4 && m_cards[3].suit() == 4 && m_cards[4].suit() == 4){
    return true;
  }
  return 0;
}

// missing boolean value for the function or missing entire function signiture
if (m_cards[indx[0]].points() == 2 && m_cards[indx[1]].points() == 3 &&
    m_cards[indx[2]].points() == 4 && m_cards[indx[3]].points() == 5 &&
    m_cards[indx[4]].points() == 6){
  return true;
 }
if (m_cards[indx[0]].points() == 3 &&
    m_cards[indx[1]].points() == 4 && m_cards[indx[2]].points() == 5 &&
    m_cards[indx[3]].points() == 6 && m_cards[indx[4]].points() == 7)
  {
    return true;
  }
if (m_cards[indx[0]].points() == 4 && m_cards[indx[1]].points() == 5 &&
    m_cards[indx[2]].points() == 6 && m_cards[indx[3]].points() == 7 &&
    m_cards[indx[4]].points() == 8)
  {
    return true;
  }
if (m_cards[indx[0]].points() == 5 &&
    m_cards[indx[1]].points() == 6 && m_cards[indx[2]].points() == 7 &&
    m_cards[indx[3]].points() == 8 && m_cards[indx[4]].points() == 9){
  return true;
 }
if (m_cards[indx[0]].points() == 6 && m_cards[indx[1]].points() == 7 &&
    m_cards[indx[2]].points() == 8 && m_cards[indx[3]].points() == 9 &&
    m_cards[indx[4]].points() == 10){
  return true;
 }
if (m_cards[indx[0]].points() == 7 && m_cards[indx[1]].points() == 8
    && m_cards[indx[2]].points() == 9 && m_cards[indx[3]].points() == 10
    && m_cards[indx[4]].points() == 11){
  return true;
 }
if (m_cards[indx[0]].points() == 8 && m_cards[indx[1]].points() == 9 &&
    m_cards[indx[2]].points() == 10 && m_cards[indx[3]].points() == 11
    && m_cards[indx[4]].points() == 12){
  return true;
 }
if  (m_cards[indx[0]].points() == 9 && m_cards[indx[1]].points() == 10 &&
     m_cards[indx[2]].points() == 11 && m_cards[indx[3]].points() == 12
     /// missing this line of implementtation
     }

// should i be using a main to test these as such as the cards class 
// or is the card class needing to be included inside this file  
  
// what signifies each card in this file is it
// firstpairpoints secondpairpoints thing?
// do we even need to do this?

  

// sorts the point values of the hand, can use from prevoius code

