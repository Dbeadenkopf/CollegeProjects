// The header file of the implementation
// of Pin Hit which will be a class that simulates
// an instance of a pin number and hits based off there
// key value pairs where the key is the pin number 
// and the value is the number of times that pin number
// was seen in the dataset aka(maybe-->pinhit). This class should
// check that pin numbers coming in are between 0000 and 9999


#ifndef PINHIT_H_
#define PINHIT_H_

class PinHit 
{

 public:
  // The default constructor, which will
  // initilize a PinHit with default values for PIN and
  // frequency
  PinHit();

  // The constructor that will initialize
  // a PinHit with the PIN and the
  // number of hits (occurrences) it has
  // ex. (9889, 5)= (PIN, HITS)
  PinHit(int key, int value);

  // prototype of the member function that 
  // will set the key which is the pin number
  // that is passed in
  void SetKey(int pin);

  // returns the pin number, used as a key
  // in this key value pair
  int GetKey() const;
  
  // The getter prototype that returns
  // the number of hits, used as a value in
  // this key value pair
  int GetValue() const;


  // The prototype for the function
  // that increments the number of hits that
  // this pin has encountered
  // basically acts as the counter
  // to count the amount of hits this
  // single pin has took
  void IncrementHits();

  // The prototype of the function that 
  // Compares the value(hits) of this PinHit.
  // returns 0 if they are the same, negative if this 
  // is less than other or positive if this is greater
  // than other. **THIS FUNCTION DOES NOT COMPARE PINS**
  int CompareTo(const PinHit& other) const;

  // this is the eqauls equals operator
  // prototype that will compare the key(pins)
  // against other for equality; meaning, 
  // if this pin is eqauivalent to other`s pin return
  // true, else return false. 
  // im assuming this is also being used as to look
  // for the same PIN in the data set
  bool operator==(const PinHit& other); // whats the significance of
  // having pins eqaul to each other

 protected:
  int m_pin; // private data member that will hold the key value(pin number)
  int  m_hits; // private data member that will hold the numbers of hits
  const static int checkNum = 9999;
  bool isInRange(int Pin); // function that returns true if
  // the pin value is in range 0000 to 9999, else return false
};

#endif /* PinHit_H_ */
