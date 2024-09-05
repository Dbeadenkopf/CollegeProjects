#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "CrunoPlayer.h"
#include "game.h"
#include "player.h"
#include "newCrunoGame.h"
#include "card.h"
#include "Cruno8.h"
using namespace std;
/*CrunoPlayer::CrunoPlayer(){
  // empty body
  }*/
// costructor that gives orginal plaer class the passed in values
CrunoPlayer::CrunoPlayer(Game *cptr,unsigned int n_Cards) : Player (cptr, n_Cards){
  // empty body
}
unsigned int CrunoPlayer::pickSuit(){
  /*for (int i = 0; i < Player::m_numCards; i++){
    //unsigned int countH = 0;
    //unsigned int countC = 0;
    //unsigned int countD = 0;
    //unsigned int countS = 0;
    //unsigned int countI = 0;
    cout << i << endl;
    }*/
  return Card::Clubs;
}


Card *CrunoPlayer::playOneCard(bool &lastCard, bool &oneCardLeft){
  // fixed this returning null up here
  int c = 0;// conflicting error here?
  Card *cptr;// (may need this later )->*temp;(fixed semicolon error

  // find first card that is playable

  //c = 0 ;        // index into array of Card pointers
  cptr = NULL;  // haven't found a playable card yet

  while( 1 ) {
    if (c >= m_numCards) break ;   // hit end of array

    if (m_cards[c]->playable(m_game)){ // found playable card

      cptr = m_cards[c] ;  // remember the card

      // To remove the card we will play from the hand,
      // we replace it with the last card in the array.
      // This changes the order of the cards, but
      // order doesn't matter here.

      m_numCards--;                       // one less card
      m_cards[c] = m_cards[m_numCards] ;   // replace with last card
      m_cards[m_numCards] = NULL ;         // just to be safe

      if (m_numCards == 1) oneCardLeft = true ;  // say "Uno"?
      if (m_numCards == 0) lastCard = true ;     // did we win?
      break ;
    }

    c++;    // no pun intended
  }

  return cptr ;
}

void CrunoPlayer::takeCard(Card *cptr){
  m_cards[m_numCards] = cptr ;
  m_numCards++;

  // sanity check
  //
  if (m_numCards == m_maxCards) {
    cerr << "Something is wrong in Player::takeCard !!!\n" ;
    exit(1) ;
  }
}

void CrunoPlayer::showCardToPlayer(const Card *cptr, unsigned int player, bool oneCardLeft ) {

  // "dumb" player ignores this info

  return ;
}
