// File: lab3.cpp
//
// Demonstrates use of the Dog class.
// Compile together with Dog.cpp
//

#include <iostream>
#include "Dog.h"

using namespace std;

int main() {
    // CREATE TWO OBJECTS OF THE "Dog" CLASS BY DECLARING VARIABLES
    // "dog1" AND "dog2" OF THAT CLASS TYPE:
  Dog dog1; // using this dog1 object
  Dog dog2; // dog2 object

    // PRINT THE INITIAL FIELD VALUES FOR THE dog1:
    cout << "dog1's original data:\n";
    cout << "  name is: " << dog1.GetName() << endl;
    cout << "  age in 2016 is: " << dog1.GetBirthYear() << endl;
    cout << "  owner is: " << dog1.GetOwner() << endl;

    // MODIFY dog1 AND dog2, BY USING THE APPROPRIATE Dog CLASS METHODS,
    // TO SET THE "owner" FIELD TO SOMETHING NEW, THEN FETCH THE FIELDS
    // BACK OUT AND PRINT
    cout << "Give the dogs to new owners:\n";
    string dogOwner1, dogOwner2;
    cout << "What is the name of this owner?  ";
    cin >> dogOwner1;
    cout << "What is the name of this owner? ";
    cin >> dogOwner2;
    dog1.SetOwner(dogOwner1); // set new owner for dog1
    cout << "dog1's new owner is: " << dog1.GetOwner() << endl;
    dog2.SetOwner(dogOwner2); // set new owner for dog2
    cout << "dog2's new owner is: " << dog2.GetOwner() << endl;

    // INTERACT WITH YOUR DOGS TO AFFECT THEIR HAPPINESS RATINGS,
    // BY USING THE Scold() AND Reward() METHODS
    cout << "Scold and reward a dog several times:\n";

    // Fetch current happiness value and print it out
    cout << "dog1 starts out " << dog1.GetHappiness() << endl;

    // Now, scold dog1 once, then reward it twice, printing out the
    // happiness level after each change:
    dog1.Scold();  // scold the dog
    cout << "Scolded dog1: dog is now " << dog1.GetHappiness() << endl;
    dog1.Scold();  // reward the dog
    cout << "Scloded dog1 more: dog is now " << dog1.GetHappiness() << endl;
    dog1.Reward();  // reward the dog
    cout << "Rewarded dog1: dog is now " << dog1.GetHappiness() << endl;

    
    cout << " " << endl;
    cout << "scolding dog for no reason" << endl;
    dog1.Scold();

    cout << "Reward dog for being good" << endl;
    dog1.Reward();
    cout << "Dog is now : " << dog1.GetHappiness();


    cout << "Rewarding dog again for being good" << endl;
    dog1.Reward();
    cout << "Dog is now: " << dog1.GetHappiness() << endl;
    // FINALLY, GET THE DOGS TO TALK TO YOU


    cout <<"Rewarding dog again for being good" << endl;
    dog1.Reward();
    cout << "Dog is now: " << dog1.GetHappiness() << endl;
    cout << "Asking dog1 to speak:\n";
    dog1.Talk();

    return 0;

}
