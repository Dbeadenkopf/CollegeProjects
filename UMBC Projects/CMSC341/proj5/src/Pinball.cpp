#include <iostream> 
#include <stdexcept> // include that allows for exceptions to
// be thrown

#include <string.h> // allows to use strdup() to copy strings
#include "Pinball.h"
#include <time.h> // allows for random number generator
#include <assert.h>

using namespace std;



Pinball::Pinball(int n){
  m_capacity = n;
  char* m_empty = NULL; 
  H = (char**) malloc(m_capacity*sizeof(char)); // allocating a new array of type char **
  //H = new char*[m_capacity];
  for (int i = 0; i < m_capacity;i++){
    H[i] = m_empty;
  }
  m_size = 0; // need to count the amount of items stored in array
  m_degree = 5;
  m_ejectLimit = 8;
  randomnessLvl = "Not so random";
  m_primarySlots = 0; //primaryslotCount(); // cna only be given from hashcode()
  m_totalEjects = 0;
  m_maxEjects = 0; 
  countEjects = 0;
}


Pinball::~Pinball(){
  for (int i = 0; i < m_capacity;i++){
    free(H[i]);
  }
}




void Pinball::insert(const char *str){
  srand(time(NULL));
  char *notfound; // this varible could use remove() function


  holdHashvalue = hashCode(strdup(str));
  m_primarySlots++;
  cout << m_primarySlots << endl;
  setPrimary(m_primarySlots);
  offset1 = holdHashvalue + (rand() % m_capacity); 
  offset2 = holdHashvalue + (rand() % m_capacity);
  offset3 = holdHashvalue + (rand() % m_capacity);
  offset4 = holdHashvalue + (rand() % m_capacity);
  if(offset1 == offset2){
    offset1 = holdHashvalue + (rand() % m_capacity);
  }
  else if(offset1 == offset3){
    offset1 = holdHashvalue + (rand() % m_capacity);
  }
  else if(offset1 == offset4){
    offset1 = holdHashvalue + (rand() % m_capacity);   // if statements account for giving an offset 
  }                                                    // their distinct values
  if (offset2 == offset1){
    offset2 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset2 == offset3){
    offset2 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset2 == offset4){
    offset2 = holdHashvalue + (rand() % m_capacity);
  }
  if (offset3 == offset1){
    offset3 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset3 == offset2){
    offset3 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset3 == offset4){
    offset3 = holdHashvalue + (rand() % m_capacity);
  }
  if (offset4 == offset1){
    offset4 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset4 == offset2){
    offset4 = holdHashvalue + (rand() % m_capacity);
  }
  else if (offset4 == offset3){
    offset4 = holdHashvalue + (rand() % m_capacity);
  }  
  // cout << "offset1 = " << offset1 << endl;
  //cout << "offset2 = " << offset2 << endl;
  //cout << "offset3 = " << offset3 << endl;
  //cout << "offset4 = " << offset4 << endl;
  H[holdHashvalue] = strdup(str); 
  cout << "holdHashvalue =  " << holdHashvalue << endl;
  for (int i = 0; i < m_capacity; i++){
    if(H[holdHashvalue] == NULL){ // empty slot
      H[holdHashvalue] = strdup(str);
    }
    if (H[offset1] == NULL){
      H[offset1] = strdup(str);
      if (H[offset1]!= NULL && this->ejectlimitReached()!= true){ // there is a string there
	notfound = H[offset1];
	H[offset1] = strdup(str);
	countEjects++;
      }
    }
    if (H[offset2] == NULL){
      H[offset2] = strdup(str);
      if (H[offset2]!= NULL && this->ejectlimitReached()!= true){ // there is a string there
        notfound = H[offset2];
        H[offset2] = strdup(str);
        countEjects++;
      }
    }
    if (H[offset3] == NULL){
      H[offset3] = strdup(str);
      if (H[offset3]!= NULL && this->ejectlimitReached()!= true){ // there is a string there
        notfound = H[offset3];
        H[offset3] = strdup(str);
        countEjects++;
      }
    }
    if (H[offset4] == NULL){
      H[offset4] = strdup(str);
      if (H[offset4]!= NULL && this->ejectlimitReached()!= true){ // there is a string there
        notfound = H[offset4];
        H[offset4] = strdup(str);
        countEjects++;
      }
    }
    else{// m_totalEjects++;
      try{
	if(this->ejectlimitReached() == true){
	  throw  PinballHashFull("The hash table is full");
	}
    }
      catch(PinballHashFull& zde){
	cerr << zde.what() << endl;// handling excemption
      }
    }
  }
}
	
    


	
int Pinball::find(const char *str){
  int getIndex;
  for (int i = 0; i < m_capacity; i++){
    if (H[i]!= NULL){
      if (strcmp(H[i],str) == 0){
	getIndex = i;
      }
      else{
	getIndex = -1;
      }
    }
  }
  return getIndex;
}


const char * Pinball::at(int index){
  char *takeString;
  try{
    assert(index < 0 || index > m_capacity);
  }
  catch (const out_of_range& outrange){
    cerr << "Out of Range error: " << outrange.what() << '\n';
  }
  for (int i = 0; i < m_capacity; i++){
    if (H[i]!= NULL && H[index]!= NULL){
      if (strcmp(H[i],H[index]) == 0){
	takeString = H[i];
      }
    }
  }
  return takeString;
}



unsigned int Pinball::getPrimary(){
  return m_primarySlots;
} 


char * Pinball::remove(const char *str){
  char *takeString; // pointer to hold removed string
  for (int i = 0; i < m_capacity; i++){
    cout << "H[i] = " << H[i] << "str = " << str << endl;
    if (H[i]!= NULL){
      if (strcmp(H[i],str) == 0){ //  
	takeString = H[i]; // take that string found
      }
    }
    else{
      return NULL; // the string is not in the hash table
    }
  }
  cout << "takestring = " << *takeString << endl;
  return takeString; // return it
}



void Pinball::printStats(){
  cout << "Hash Statistics Report: " << endl;
  cout << "\trandomness level = " <<  randomnessLvl << endl; 
  cout <<  "\tcapacity =  " << m_capacity << endl;
  cout <<  "\tsize = " <<  m_size << endl;
  cout <<  "\tdegree = " <<  m_degree << endl;
  cout <<  "\tejection limit = " <<  m_ejectLimit << endl; 
  cout << "\tnumber of primary slots  = " <<  m_primarySlots << endl; // can only be decided, when an item already
  // in the hashtable generates a hashcode, which gives a primary slot, each primary slots have auxilary slots
  cout << "\taverage hits to primary slots = " <<  endl;
  cout << "\tmaximum hits to primary slots = " << endl;
  cout << "\ttotal number of ejections = " <<  m_totalEjects << endl;
  cout << "\tmaximum number of ejections in a single insertion = " << m_maxEjects << endl;
}


void Pinball::setPrimary(int Primary){
  m_primarySlots = Primary;
} 


unsigned int Pinball::primaryslotCount(){
  return m_primarySlots++;
}


bool Pinball::isEmpty(){
  for (int i = 0; i < m_capacity; i++){
    if (H[i] == '\0'){
      return true;
    }
  }
  return false;
}


unsigned int Pinball::generateOffsets(unsigned int Primary)
{
  srand(time(NULL));
  unsigned int offset = Primary + (rand() % m_capacity + 1);
  return offset;
}


bool Pinball::ejectlimitReached(){
  if ( countEjects == 8){
    return true;
  }
  return false;
}
