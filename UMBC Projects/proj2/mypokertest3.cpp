srand (time(NULL));// random number change
unsigned int n_compCard1,n_compCard2,n_compCard3,n_compCard4,n_compCard5,n_compCard6,n_compCard7,n_compCard8,n_com\
  pCard9,n_compCard10;
n_compCard1 = rand() % 14 + 2;
n_compCard2 = rand() % 14 + 2;
n_compCard3 = rand() % 14 + 2;
n_compCard4 = rand() % 14 + 2;
n_compCard5 = rand() % 14 + 2;
n_compCard6 = rand() % 14 + 2;
n_compCard7 = rand() % 14 + 2;
n_compCard8 = rand() % 14 + 2;
n_compCard9 = rand() % 14 + 2;
n_compCard10 = rand() % 14 + 2;
// do I need any of this?
Card n_obj1, n_obj2, n_obj3, n_obj4, n_obj5, n_objone, n_objtwo, n_objthree, n_objfour,n_objfive;
char n_choice, n_choice2;
cout << "Flip hand?(y/n): ";
cin >> n_choice;
cout << "Here " << endl;
int c = 0;
if (n_choice == 'y'){
  Card::cSuit randSuit1, randSuit2, randSuit3, randSuit4, randSuit5;
  randSuit1 = (Card::cSuit) ( rand() % 4 + 1 );
  randSuit2 = (Card::cSuit) ( rand() % 4 + 1 );
  randSuit3 = (Card::cSuit) ( rand() % 4 + 1 );
  randSuit4 = (Card::cSuit) ( rand() % 4 + 1 );
  randSuit5 = (Card::cSuit) ( rand() % 4 + 1 );

  obj1 = Card(randSuit1, n_compCard1);// need to randomise suit as well
  obj2 = Card(randSuit2, n_compCard2);
  obj3 = Card(randSuit3, n_compCard3);
  obj4 = Card(randSuit4, n_compCard4);// possibley short circuit evaluates
  obj5 = Card(randSuit5, n_compCard5);
  PokerHand hand, handofCards(n_obj1,n_obj2, n_obj3, n_obj4, n_obj5);
  handofCards.printRank();
  handofCards.printCards();
  char oppChoice;
  cout << "          " << "Computer wager: " << "\n";// ****stuff was done here**

  compCard1 = rand() % 10000 + 1;
  Wager compObj2;
  compObj2.setAmount(n_compCard1);
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
    cin >> n_choice2;
  }
 }
 else{
   // is this where the instance stops?
   exit(1);
 }
c++;

if (n_choice2 == 'n'){
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

