#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstring>
#include <map>
#include <stdlib.h>
#include "PinHit.h"
#include "Heap.h"
#include "MinValueHeap.h"
#include "MaxValueHeap.h"

// global variable for type of heap
std::string heapType = "--max"; // aparently this has to be flipped 
// throughout the program

//forward declare so I can define it below main
void printGreeting();



// printGreetin protoType of the function that will read the pin dump
// into a vector of Pin Hits. (totalHits) is an out Varible
// that I will set in the method, tallying the total number of lines
// = (pins) in the file, the function will return the final 
// count of the total hits that the vector contains
std::vector<PinHit> ReadPins(char* fileName, int* totalHits);


// The prototype of the function that takes
// the vector full of PinHits and the total
// size of the heap and the type of heap (--min or -- max)
// the function overall will return a pointer
// to the heap I dynamically created
template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots);



// provided , function that will be doing the most work of the project
// the function will take a min or max heap and the vector of pins that 
// I read in from the file. It will then randomly pick a pin from that
// vector and use my heap to try to guess what the pin is. Upon successufully
// guessing what the pin is, a count of succesful hacks is returned
// Try calling this function and comparing the results iof using a min
// heap vs a max heap
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits);


int main(int argc, char* argv[]){
  char* fileName;
  const int s = 10000;
  Heap<PinHit, 10000> *pointer;
  vector<PinHit> pins;
  int* totalH;
  //int totalH2 = 0;
  //int useHack;
  fileName = argv[1]; // filename contains the first argument
  heapType = argv[2]; // heap type contains the second
  totalH = new int(0); // initalizing total hit to zero
  pins = ReadPins(fileName,totalH);
  pointer = BuildHeap<PinHit, 10000>(pins, s);
  //  useHack = Hack(pointer, pins, totalH2); uncommenting this causes errors
  printGreeting();
  
  return EXIT_SUCCESS;
}


// prints your name and section
void printGreeting(){
  std::cout << "David Beadenkopf, Section Chang 10:00am" << std::endl;
}

// implement these two functions
std::vector<PinHit> ReadPins(char* fileName, int* totalHits)
{
  

  std::vector<PinHit> getdataDump(10000); // gives size of 10000
  std::fstream readFile;
  string pins;
  int notstringPins;
  // you may need to now usec pinhits?
  readFile.open(fileName);
  while(true){
    readFile >> pins;
    notstringPins = atoi(pins.c_str());
    getdataDump.at(notstringPins).IncrementHits(); // looking at each pinhit that matches and incrementing hits if there are matches
    // the pins in our vector
    (*totalHits )++; // dereference then increment total hits
    if(readFile.eof()){ // never gets to end of file
      break;
    }
  }
  readFile.close();
  return getdataDump;
}

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots){
  Heap<T, m_size>* ptr;
  if (heapType == "--max"){
    ptr = new MaxValueHeap<T, m_size>(); // make default max heap
  }
  else{
    ptr = new MinValueHeap<T, m_size>(); // make default min heap
  }
  for (unsigned int i = 0; i < PinHits.size(); i++){
    if (PinHits[i].GetValue() > 0){
      ptr->Insert(PinHits[i]); // insert pinHit at this ith index
    }
  }
  return ptr;
}

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits){

  int UPPER_BOUND = totalHits; // used for failsafes

  /*
   * His fictional bank with fictional cards and 
   * "normal pins" will allow you to incorrectly attempt 
   * to access his card 3 times per hour. You have from 
   * the start of the assignment to the end to hack as 
   * many accounts as possible (14 days * 24 hr/day * 3 
   * attempts/hr = 1008 attempts per card)
   */
  int MAX_ATTEMPTS = 1008; // maximum amount of attempts per card

  int hackAttemptsLeft = MAX_ATTEMPTS; 
  int successfulHacks = 0; // will count the succesfull hacks that have 
  // been done

  srand (time(NULL)); // seeds our random generator with the current time  
  int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits
  //randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
  int curHits = 0; // our variable for crawling
  int randomIndex = -1; // the index where our new random pinhit lives
  int newHits = 0; // number of hits in new "random" pin
  int failSafe = 0; // always good to have one of these in what could be an infinite loop

  /* 
   * Linearly searches through PinHits until
   * we've accrued enough hits to reach our random hits
   * which will then determine the next pin to try to hack.
   * We use newHits to make sure we don't pick a random pin
   * that's not in our heap. 
   */
  PinHit curPinHit;
  while (newHits == 0 && failSafe < UPPER_BOUND) {

    for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++){
      curHits += PinHits[i].GetValue();
      randomIndex = i;
    }
    // should have found the random pin by now
    curPinHit = PinHits[randomIndex];
    newHits = curPinHit.GetValue(); // make sure it's actually in our heap
    std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
    failSafe++;
  }

  // let's make a copy of the heap so we don't modify the original.
  Heap<T, m_size>* heapCopy; // the copy contructor is vital here?

  if (heapType == "--min"){
    heapCopy = new MinValueHeap<T, m_size>(*heap);
  } else if (heapType == "--max"){
    heapCopy = new MaxValueHeap<T, m_size>(*heap);
  } else {
    // invoking the copy constructor here
    heapCopy = new Heap<T, m_size>(*heap);
  }

  failSafe = 0;

  PinHit defaultPin;

  // exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
  int MAX_NUM_HACKS = 10000;

  while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS){

    // grabs our root
    PinHit topOfHeap = heapCopy->Remove();// equals equals operater get invoked here
    if (topOfHeap == defaultPin)
      break;

    std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

    if (hackAttemptsLeft == 1)
      std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

    hackAttemptsLeft--;

    // account was hacked!
    if (topOfHeap == curPinHit) {
      std::cout << "We got them!" << std::endl;
      successfulHacks++;

      // reset our heap
      if (heapType == "--min") {
	heapCopy = new MinValueHeap<T, m_size>(*heap);// will take in a heap
      } else if (heapType == "--max") {
	heapCopy = new MaxValueHeap<T, m_size>(*heap);
      } else {
	heapCopy = new Heap<T, m_size>(*heap);
	
      }
      hackAttemptsLeft = MAX_ATTEMPTS;
      randomNumHits = rand() % totalHits;
      curHits = 0;
      randomIndex = -1;
      newHits = 0;
      failSafe = 0;
      while (newHits == 0 && failSafe < UPPER_BOUND) {
	
	for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
	  curHits += PinHits[i].GetValue();
	  randomIndex = i;
	}
	// should have found the random pin by now
	curPinHit = PinHits[randomIndex];
	newHits = curPinHit.GetValue(); // make sure it's actually in our heap
	std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
	failSafe++;
      }

      std::cout << "Valid Random Pin: " << curPinHit.GetKey() << " found!" << std::endl;
    }
  }

  return successfulHacks;

}
