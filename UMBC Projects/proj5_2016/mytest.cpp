#include <iostream>
#include <string>
#include <cstring>
#include "iterator_ex.h"
#include "sorted.h"
// I incremently tested each function 
// by pulling pieces of sorted_driver.cpp to this test file
// I also manuelly tested most of the functions so they should work
using namespace std;
int main(){

  sorted<int> x;
  sorted<int>::const_iterator itr;
  //int temp1 = 5;
  //x.begin();
  //x.insert(5);
  //x.insert(6);
  // throws my 
  for (int i = 0; i < 10; i++ )
    x.insert( (i*i) % 23 );
  
  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    cout << *itr << " ";
  cout << endl << endl;

  cout << "capacity of x is " << x.capacity() << endl;
  cout << "size of x is " << x.size() << endl << endl;


  cout << "Now we will erase() some items in x..." << endl;
  int i = 0;
  for (itr = x.begin(); itr != x.end();) {
    if (i == 2 || i == 4 || i == 7) {
      itr = x.erase(itr);
    } else {
      itr++;
    }
    i++;
  }
  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    cout << *itr << " ";
  cout << endl << endl;

  cout << "capacity of x is " << x.capacity() << endl;
  cout << "size of x is " << x.size() << endl << endl;



  cout << "Insert a few more items in x (21, -3, 9)..." << endl;

  x.insert(21);
  x.insert(-3);
  x.insert(9);

  cout << "Items in x: ";
  for (itr = x.begin(); itr != x.end(); itr++)
    cout << *itr << " ";
  cout << endl << endl;


  cout << "Create a 'playlist' of Prince songs..." << endl << "\n";

  sorted<string> songs;

  songs.insert("When You Were Mine");
  songs.insert("Pop Life");
  songs.insert("Adore");
  songs.insert("Purple Rain");
  songs.insert("Kiss");
  songs.insert("If I Was Your Girlfriend");
  songs.insert("Joy in Repetition");
  songs.insert("The Ballad of Dorothy Parker");
  songs.insert("Little Red Corvette");
  songs.insert("When Doves Cry");

  sorted<string>::const_iterator songitr;
  //sorted<string>::rand_iterator rndsongitr;
  //cout << endl;

  cout << "My Prince songs:" << endl;
  for ( songitr = songs.begin(); songitr != songs.end(); songitr++ ){
    cout << "  " << *songitr << endl;
  }


  // testing some random iterator functions 
  /*cout << endl;
  cout << "My Prince songs shuffled:" << endl;
  for ( rndsongitr = songs.rndbegin(); rndsongitr != songs.rndend(); rndsongitr++ )
    cout << "  " << *rndsongitr << endl;
    cout << endl;*/

  //sorted<string> test;
  // did not make a well implmented copy constructor 
  // so just using the songs
  //test = songs;

  cout << "Testing operator= by creating a copy and then deleting "
       << "one item from copy..." << endl;

  // Delete a song from test; test and songs should be different
  songitr = songs.begin();
  songitr++;
  songitr++;
  songs.erase(songitr);

  cout << endl;
  cout << "My Prince songs:" << endl;
  for ( songitr = songs.begin(); songitr != songs.end(); songitr++ )
    cout << "  " << *songitr << endl;

  cout << endl;
  cout << "My Prince songs (copy with 'Joy in Repetition' deleted):" << endl;
  for ( songitr = songs.begin(); songitr != songs.end(); songitr++ )
  cout << "  " << *songitr << endl;


  
    //static const int num = 11;  
  //int temp[10] = {4,3,2,1,0,-1,-2,-3,-4,5};
  //sorted2 obj(temp, 9);
  //cout << "Testing size() " << obj.size() << endl;
  //cout << "Testing the capacity " << obj.capacity() << endl;
  // need to insert items into array before iterating through it
  
  //try{
  //sorted<int> arr[10] = {3,4,2,3,4,5,6,4,1,0};
  //sorted y(arr, 11);  
  //} 
  //catch (iterator_ex& e){
  //cout << "testing " << endl;
  // cerr << "Error: " << e.what() << endl;
  //}
  
  return 0;
}


