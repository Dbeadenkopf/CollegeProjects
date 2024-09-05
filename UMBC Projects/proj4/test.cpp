#include <cstring>
#include <iostream>
#include "game.h"
#include "player.h"
#include "card.h"
#include "Cruno8.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"
using namespace std;
//#include "CrunoPlayer.h"
int main(){
  //// -> this triggers pick suit Cruno8 obj(4,8);
  CrunoGame obj3;
  // when intilizzing 4, one will need 4 players as well and vice versa
  obj3.initialize(4);
  //Cruno8 obj(0,3);
  /*Card *obj2;
  obj2 = &obj; 
  if (obj2->getPoints() == 8){ 
    coeut << "We have a wild 8 card" << endl;
    cout << "and wee have a 4 level suit" << endl;
    }*/
  int n = obj3.getNumCards();
  Player *pptr1 = new Player(&obj3,n);
  Player *pptr2 = new Player(&obj3,n);
  Player *pptr3 = new Player(&obj3,n);
  Player *pptr4 = new Player(&obj3,n);
  /*delete pptr1;
  delete pptr2;
  delete pptr3;
  delete pptr4;*/
  /*CrunoPlayer *pptr1 = new CrunoPlayer(&obj3,n);
  CrunoPlayer *pptr2 = new CrunoPlayer(&obj3,n);
  CrunoPlayer *pptr3 = new CrunoPlayer(&obj3,n);
  CrunoPlayer *pptr4 = new CrunoPlayer(&obj3,n);
  delete pptr1;
  delete pptr2;
  delete pptr3;
  delete pptr4;*/
  
  obj3.addPlayer(pptr1);
  obj3.addPlayer(pptr2);
  obj3.addPlayer(pptr3);
  obj3.addPlayer(pptr4);

  obj3.startGame(3810743) ;
  //obj3.startGame(8132987);
  return 0;
}
		    
