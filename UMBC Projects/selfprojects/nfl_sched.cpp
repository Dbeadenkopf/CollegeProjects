#include "nfl_sched.h"

Sched::Sched(){
  name = "Ravens";
}

Sched::Sched(string z){
  name = z;
}


void Sched::setTeam(string x){
  name = x;
}

string Sched::getName(){
  return name;
}



void Sched::Output_results(){
  // I think its shouting at me for this getname
  cout << "This is the football team " << getName() << endl;
}
