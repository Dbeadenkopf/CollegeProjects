#include "nfl_sched.h"




int main(){

  Sched Nfl_teams;
  string fav_team;
  cout << "What is your favorite team?: ";
  cin >> fav_team;
  Nfl_teams.setTeam(fav_team);
  Nfl_teams.Output_results();



  return 0;
}
