#include <iostream>
#include <cstring>
#include "pokerhand.h"
#include "card.h"
#include "wager.h"
#include "wallet.h"
#line 1 "ERROR!->"
#include "compWallet.h"
#include "wagerMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>// random number genterator

using namespace std;
/// ******** Also! we could allow the user to choose from the
/// ********* from the beginning if he/she would like to bet
/// ******** or play against the computer
/// ******** 
/// ***** idea, perhaps we can use the random number genertator for the 
// ******** computer to allow the computer to place its own amount 
// ********* 
// could possibley use random number generator to generate hand possibly 
int main(){
  //  Wager *temp;
  // could allow user to set the amount 
  // ----> unsigned int winCap = 1000;
  //unsigned int computer;
  //computerAi = rand() % 1000000000;
  
  static double amHolder;
  char symbolHold;
  int playersCount = 0;
  int compCount = 0;
  char wager;	    
  cout << " " << endl;
  cout << "     Welcome To" << endl;
  cout << "===================" << endl;
  cout << "|    $PoKer$      |" << endl;
  cout << "===================" << endl << "\n";
  //cout << "Wager amount?(y/n) ";// need to confine this rule so they only answer the qeustion
  //cin >> wager;
  //switch(wager){
  //case 'y':
    // MENU LOGIC SHOULD OVERIDE this switch logic
  Wager obj;
  int a;
  char s;
  Menu starting('y');
    
    
    // we would have to get rid of our set amount componant
  cout << starting << endl;
  cout << "Starting Pot: ";
  cin >> a;
    
    // should see the increase as they press i
    // need polymorphism here to make things easier most likely
    // basically need a componenat that will stop there amount they want
  cout << "set symbol: ";
  cin >> s;
   
  switch(a)
    {
    case 1:
      obj.setAmount(10);
      break;
    case 2:
      obj.setAmount(100);
      break;
    case 3:
      obj.setAmount(1000);
      break;
    }
    

    // problems here
  Menu newMenu;
  newMenu.setSymbol(s);
  newMenu.outPut(newMenu);
  // obj.setAmount(a);
  obj.getAmount();
  obj.setSymbol(s);
  symbolHold = obj.Symbol();
  obj.outPut();
  amHolder = obj.getAmount();

  
  //break;
  //}
  srand (time(NULL));// random number change
  unsigned int compCard1,compCard2,compCard3,compCard4,compCard5,compCard6,compCard7,compCard8,compCard9,compCard10;
  compCard1 = rand() % 14 + 1;
  compCard2 = rand() % 14 + 1;
  compCard3 = rand() % 14 + 1;
  compCard4 = rand() % 14 + 1;
  compCard5 = rand() % 14 + 1;
  compCard6 = rand() % 14 + 1;
  compCard7 = rand() % 14 + 1;
  compCard8 = rand() % 14 + 1;
  compCard9 = rand() % 14 + 1;
  compCard10 = rand() % 14 + 1;
 
  Card obj1, obj2, obj3, obj4, obj5, objone, objtwo, objthree, objfour, objfive;
  char choice;
  cout << "Flip hand?(y/n): ";
  cin >> choice;
  PokerHand *takeHand;
  if (choice == 'y'){
    // made varibles of type suit
    // to access the enumeration constant
    Card::cSuit randSuit1, randSuit2, randSuit3, randSuit4, randSuit5;
    // typecast to then allow for random number
    // generator to be in terms of the enumeration array
    randSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit5 = (Card::cSuit) ( rand() % 4 + 1 );
    obj1 = Card(randSuit1, compCard1);
    obj2 = Card(randSuit2, compCard2);
    obj3 = Card(randSuit3, compCard3);
    obj4 = Card(randSuit4, compCard4);
    obj5 = Card(randSuit5, compCard5);
    PokerHand hand, handofCards(obj1,obj2, obj3, obj4, obj5);
    takeHand = &handofCards;
    handofCards.printRank();
    handofCards.printCards();
    Menu start;
    Wager obj;
    int a;
    start.setSymbol(symbolHold);
    // *** THERE NEEDS TO BE A SET WAGER AMOUNT BEFORE THE GAME STARTS?
    cout << start << endl;
    cout << "select choice 1-5: ";
    cin >> a;
    switch(a)
      {
      case 1:
        amHolder = amHolder + 10;
	obj.setAmount(amHolder);
	obj.outPut();
	break;
      case 2:
        amHolder = amHolder + 100;
	obj.setAmount(amHolder);
	obj.outPut();
        break;
      case 3:
        amHolder = amHolder + 1000; // may need to use getter
	obj.setAmount(amHolder);
	obj.outPut();
        break;
      case 4:
	// logic needs to occur after this case
        cout << "Checking...." << endl;
        cout << "\n" << endl;
        break;
      case 5:
	cout << "Folding...." << endl;
	cout << "\n" << endl;
	cout << "         " << "                  ---------- " << endl;
	cout << "           " << "                Comp Wins!" << endl;
	cout << "                " <<     "           ---------- " << endl;
        compWallet obj(amHolder);
        obj.outPut(obj);
	char choice2;
	cout << "Play again?(y/n): ";
	cin >> choice2;
	int i = 0;
	cout << i << endl;
	while (choice2!= 'n'){
	  cout << " " << endl;
	  /*cout << "     Welcome To" << endl;
	    cout << "===================" << endl;
	    cout << "|$    <3PoKer<3  $  |" << endl;
	    cout << "===================" << endl << "\n";*/
	  cout << "Wager amount?(y/n) ";// take turns with the computer wagering amounts
	  cin >> wager;                 // of money
	  switch(wager){
	  case 'y':
	    
	    Wager obj;
	    // char s;
	    Menu starting(wager);
	    cout << starting << endl;
	    cout << "Starting Amount: ";
	    cin >> a;

	    // should see the increase as they press i
	    // need polymorphism here to make things easier most likely
	    // basically need a componenat that will stop there amount they want
	    // cout << "set symbol: ";
	    //cin >> s;

	    switch(a)
	      {
	      case 1:
		obj.setAmount(10);
		break;
	      case 2:
		obj.setAmount(100);
		break;
	      case 3:
		obj.setAmount(1000);
		break;
	      }
	    // removed extra brase
	    // to see what is all included
	    // in above while loop 
	    Menu newMenu;
	    newMenu.setSymbol(symbolHold);
	    newMenu.outPut(newMenu);
	    // obj.setAmount(a);
	    obj.getAmount();
	    obj.setSymbol(symbolHold);
	    symbolHold = obj.Symbol();
	    obj.outPut();
	    amHolder = obj.getAmount();
	   
	    break;
	  }
	
	  srand (time(NULL));// random number change
	  unsigned int compCard1,compCard2,compCard3,compCard4,compCard5,compCard6,compCard7,compCard8,compCard9,compCard10;
	  compCard1 = rand() % 14 + 2;
	  compCard2 = rand() % 14 + 2;
	  compCard3 = rand() % 14 + 2;
	  compCard4 = rand() % 14 + 2;
	  compCard5 = rand() % 14 + 2;
	  compCard6 = rand() % 14 + 2;
	  compCard7 = rand() % 14 + 2;
	  compCard8 = rand() % 14 + 2;
	  compCard9 = rand() % 14 + 2;
	  compCard10 = rand() % 14 + 2;

	  Card obj1, obj2, obj3, obj4, obj5, objone, objtwo, objthree, objfour, objfive;
	  char choice;
	  cout << "Flip hand?(y/n): ";
	  cin >> choice;
	  if (choice == 'y'){
	    
	    Card::cSuit randSuit1, randSuit2, randSuit3, randSuit4, randSuit5;
	    randSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
	    randSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
	    randSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
	    randSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
	    randSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

	    obj1 = Card(randSuit1, compCard1);// need to randomise suit as well
	    obj2 = Card(randSuit2, compCard2);
	    obj3 = Card(randSuit3, compCard3);
	    obj4 = Card(randSuit4, compCard4);// possibley short circuit evaluates
	    obj5 = Card(randSuit5, compCard5);
	    PokerHand hand, handofCards(obj1,obj2, obj3, obj4, obj5);
	    handofCards.printRank();
	    handofCards.printCards();
	    // Menu logic occurs here
	    cout << start << endl;
	    cout << "select choice 1-5: ";
	    cin >> a;
	    switch(a) // maybe we can change this value
	      {
	      case 1:
		amHolder = amHolder + 10;
		obj.setAmount(amHolder);
		obj.outPut(obj);
		break;
	      case 2:
		amHolder = amHolder + 100;
		obj.setAmount(amHolder);
		obj.outPut(obj);
		break;
	      case 3:
		amHolder = amHolder + 1000; // may need to use getter
		obj.setAmount(amHolder);
		obj.outPut(obj);
		break;
	      case 4:
		// logic needs to occur after this case
		cout << "Checking...." << endl;
		cout << "\n" << endl;
		break;
	      case 5:
		cout << "Folding...." << endl;
		cout << "\n" << endl;
		cout << "         " << "                  ---------- " << endl;
		cout << "           " << "                Comp Wins!" << endl;
		cout << "                " <<     "           ---------- " << endl;
		// giving notice to ERROR here
		// ###
		compWallet obj(amHolder);
		obj.outPut(obj);
		char choice2;
		cout << "Play again?(y/n): ";
		cin >> choice2;
		int i = 0;
		while (choice2!= 'n'){
		  cout << " " << endl;
		  cout << "Wager amount?(y/n) ";// take turns with the computer wagering amounts
		  cin >> wager;                 // of money
		  switch(wager){
		  case 'y':
		    
		    Wager obj;
		    // char s;
		    Menu starting(wager);
		    cout << starting << endl;
		    cout << "Starting Amount: ";
		    cin >> a;
		    
		    // should see the increase as they press i
		    // need polymorphism here to make things easier most likely
		    // basically need a componenat that will stop there amount they want
		    // cout << "set symbol: ";
		    //cin >> s;
		    
		    switch(a)
		      {
		      case 1:
			obj.setAmount(10);
			break;
		      case 2:
			obj.setAmount(100);
			break;
		      case 3:
			obj.setAmount(1000);
			break;
		      }
		    // removed extra brase
		    // to see what is all included
		    // in above while loop
		    Menu newMenu;
		    newMenu.setSymbol(symbolHold);
		    newMenu.outPut(newMenu);
		    // obj.setAmount(a);
		    obj.getAmount();
		    obj.setSymbol(symbolHold);
		    symbolHold = obj.Symbol();
		    obj.outPut();
		    amHolder = obj.getAmount();

		    break;
		  }
		}
	      	      
	      
	      	  
		char oppChoice;
		cout << "          " << "Computer wager: " << "\n";// ****stuff was done here**

		compCard1 = rand() % 10000 + 1;
		Wager compObj2;
		compObj2.setAmount(compCard1);
		compObj2.outPut();
		cout << "Flip Comp Hand?(y/n): ";
		cin >> oppChoice;
		if (oppChoice == 'y'){
		  Card::cSuit comprandSuit1, comprandSuit2, comprandSuit3, comprandSuit4, comprandSuit5;
		  comprandSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
		  comprandSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
		  comprandSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
		  comprandSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
		  comprandSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

		  objone = Card(comprandSuit1, compCard6);
		  objtwo = Card(comprandSuit2, compCard7);
		  objthree = Card(comprandSuit3, compCard8);
		  objfour = Card(comprandSuit4, compCard9);// possibley short circuit evaluates
		  objfive = Card(comprandSuit5, compCard10);
		  PokerHand hand, oppHand(objone, objtwo, objthree, objfour, objfive);
		  oppHand.printRank();
		  oppHand.printCards();
		  cout << "Here need to add same format" << endl;
		  if (oppHand.cmp(handofCards) > 0){// test comparison
		    cout << "         " << "                  ---------- " << endl;
		    cout << "            " << "                You Win!" << endl;
		    cout << "                " <<     "           ---------- " << endl;
		    
		    playersCount = playersCount + amHolder + compCard1;
		    Wallet obj(playersCount);
		    obj.outPut(obj);
		    // wallet + amount wagered
		  }
		  if (oppHand.cmp(handofCards) < 0){// test comparison
		    cout << "         " << "                  ---------- " << endl;
		    cout << "           " << "                Comp Wins!" << endl;
		    cout << "                " <<     "           ---------- " << endl;
		    compCount = compCount + amHolder + compCard1;
		    compWallet obj(compCount);
		    obj.outPut(obj);
		  }
		  if (oppHand.cmp(handofCards) == 0){// test tie
		    cout << "  " << endl;
		    cout << "We Tie" << endl;
		    cout << " " << endl;
		  }
		  cout << "Play again?(y/n): ";
		  cin >> choice2;
		}
		// switch bracket placed here
		  else{
	      // is this where the instance stops?
		    exit(1);
		  }
		  i++;
		}
	  }
	}
	if (choice2 == 'n'){
	  cout << "Computer Earnings " << "Player Earnings " << endl << "\n";
	  cout << "       " << symbolHold << compCount << "            " << symbolHold << playersCount << endl;
	  if (compCount > playersCount){
	    cout << "From the looks of it" << endl;
	    cout << "The computer wins!!" << endl;
	  }
	  if (compCount == playersCount){
	    cout << "We have a tie" << endl;
	    // the tie breaker
	    // can be to play a round of poker
	    // if there is a tie breaker
	  }
	  // this is not acting correctly here
	  if (compCount < playersCount){
	    cout << "From the looks of it " << endl;
	    cout << " " << endl;
	    cout << "The player wins!! " << endl;
	  }
	  exit(1);
	}
	
      
  	
      
  

  // testing occuring here 

  


  char oppChoice;
   
  compCard1 = rand() % 10000 + 1;
  Wager compObj;
  compObj.setAmount(compCard1);
  cout << "          " << "Computer wager: " << "\n";// ****stuff was done here**  
  compObj.outPut();
  cout << "Flip Comp Hand?(y/n): ";
  cin >> oppChoice;
  if (oppChoice == 'y'){
    Card::cSuit randSuit1, randSuit2, randSuit3, randSuit4, randSuit5;
    randSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
    randSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

    objone = Card(randSuit1, compCard6);
    objtwo = Card(randSuit2, compCard7);
    objthree = Card(randSuit3, compCard8);
    objfour = Card(randSuit4, compCard9);// possibley short circuit evaluates
    objfive = Card(randSuit5, compCard10);
    PokerHand hand, oppHand(objone, objtwo, objthree, objfour, objfive);
    oppHand.printRank();
    oppHand.printCards();
    if (oppHand.cmp(*takeHand) > 0){// test comparison
	cout << "         " << "                  ---------- " << endl;
        cout << "            " << "                You Win!" << endl;
        cout << "                " <<     "           ---------- " << endl;
	// here is were the wallet class comes int
	// perhaps dynamic binding could occur here
	playersCount = playersCount + amHolder + compCard1;
	Wallet obj(playersCount);
	obj.outPut(obj);
	//Wager temp;
	//temp.returnCounter();
	//temp++;
	// here we need to add to the amount they currently wagered by incrementing he counter and multiplying the counter to the current amount or adding the counter
      }
      if (oppHand.cmp(*takeHand) < 0){// test comparison
	cout << "         " << "                  ---------- " << endl;
	cout << "           " << "                Comp Wins!" << endl;
	cout << "                " <<     "           ---------- " << endl;
	compCount = compCount + amHolder + compCard1;
	compWallet obj(compCount);
        obj.outPut(obj);
      }
      if (oppHand.cmp(*takeHand) == 0){// test tie
	cout << " " << endl;
	cout << "we tie" << endl;
      }
      //i++;
      if (choice == 'n'){
	exit(1);
      }
    }
    if (choice == 'n'){
      exit(1);
    }


  PokerHand hand, handofCards(obj1,obj2, obj3, obj4, obj5), oppHand(objone, objtwo, objthree, objfour, objfive);
  obj1 = Card(Card::Hearts, compCard1);// need to randomise suit as well
  obj2 = Card(Card::Hearts, compCard2);
  obj3 = Card(Card::Spades, compCard3);
  obj4 = Card(Card::Clubs, compCard4);// possibley short circuit evaluates
  obj5 = Card(Card::Spades, compCard5);
  
  objone = Card(Card::Clubs, compCard6);
  objtwo = Card(Card::Clubs, compCard7);
  objthree = Card(Card::Diamonds, compCard8);
  objfour = Card(Card::Clubs, compCard9);// possibley short circuit evaluates
  objfive = Card(Card::Clubs, compCard10);
  /*handofCards.printRank();
  handofCards.printCards();
  oppHand.printRank();
  oppHand.printCards();*/
  /*if (handofCards.isRoyalFlush() == true){
    cout << "we have a royal flush" << endl;// could put result here for testing thenput it back into functio
  }
  if (handofCards.isTwoPair() == true){// test two pair
    cout << "we have a two pair" << endl;
  }
  if (handofCards.isStraightFlush() == true){// test straight
    cout << "we have a straight flush" << endl;
  }
  if(handofCards.isStraight() == true){// test is straight
    cout << "we have found a straight" << endl;
  }
  if(handofCards.isFlush() == true){// test is flush
    cout << "we have a flush" << endl;
  }
  if(handofCards.isHighCard() == true){// test is high card
    cout << "Only by high card" << endl << "\n";
  }
  if(handofCards.isFourOfAKind() == true){// test four of a kind
    cout << "testing four of a kind" << endl;
  }
  if(handofCards.isOnePair() == true){// test one pair
    cout << "testing for one pair" << endl;
  }
  if(handofCards.isFullHouse() == true){// test full house
    cout << "testing full house" << endl;
  }xsxc
  if(handofCards.isThreeOfAKind() == true){// test three of a kind
    cout << "testing for three of a kind" << endl;
    }*/
  /*if (oppHand.cmp(handofCards) > 0){// test comparison
    cout << "Your hand beats mine" << endl;
  }
  if (oppHand.cmp(handofCards) < 0){// test comparison
    cout << "My hand beats yours" << endl;
  }
  if (oppHand.cmp(handofCards) == 0){// test tie
    cout << "we tie" << endl;
    }*/
  char n_choice2;
  cout << "Play again?(y/n): ";
  cin >> n_choice2;
  int p = 0;
  cout << p << endl;
  while (n_choice2!= 'n'){
    cout << " " << endl;
    /*cout << "     Welcome To" << endl;
    cout << "===================" << endl;
    cout << "|$    <3PoKer<3  $  |" << endl;
    cout << "===================" << endl << "\n";*/
    cout << "Wager amount?(y/n) ";// take turns with the computer wagering amounts
    cin >> wager;                 // of money
    switch(wager){
    case 'y':
      //perhaps here is were the game can continue
      Wager obj;
      double a;
      //char s;
      cout << "Set wager amount: ";
      cin >> a;
      //cout << "set symbol: ";
      //cin >> s;
      obj.setAmount(a);
      amHolder = obj.getAmount();
      obj.setSymbol(symbolHold);
      obj.Symbol();
      obj.outPut();
      break;
    }
    srand (time(NULL));// random number change
    unsigned int compCard1,compCard2,compCard3,compCard4,compCard5,compCard6,compCard7,compCard8,compCard9,compCard10;
    compCard1 = rand() % 14 + 2;
    compCard2 = rand() % 14 + 2;
    compCard3 = rand() % 14 + 2;
    compCard4 = rand() % 14 + 2;
    compCard5 = rand() % 14 + 2;
    compCard6 = rand() % 14 + 2;
    compCard7 = rand() % 14 + 2;
    compCard8 = rand() % 14 + 2;
    compCard9 = rand() % 14 + 2;
    compCard10 = rand() % 14 + 2;
 
    Card obj1, obj2, obj3, obj4, obj5, objone, objtwo, objthree, objfour, objfive;
    char choice;
    cout << "Flip hand?(y/n): ";
    cin >> choice;
    if (choice == 'y'){
      Card::cSuit randSuit1, randSuit2, randSuit3, randSuit4, randSuit5;
      randSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
      randSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
      randSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
      randSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
      randSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

      obj1 = Card(randSuit1, compCard1);// need to randomise suit as well
      obj2 = Card(randSuit2, compCard2);
      obj3 = Card(randSuit3, compCard3);
      obj4 = Card(randSuit4, compCard4);// possibley short circuit evaluates
      obj5 = Card(randSuit5, compCard5);
      PokerHand hand, handofCards(obj1,obj2, obj3, obj4, obj5);
      handofCards.printRank();
      handofCards.printCards();
      char oppChoice;
      cout << "          " << "Computer wager: " << "\n";// ****stuff was done here**
     
      compCard1 = rand() % 10000 + 1;
      Wager compObj2;
      compObj2.setAmount(compCard1);
      compObj2.outPut();
      cout << "Flip Comp Hand?(y/n): ";
      cin >> oppChoice;
      if (oppChoice == 'y'){
	Card::cSuit comprandSuit1, comprandSuit2, comprandSuit3, comprandSuit4, comprandSuit5;
	comprandSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
	comprandSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
	comprandSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
	comprandSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
	comprandSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

	objone = Card(comprandSuit1, compCard6);
	objtwo = Card(comprandSuit2, compCard7);
	objthree = Card(comprandSuit3, compCard8);
	objfour = Card(comprandSuit4, compCard9);// possibley short circuit evaluates
	objfive = Card(comprandSuit5, compCard10);
	PokerHand hand, oppHand(objone, objtwo, objthree, objfour, objfive);
	oppHand.printRank();
	oppHand.printCards();
	cout << "Here need to add same format" << endl;
	if (oppHand.cmp(handofCards) > 0){// test comparison
	  cout << "         " << "                  ---------- " << endl;
	  cout << "            " << "                You Win!" << endl;
	  cout << "                " <<     "           ---------- " << endl;

	  playersCount = playersCount + amHolder + compCard1;
	  Wallet obj(playersCount);
	  obj.outPut(obj);
	  // wallet + amount wagered
	}
	if (oppHand.cmp(handofCards) < 0){// test comparison
	  cout << "         " << "                  ---------- " << endl;
	  cout << "           " << "                Comp Wins!" << endl;
	  cout << "                " <<     "           ---------- " << endl;
	  compCount = compCount + amHolder + compCard1;
	  compWallet obj(compCount);
	  obj.outPut(obj);
	}
	if (oppHand.cmp(handofCards) == 0){// test tie
	  cout << "  " << endl;
	  cout << "We Tie" << endl;
	  cout << " " << endl;
	}
	cout << "Play again?(y/n): ";
	cin >> choice2;
      }
    }
    else{
      // is this where the instance stops?
      exit(1);
    }
    i++;
  }
  if (choice2 == 'n'){
    cout << "Computer Earnings " << "Player Earnings " << endl << "\n";
    cout << "       " << symbolHold << compCount << "            " << symbolHold << playersCount << endl;
    if (compCount > playersCount){
      cout << "From the looks of it" << endl;
      cout << "The computer wins!!" << endl;
    }
    if (compCount == playersCount){
      cout << "We have a tie" << endl;
      // the tie breaker 
      // can be to play a round of poker
      // if there is a tie breaker
    }
    // this is not acting correctly here
    if (compCount < playersCount){
      cout << "From the looks of it " << endl;
      cout << " " << endl;
      cout << "The player wins!! " << endl;
    }
    exit(1);
  }
      }
  }
   
      

  
  return 0;
}
