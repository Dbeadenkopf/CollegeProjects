#include <iostream>
#include <cstring>
#include <vector>
#include "linked.h"
#include <sys/times.h>
#include <sys/resource.h>
#include <stdexcept>
using namespace std;
int main () {
  cout << "TEST 1" << endl;
   LinkedList<int> L; 

   L.addFront(5) ;
   L.addFront(4) ;
   L.addFront(3) ;
   L.addFront(2) ;
   L.addFront(1) ;
   L.addFront(0) ;

   cout << "Print using [] operator\n" ;
   cout << L[0] << endl ;
   cout << L[1] << endl ;
   cout << L[2] << endl ;
   cout << L[3] << endl ;
   cout << L[4] << endl ;
   cout << L[5] << endl ;

   cout << "\nPrint using print function\n" ;
   L.print()  ;

   cout << "\nPrint using print function (second time)\n" ;
   L.print()  ;

   cout << "\nPrint using print function (third time)\n" ;
   L.print()  ;

  

   cout << "Test 4" << endl;

   LinkedList< vector<int> > A ;
   vector<int> dummy7 ;


   // Create a vector<int> with 7 items
   //
   for (unsigned int i = 0 ; i < 7 ; i++) {
     dummy7.push_back(0) ;
   }
   

   //  Add dummy7 to A 7 times
   //  Remember that addFront() makes a copy.
   //  So, A has 7 different copies of dummy7.
   //
   for (unsigned int i = 0 ; i < 7 ; i++) {
     A.addFront(dummy7) ;  // addFront() copies
   }


   // Construct mod 7 multiplication table
   //
   for (unsigned int i = 0 ; i < 7 ; i++) {
     for (unsigned int j = 0 ; j < 7 ; j++) {
       A[i][j] = ( i * j ) % 7 ;
     }
   }


   // Print out mod 7 multiplication table
   //
   for (unsigned int i = 0 ; i < 7 ; i++) {
     for (unsigned int j = 0 ; j < 7 ; j++) {
       cout << A[i][j] << " " ;
     }
     cout << endl ;
   }

    cout << "Test 2" << endl;

   LinkedList<double> doubleL ;

   doubleL.addFront(5.25) ;
   doubleL.addFront(4.25) ;
   doubleL.addFront(3.25) ;
   doubleL.addFront(2.25) ;
   doubleL.addFront(1.25) ;
   doubleL.addFront(0.25) ;

   cout << "*** doubleL ***" << endl ;
   doubleL.print() ;
   
   LinkedList<double> dL2(doubleL) ;

   cout << "*** dL2 ***" << endl ;
   dL2.print() ;

   doubleL[2] = 17.413 ;
   doubleL[4] = 997.111 ;
   cout << "*** doubleL changed ***" << endl ;
   doubleL.print() ;

   cout << "*** dL2 did not change ***" << endl ;
   dL2.print() ;

   doubleL = dL2 ;
   cout << "*** doubleL restored ***" << endl ;
   doubleL.print() ; 
   
  
}
