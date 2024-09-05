#ifndef HINT_H
#define HINT_H
using namespace std;
class GameHint{
  // this header file is the prototype to add hints throught the game
  // the purpose of this header file is to hold funtions portaininf to
  // enabling hints that will help the player throught the game
  // the player can turn them off or on , and enable throught the game at any time
  // the game starts with very simple duirections, the idea
  // is to bring logic that can inform the player further/
  // throught the game
 public:
  GameHint();
  GameHint(char giveMe);
  bool returnOn();







 private:
  bool turnOn;
  bool turnOff;
  char hint;
  
}

#endif
