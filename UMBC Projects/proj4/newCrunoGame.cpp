#include <iostream>
#include <cstring>
#include <cstdlib>
#include "game.h"
#include "newCrunoGame.h"
#include "CrunoPlayer.h"
#include "Cruno8.h"
#include "CrunoDraw2.h"
#include "CrunoSkip.h"
using namespace std;

static void ifNullCrash(void *ptr){
  if (ptr == NULL){
    cerr << "Could not allocate memory\n";
    exit(1);
  }
  return;
}

newCrunoGame::newCrunoGame(){
  //
}

void newCrunoGame::initialize(int numPlayers) {
  m_suit = 0;
  m_points = 0;
  m_currentPlayer = 0 ;

  // can't play by yourself
  //
  if (numPlayers < 2) {
    cerr << "Insufficient players\n" ;
    exit(1) ;
  }

  
  // not enough cards to make it fun for >10.
  //
  if (numPlayers > 10) {
    cerr << "Too many players\n" ;
    exit(1) ;
  }

  m_numPlayers = 0 ;  // no players added yet.

  // allocate space for max requested
  //

  m_maxPlayers = numPlayers ;
  m_players = new Player*[numPlayers] ;
  ifNullCrash(m_players) ;

  m_winner = m_maxPlayers + 1 ;  // not a real player

  // usually use just one deck
  int decks = 1 ;
  m_maxCards = 52 ;   // 52 cards in one deck

  if (numPlayers > 5) {

    decks = 2 ;
    m_maxCards = 104 ;   // 104 cards in two decks
  }

  // allocate space for the discard pile
  m_discard = new Card*[m_maxCards];
  ifNullCrash(m_discard);
  m_numDiscard = 0 ;  // nothing discarded yet

  // allocate space for the stock pile
  m_stock = new Card*[m_maxCards] ;
  ifNullCrash(m_stock);

  int i = 0;  // next available slot in m_stock[]

  for (int d = 0 ; d < decks ; d++) {  // # of decks

    // iterate over suits
    for (unsigned int s = Card::Clubs ; s <= Card::Spades ; s++) {

      // iterate over point values

      // iterate over point values
      for (unsigned int p = 2 ; p <= Card::Ace ; p++) {

        m_stock[i] = new Card(s,p) ;  // insert new card
	m_stock[i] = new Draw2(s,p);
        ifNullCrash(m_stock[i]) ;
        i++ ;
        if (p == 8){
          m_stock[i] = new Cruno8(s,8);
        }

      }
    }
  }
    // remember how many cards we added
    m_numStock = m_maxCards ;

    // Still haven't started (need to have players added)
    m_started = false ;
    m_over = false ;
  
}

unsigned int newCrunoGame::getNumCards(){
  return m_maxCards;
}

void newCrunoGame::addPlayer(Player *pptr){

  // sanity check
  //
  if (m_numPlayers == m_maxPlayers) {
    cerr << "Too many players added!\n" ;
    return ;
  }

  m_players[m_numPlayers] = pptr ;
  m_numPlayers++ ;
  return ;
}

unsigned int newCrunoGame::nextPlayer() {
  m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers ;
  return m_currentPlayer ;
}

unsigned int newCrunoGame::playerAfter(unsigned int thisPlayer) {
  return (thisPlayer + 1) % m_numPlayers ;
}

void newCrunoGame::startGame(unsigned int seed) {

  int j;

  // shuffle cards
  //
  //  
  cout << "Random seed = " << seed << endl;
  srand(seed) ;
  for(unsigned int i = 0 ; i < m_numStock ; i++) {
    Card *temp ;

    j = rand() % m_numStock ;
    temp = m_stock[i] ;
    m_stock[i] = m_stock[j] ;
    m_stock[j] = temp ;
  }

  // give players cards
  //
  dealCards() ;

  // Sanity check. Did we run out?
  //
  if (m_numStock < 1) {
    cerr << "Missing cards!\n" ; // possible factor this into the cheating impl\ementation of game, player stole a card
      exit(1) ;
  }


  // turn over one card in the stock pile
  // and make it the top of the discard pile
  //
  m_numStock-- ;
  m_discard[0] = m_stock[m_numStock] ;
  m_stock[m_numStock] = NULL ;
  m_numDiscard++;
  setSuit( m_discard[0]->getSuit() ) ;
  setPoints( m_discard[0]->getPoints() ) ;
  // changed all indexs of discard from 0 to 1
  cout << "First card: " << m_discard[0]->toString() << endl ;

  m_started = true ;
  playGame();  // main game l
  
  gameOver();
  
}


void newCrunoGame::playGame(){

  bool lastCard, oneCardLeft;
  unsigned int p, q ;
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

    
    p = currentPlayer();  // virtual

    cptr = m_players[p]->playOneCard(lastCard, oneCardLeft) ;
    // keep drawing cards until a card is played.
    // Note: a player can choose not to play a card that is playable.
    // After drawing a card, the player can play any card in his/her
    // hand. This is not necessarily the card that was just drawn.
    //
    while (cptr == NULL){
      cptr = dealOneCard();// heres THE DEAL ONE CARD
      if (cptr == NULL) {
	 // getting rid of break (break; (file game.cpp line 300) for comparison)
	cout << "Player " << p << " draws a card: " << cptr->toString() << endl ;
	m_players[p]->takeCard(cptr) ;
	cptr = m_players[p]->playOneCard(lastCard, oneCardLeft);
	break;
      }


    // if a card was actually played...
    //
      if (cptr!= NULL){

      cout << "Player " << p << " plays " << cptr->toString() << endl;

      // Show each player what was played. (They can ignore the info.)
      // Also allow the card to interact with each player
      //
      q = playerAfter(p);  // virtual
      while (q!= p){
        m_players[q]->showCardToPlayer(cptr, p, oneCardLeft);
        cptr->showPlayerToCard(m_players[q]);
        q = playerAfter(q);  // virtual
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
    //
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
  }
  

}


Card *newCrunoGame::dealOneCard(){
  Card *cptr;
  /*for(unsigned int i = 0 ; i < m_numDiscard-1 ; i++) {
    m_stock[i] = m_discard[i];
    m_discard[i] = NULL;
  }
  m_numStock = m_numDiscard-1;
  m_discard[0] = m_discard[m_numDiscard-1];
  m_discard[m_numDiscard-1] = NULL;*/

  

  // Sanity check
  //
  
  if (m_numStock < 1) {
    m_over = true ; // game is over
    return NULL ;
  }

  // Gimme!
  //
  m_numStock--;
  cptr = m_stock[m_numStock];
  m_stock[m_numStock] = NULL;
  if (m_numStock < 1){
    for(unsigned int i = 0 ; i <= m_numDiscard-1; i++){
      m_stock[i] = m_discard[i];
      m_discard[i] = NULL;
    }
    m_numStock = m_numDiscard-1;
    m_discard[0] = m_discard[m_numStock];// changed this from m_numDiscard to m_numStock
    m_discard[m_numStock] = NULL;
  }
  
  return cptr ;
}




