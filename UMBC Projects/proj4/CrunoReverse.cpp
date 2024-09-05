#include <iostream>
#include <cstring>
#include "CrunoReverse.h"
#include "game.h"
#include "player.h"
using namespace std;
CrunoRev::CrunoRev(){
  // empty body
}
void CrunoRev::playGame(){
  bool lastCard, oneCardLeft;
  unsigned int p, q;
  Card *cptr ;


  // Each iteration of this while loop is
  // a player taking a turn
  //
  while (not m_over) {

    lastCard = false ;
    oneCardLeft = false ;

    // debugging output so we can see
    //
    cout << endl ;
    for (unsigned int i=0 ; i < m_numPlayers ; i++) {
      cout << "----------------------------\n" ;
      cout << "Player " << i << " has:\n" ;
      m_players[i]->dump() ;
    }
    cout << "----------------------------\n\n" ;


    p = currentPlayer() ;  // virtual

    cptr = m_players[p]->playOneCard(lastCard, oneCardLeft) ;

    // keep drawing cards until a card is played.
    // Note: a player can choose not to play a card that is playable.
    // After drawing a card, the player can play any card in his/her
    // hand. This is not necessarily the card that was just drawn.
    //
    while (cptr == NULL){
      cptr = dealOneCard();// heres THE DEAL ONE CARD
      if (cptr == NULL) break;
      cout << "Player " << p << " draws a card: " << cptr->toString() << endl ;
      m_players[p]->takeCard(cptr) ;
      cptr = m_players[p]->playOneCard(lastCard, oneCardLeft) ;
    }


    // if a card was actually played...
    //
    //
    if (cptr != NULL) {

      cout << "Player " << p << " plays " << cptr->toString() << endl ;

      // Show each player what was played. (They can ignore the info.)
      // Also allow the card to interact with each player
      //
      q = playerAfter(p) ;  // virtual
      while (q != p) {
        m_players[q]->showCardToPlayer(cptr, p, oneCardLeft) ;
        cptr->showPlayerToCard(m_players[q]) ;
        q = playerAfter(q) ;  // virtual
      }


      // Now let the card do what it needs to do with the game.
      // (E.g. set the suit and points for others to follow.)
      //
      cptr->playCard(this, m_players[p]) ;


      // Card played goes into the discard pile.
      //
      m_discard[m_numDiscard] = cptr ;
      m_numDiscard++ ;
    }


    // Say "Uno!"
    if (oneCardLeft) {
      cout << "Player " << p << " has one card left!\n" ;
    }

    // Player went out?
    //
    if (lastCard) {
      cout << "Player " << p << " wins!\n" ;
      m_winner = p ;
      m_over = true ;
    } else {
      nextPlayer() ;  // virtual
    }
  }

  return ;
}



