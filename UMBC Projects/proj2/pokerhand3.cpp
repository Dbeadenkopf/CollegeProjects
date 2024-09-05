/* File: pokerhand.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 2
   
   Implementation of PokerHand class.
   See pokerhand.h for documentation.
*/
#include <cstring>
#include <iostream>
using namespace std;
//static int comP1;
//static int comP2;
//static int comP3;
#include "pokerhand.h"// created static array of indxs to be used throughout entire code
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
  // ******** maybe just sort this array if the point values are greater, 
  // gets rid of index
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

// The member function below prints the rank of each indiviual Rank
// does most of printing based on bool logic of the correcponding rank
// precondition: sets bool values to bool functions
// postcondition: evaluates boolean expression and displays the conclusion of the expression
void PokerHand::printRank(){// need to get rank before the correct rank is displayed out
  bool rFlush = isFlush();
  bool rRoyal = isRoyalFlush();
  bool rOnePair = isOnePair();
  bool rTwoPair = isTwoPair();
  bool rStraight = isStraight();
  bool rSFlush = isStraightFlush();
  bool rfKind = isFourOfAKind();
  bool rhCard = isHighCard();
  bool rfHouse = isFullHouse();
  bool r3OfKind = isThreeOfAKind();
  if (rFlush == true){
    cout << "Current pick: " << "Flush" << endl;
  }
  if (rRoyal == true){
    cout << "Current pick: " << "Royal Flush" << endl;
  }
  if (rOnePair == true){
    cout << "Current pick: " << "One Pair" << endl;
  }
  if (rTwoPair == true){
    cout << "Current pick: " << "Two Pair" << endl;
  }
  if (rStraight == true){
    cout << "Current pick: " << "Straight" << endl;
  }
  if (rSFlush == true){
    cout << "Current pick: " << "Straight Flush" << endl;
  }
  if (rfKind == true){
    cout << "Current pick: " << "Four Of A Kind" << endl;
  }
  if (rhCard == true){
    cout << "Current pick: " << "High Card" << endl;
  }
  if (rfHouse == true){
    cout << "Current pick: " << "Full House" << endl;
  }
  if (r3OfKind == true){
    cout << "Current pick: " << "Three Of A Kind" << endl;
  }

}


// The sort function sorts each card in the array 
// based on the point values of the cards
// precondition: creates an obj ptr of card and 
// loops through each card in array twice
// postcondition: after evaluation expression, the ptr
// is used to sort the array postions 
void PokerHand::sort(){
  // then an object will need to hold it instead of int varible
  Card ptr;
  for (int i = 0; i < FIVE; i++){
    for (int j = i+1; j < FIVE; j++){
      if (m_cards[i].points() > m_cards[j].points()){
	ptr = m_cards[j];
	m_cards[j] = m_cards[i];
	m_cards[i] = ptr;
      }
    }
  }
}
// prints cards one per line
void PokerHand::printCards(){
  for (int i = 0; i < FIVE; i++){
    m_cards[i].print();
  }
}
// The function compares the hand being passed in
// precondition: takes in a reference parameter object
// postcondtion: used reference object to determine better
// ranks and returns a number for winner determination
int PokerHand::cmp(PokerHand &otherHand){
  if (m_rank > otherHand.m_rank){
    return -1;
  }
  if(m_rank < otherHand.m_rank){
    return 1;
  }
  if(m_rank == otherHand.m_rank){
    if (m_rank && otherHand.m_rank == OnePair){
      if(otherHand.m_firstPairPoints > m_firstPairPoints){
	return 1;
      }
      if(otherHand.m_firstPairPoints < m_firstPairPoints){
	return -1;
      }
      else{
	if (otherHand.m_firstPairPoints == m_firstPairPoints){
	  if (otherHand.m_cards[0].points() > m_cards[0].points()){
	    return 1;
	  }
	  if (otherHand.m_cards[0].points() < m_cards[0].points()){
	    return -1;
	  }
	  else if(otherHand.m_cards[0].points() == m_cards[0].points()){
	    if (otherHand.m_cards[1].points() > m_cards[1].points()){
              return 1;
            }
            if (otherHand.m_cards[1].points() < m_cards[1].points()){
              return -1;
            }
	  }
	  if(otherHand.m_cards[1].points() == m_cards[1].points()){
	    if (otherHand.m_cards[2].points() > m_cards[2].points()){
	      return 1;
	    }
	    if (otherHand.m_cards[2].points() < m_cards[2].points()){
	      return -1;
	    }
	  }
	  if(otherHand.m_cards[2].points() == m_cards[2].points()){
	    if (otherHand.m_cards[3].points() > m_cards[3].points()){
	      return 1;
	    }
	    if(otherHand.m_cards[3].points() < m_cards[3].points()){
	      return -1;
	    }
	  }
	  if(otherHand.m_cards[3].points() == m_cards[3].points()){
	    if (otherHand.m_cards[4].points() > m_cards[4].points()){
	      return 1;
	    }
	    if (otherHand.m_cards[4].points() < m_cards[4].points()){
	      return -1;
	    }
	    else{
	      return 0;
	    }
	  }

	}
      }
    }
    if (m_rank && otherHand.m_rank == TwoPair){ 
      if(otherHand.m_firstPairPoints  > m_firstPairPoints ){
	return 1;
      }   
      if(otherHand.m_firstPairPoints  < m_firstPairPoints ){
	return -1;
      }
      else{
	if(otherHand.m_secondPairPoints > m_secondPairPoints){
	  return 1;
	}
	if(otherHand.m_lastCardPoints < m_secondPairPoints){
          return -1;
        }
	else{
	  if(otherHand.m_lastCardPoints > m_lastCardPoints){
	    return 1;
	  }
	  if(otherHand.m_lastCardPoints < m_lastCardPoints){
	    return -1;
	  }
	  else{
	    return 0;
	  }
	}
      }
    }
    if (m_rank && otherHand.m_rank == ThreeOfAKind){
      if (otherHand.m_tripletPoints > m_tripletPoints){
	return 1;
      }
      if (otherHand.m_tripletPoints < m_tripletPoints){
        return -1;
      }
      else{
	if (otherHand.m_tripletPoints == m_tripletPoints){
	  if (otherHand.m_cards[4].points() > m_cards[4].points()){
	    return 1;
	  }
	  if (otherHand.m_cards[4].points() < m_cards[4].points()){
	    return -1;
	  }
	  if(otherHand.m_cards[4].points() == m_cards[4].points()){
	    if (otherHand.m_cards[3].points() > m_cards[3].points()){
	      return 1;
	    }
	    if (otherHand.m_cards[3].points() < m_cards[3].points()){
	      return -1;
	    }
	  }
	  if(otherHand.m_cards[3].points() == m_cards[3].points()){
	    if (otherHand.m_cards[2].points() > m_cards[2].points()){
	      return 1;
	    }
	    if (otherHand.m_cards[2].points() < m_cards[2].points()){
	      return -1;
	    }
	  }
	  if(otherHand.m_cards[2].points() == m_cards[2].points()){
	    if (otherHand.m_cards[1].points() > m_cards[1].points()){
	      return 1;
	    }
	    if(otherHand.m_cards[1].points() < m_cards[1].points()){
	      return -1;
	    }
	  }
	  if(otherHand.m_cards[1].points() == m_cards[1].points()){
	    if (otherHand.m_cards[0].points() > m_cards[0].points()){
	      return 1;
	    }
	    if (otherHand.m_cards[0].points() < m_cards[0].points()){
	      return -1;
	    }
	    else{
	      return 0;
	    }
	  }
	}
      }
    }
    if (m_rank && otherHand.m_rank == FourOfAKind){
      if (otherHand.m_quadrupletPoints > m_quadrupletPoints){
        return 1;
      }
      if (otherHand.m_quadrupletPoints < m_quadrupletPoints){
        return -1;
      }
      else{
	if(otherHand.m_lastCardPoints > m_lastCardPoints){
          return 1;
        }
        if(otherHand.m_lastCardPoints < m_lastCardPoints){
          return -1;
        }
        else{
          return 0;
        }
      }
    }
    if (m_rank && otherHand.m_rank == FullHouse){
      if (otherHand.m_tripletPoints && otherHand.m_firstPairPoints > m_tripletPoints && m_firstPairPoints){
        return 1;
      }
      if (otherHand.m_tripletPoints && otherHand.m_firstPairPoints < m_tripletPoints && m_firstPairPoints){
        return -1;
      }
      else{
        return 0;
      }
    }
    if (m_rank && otherHand.m_rank == HighCard){
      if (otherHand.m_cards[4].points() > m_cards[4].points()){
	return 1;
      }
      if (otherHand.m_cards[4].points() < m_cards[4].points()){
	return -1;
      }
      if(otherHand.m_cards[4].points() == m_cards[4].points()){
	if (otherHand.m_cards[3].points() > m_cards[3].points()){
	  return 1;
	}
	  if (otherHand.m_cards[3].points() < m_cards[3].points()){
	    return -1;
	  }
	}
      if(otherHand.m_cards[3].points() == m_cards[3].points()){
	if (otherHand.m_cards[2].points() > m_cards[2].points()){
	  return 1;
	}
	if (otherHand.m_cards[2].points() < m_cards[2].points()){
	  return -1;
	}
      }
      if(otherHand.m_cards[2].points() == m_cards[2].points()){
	if (otherHand.m_cards[1].points() > m_cards[1].points()){
	  return 1;
	}
	if(otherHand.m_cards[1].points() < m_cards[1].points()){
	  return -1;
	}
      }
      if(otherHand.m_cards[1].points() == m_cards[1].points()){
	if (otherHand.m_cards[0].points() > m_cards[0].points()){
	  return 1;
	}
	if (otherHand.m_cards[0].points() < m_cards[0].points()){
	  return -1;
	}
	else{
	  return 0;
	}
      }
    }
    if (m_rank && otherHand.m_rank == Flush){
      if (otherHand.m_cards[4].points() > m_cards[4].points()){
        return 1;
      }
      if (otherHand.m_cards[4].points() < m_cards[4].points()){
        return -1;
      }
      if(otherHand.m_cards[4].points() == m_cards[4].points()){
        if (otherHand.m_cards[3].points() > m_cards[3].points()){
          return 1;
        }
	if (otherHand.m_cards[3].points() < m_cards[3].points()){
	  return -1;
	}
      }
      if(otherHand.m_cards[3].points() == m_cards[3].points()){
        if (otherHand.m_cards[2].points() > m_cards[2].points()){
          return 1;
        }
        if (otherHand.m_cards[2].points() < m_cards[2].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[2].points() == m_cards[2].points()){
        if (otherHand.m_cards[1].points() > m_cards[1].points()){
          return 1;
        }
        if(otherHand.m_cards[1].points() < m_cards[1].points()){
          return -1;
	}
      }
      if(otherHand.m_cards[1].points() == m_cards[1].points()){
        if (otherHand.m_cards[0].points() > m_cards[0].points()){
          return 1;
        }
        if (otherHand.m_cards[0].points() < m_cards[0].points()){
          return -1;
        }
        else{
          return 0;
        }
      }
    }
    if (m_rank && otherHand.m_rank == Straight){
      if (otherHand.m_cards[4].points() > m_cards[4].points()){
        return 1;
      }
      if (otherHand.m_cards[4].points() < m_cards[4].points()){
        return -1;
      }
      if(otherHand.m_cards[4].points() == m_cards[4].points()){
        if (otherHand.m_cards[3].points() > m_cards[3].points()){
          return 1;
        }
        if (otherHand.m_cards[3].points() < m_cards[3].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[3].points() == m_cards[3].points()){
        if (otherHand.m_cards[2].points() > m_cards[2].points()){
          return 1;
        }
        if (otherHand.m_cards[2].points() < m_cards[2].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[2].points() == m_cards[2].points()){
        if (otherHand.m_cards[1].points() > m_cards[1].points()){
          return 1;
        }
        if(otherHand.m_cards[1].points() < m_cards[1].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[1].points() == m_cards[1].points()){
        if (otherHand.m_cards[0].points() > m_cards[0].points()){
          return 1;
        }
        if (otherHand.m_cards[0].points() < m_cards[0].points()){
          return -1;
        }
        else{
	  return 0;
	}
      }
    }
    if (m_rank && otherHand.m_rank == StraightFlush){
      if (otherHand.m_cards[4].points() > m_cards[4].points()){
        return 1;
      }
      if (otherHand.m_cards[4].points() < m_cards[4].points()){
        return -1;
      }
      if(otherHand.m_cards[4].points() == m_cards[4].points()){
        if (otherHand.m_cards[3].points() > m_cards[3].points()){
          return 1;
        }
        if (otherHand.m_cards[3].points() < m_cards[3].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[3].points() == m_cards[3].points()){
        if (otherHand.m_cards[2].points() > m_cards[2].points()){
          return 1;
        }
        if (otherHand.m_cards[2].points() < m_cards[2].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[2].points() == m_cards[2].points()){
        if (otherHand.m_cards[1].points() > m_cards[1].points()){
          return 1;
        }
        if(otherHand.m_cards[1].points() < m_cards[1].points()){
          return -1;
        }
      }
      if(otherHand.m_cards[1].points() == m_cards[1].points()){
	if (otherHand.m_cards[0].points() > m_cards[0].points()){
	  return 1;
	}
	if (otherHand.m_cards[0].points() < m_cards[0].points()){
	  return -1;
	}
	else{
	  return 0;
	}
      }
    }
  }
  return 0;
} 

 // possibley using get rank in this to for the comparisons of the ranks but then we need to do multiple logic with the hand 
  //
  // look at its rank or the passed cards in rank and then determine which could be true????

 




// The function determines if a hand has a royal flush
// precondition: selectivley selects to see if all the cards
// go by the value of a royal and all same suit
// postcondition: returns true and sets the m_rank varible to 
// RoyalFLush which indicates royal flush rank
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

bool PokerHand::isFullHouse(){
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points()){

    m_tripletPoints = m_cards[0].points();
    m_firstPairPoints = m_cards[3].points();
    m_rank = FullHouse;
    return true;
  }
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points()){

    m_tripletPoints = m_cards[0].points();
    m_firstPairPoints = m_cards[3].points();
    m_rank = FullHouse;
    return true;
  }

  return 0;
}
bool PokerHand::isOnePair(){
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){
    
    m_firstPairPoints = m_cards[1].points();
    m_rank = OnePair;
    return true;
  }
  if (m_cards[0].points() != m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){

    m_firstPairPoints = m_cards[2].points();
    m_rank = OnePair;
    return true;
  }
  if (m_cards[0].points() != m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){

    m_firstPairPoints = m_cards[3].points();
    m_rank = OnePair;
    return true;
  }
  if (m_cards[0].points()!= m_cards[1].points() &&
      m_cards[1].points()!= m_cards[2].points() &&
      m_cards[2].points()!= m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points()){

    m_firstPairPoints = m_cards[4].points();
    m_rank = OnePair;
    return true;
  }
  return 0;
}
bool PokerHand::isTwoPair(){
  if (m_cards[0].points()!= m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points()!= m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points()){
    
    m_lastCardPoints = m_cards[0].points();
    m_firstPairPoints = m_cards[3].points(); 
    m_secondPairPoints = m_cards[1].points();
    m_rank = TwoPair;
    return true;
  }
  else if (m_cards[0].points() == m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() != m_cards[4].points()) {

    m_firstPairPoints = m_cards[3].points() ;
    m_secondPairPoints = m_cards[1].points() ;
    m_lastCardPoints = m_cards[4].points() ;
    m_rank = TwoPair ;
    return true ;
  }
  else if (m_cards[0].points() == m_cards[1].points() &&
	   m_cards[1].points() != m_cards[2].points() &&
	   m_cards[2].points() != m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points()) {

    m_firstPairPoints = m_cards[4].points() ;
    m_secondPairPoints = m_cards[1].points() ;
    m_lastCardPoints = m_cards[2].points() ;
    m_rank = TwoPair ;
    return true ;
  }
  
  return 0;

}
bool PokerHand::isThreeOfAKind(){
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() != m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){

    m_tripletPoints = m_cards[0].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  if (m_cards[0].points() != m_cards[1].points() &&
      m_cards[1].points() != m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() == m_cards[4].points()){

    m_tripletPoints = m_cards[2].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  if (m_cards[0].points() != m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){

    m_tripletPoints = m_cards[1].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  return 0;
}

bool PokerHand::isStraightFlush(){
  bool same = isAllOneSuit();
  bool sequence = isSequence();
  if (same == true && sequence == true){
    m_rank = StraightFlush;// what if we call get rank in the function here 
    return true;
  }
  return 0;
}

bool PokerHand::isFourOfAKind(){
  if (m_cards[0].points() == m_cards[1].points() &&
      m_cards[1].points() == m_cards[2].points() &&
      m_cards[2].points() == m_cards[3].points() &&
      m_cards[3].points() != m_cards[4].points()){
    
    m_lastCardPoints = m_cards[4].points() ;
    m_quadrupletPoints = m_cards[0].points();
    m_rank = FourOfAKind;
    return true;
  }
  else if (m_cards[0].points() != m_cards[1].points() &&
	   m_cards[1].points() == m_cards[2].points() &&
	   m_cards[2].points() == m_cards[3].points() &&
	   m_cards[3].points() == m_cards[4].points()){

    m_lastCardPoints = m_cards[0].points() ;
    m_quadrupletPoints = m_cards[1].points();
    m_rank = FourOfAKind;
    return true;
  }


  return 0;
}
bool PokerHand::isStraight(){
  bool hasSequence = isSequence();
  bool same = isAllOneSuit();
  if (hasSequence == true && same == false){
    m_rank = Straight;
    return true;
  }
  return 0;
}

bool PokerHand::isFlush(){
  bool check2Pair = isTwoPair();
  bool checkRoyal = isRoyalFlush();
  bool same = isAllOneSuit();
  bool sequence = isSequence();
  bool oneP = isOnePair();
  bool checkFHouse = isFullHouse();
  bool checkThree = isThreeOfAKind();
  bool checkFour = isFourOfAKind();
  if (same == true && sequence == false && checkRoyal == false &&
      check2Pair == false && oneP == false && checkFHouse == false
      && checkThree == false && checkFour == false){
    m_rank = Flush;
    return true;
  }
  return 0;
}


bool PokerHand::isHighCard(){
  bool rFlush = isFlush();
  bool rRoyal = isRoyalFlush();
  bool rOnePair = isOnePair();
  bool rTwoPair = isTwoPair();
  bool rStraight = isStraight();
  bool rSFlush = isStraightFlush();
  bool rfKind = isFourOfAKind();
  bool rfHouse = isFullHouse();
  bool r3OfKind = isThreeOfAKind();
  for (int i = 0; i < FIVE; i++){
    if (m_cards[4].points() > m_cards[i-1].points() && (m_cards[4].points() < 8 || m_cards[4].points() <= 14) && rFlush == false &&  rRoyal == false &&
      rOnePair == false &&  rTwoPair == false &&  rStraight == false && rSFlush == false &&  rfKind == false &&  rfHouse == false &&
      r3OfKind == false){
    m_rank = HighCard;
      return true;
  }
  }
  return 0;
}
// this function needs to be changed to a universal use in order for 7 card stub to accuratly work
bool PokerHand::isAllOneSuit(){// maybe im using this boolan funcion wrong?
  if (m_cards[0].suit() == 1 && m_cards[1].suit() == 1 && m_cards[2].suit() == 1 && m_cards[3].suit() == 1 && m_cards[4].suit() == 1){
    return true;
  }
  if (m_cards[0].suit() == 2 && m_cards[1].suit() == 2 && m_cards[2].suit() == 2 && m_cards[3].suit() == 2 && m_cards[4].suit() == 2){
    return true;
  }
  if (m_cards[0].suit() == 3 && m_cards[1].suit() == 3 && m_cards[2].suit() == 3 && m_cards[3].suit() == 3 && m_cards[4].suit() == 3){
    return true;
  }
  if (m_cards[0].suit() == 4 && m_cards[1].suit() == 4 && m_cards[2].suit() == 4 && m_cards[3].suit() == 4 && m_cards[4].suit() == 4){
    return true;
  }
  return 0;
}

bool PokerHand::isSequence(){
  if (m_cards[0].points() == 2 && m_cards[1].points() == 3 &&
      m_cards[2].points() == 4 && m_cards[3].points() == 5 &&
      m_cards[4].points() == 6){
    return true;
  }
  if (m_cards[0].points() == 3 &&
      m_cards[1].points() == 4 && m_cards[2].points() == 5 &&
      m_cards[3].points() == 6 && m_cards[4].points() == 7)
    {
      return true;
    }
  if (m_cards[0].points() == 4 && m_cards[1].points() == 5 &&
      m_cards[2].points() == 6 && m_cards[3].points() == 7 &&
      m_cards[4].points() == 8)
    {
      return true;
    }
  if (m_cards[0].points() == 5 &&
      m_cards[1].points() == 6 && m_cards[2].points() == 7 &&
      m_cards[3].points() == 8 && m_cards[4].points() == 9){
    return true;
  }
  if (m_cards[0].points() == 6 && m_cards[1].points() == 7 &&
      m_cards[2].points() == 8 && m_cards[3].points() == 9 &&
      m_cards[4].points() == 10){
    return true;
  }
  if (m_cards[0].points() == 7 && m_cards[1].points() == 8
      && m_cards[2].points() == 9 && m_cards[3].points() == 10
      && m_cards[4].points() == 11){
    return true;
  }
  if (m_cards[0].points() == 8 && m_cards[1].points() == 9 &&
      m_cards[2].points() == 10 && m_cards[3].points() == 11
      && m_cards[4].points() == 12){
    return true;
  }
  if  (m_cards[0].points() == 9 && m_cards[1].points() == 10 &&
       m_cards[2].points() == 11 && m_cards[3].points() == 12
       && m_cards[4].points() == 13){
    return true;
  }
  return 0;
}

// should i be using a main to test these as such as the cards class 
// or is the card class needing to be included inside this file  
  
// what signifies each card in this file is it
// firstpairpoints secondpairpoints thing?
// do we even need to do this?

  

// sorts the point values of the hand, can use from prevoius code

