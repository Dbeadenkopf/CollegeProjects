#include <cstring>
#include <iostream>
#include "board.h"
using namespace std;
Board::Board(){
  amount = 0;
  piece = 'O';
}
Board::Board(char takePiece, int UseAmount){
  piece = takePiece;
  amount = UseAmount;
} 
void Board::setPice(int aM){
  amount = aM;
}
int Board::getAmount(){
  return amount;
}
