#ifndef NFL_SCHED_H
#define NFL_SCHED_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Sched{

public:
  Sched();
  Sched(string z);
  string getName();
  void setTeam(string x);
  void Output_results();
private:
  string name;
};









#endif
