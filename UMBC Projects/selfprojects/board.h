#ifndef _BOARD_H_
#define _BOARD_H_

class Board
{
 public:
  Board();
  Board(char takePiece);
  void setPiece(int aM);
  int getAmount();
 private:
  char piece;
  int amount;
}


#endif
