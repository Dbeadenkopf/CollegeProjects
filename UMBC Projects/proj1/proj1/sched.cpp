#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "sched.h"
using namespace std;

// FUNCTION PROTOTYPES -- DO NOT CHANGE!

// sort() - sorts an array of floats returning sorted indices
// On return, indx[] is an array of indices such that data[indx[0]], 
// data[indx[1]], ..., data[indx[len-1]] is data[] in ascending order.
//
// Parameters
//    data[] - float array of data to be ordered
//    indx[] - int array, same length as data[], to hold indices
//    len - int specifying the length of data[] and indx[]

void sort(float data[], int indx[], int len){
  for (int i = 0; i < len; i++){
    indx[i] = i;
  }
  int holder;
  for (int i = 0; i < len-1; i++){
    for (int j = 0; j < len-1;j++){
      if (data[indx[j]] > data[indx[j+1]]){
	holder = indx[j];
	indx[j] = indx[j+1];
	indx[j+1] = holder;
      }
      else
	{
	  continue;
	}
    }
  }
  
}

/*  int i = 0;
  while(i < len){
  cout << data[indx[i]] << " ";
    i++;
    }*/
 
  


// sched() - schedules events given start and end times, and indx[] from sort
// Returns number of events scheduled; on return, scheduled[] contains 
// indices of scheduled events (e.g. startTime[scheduled[0]] is the start
// time of the first schedled event).
//
// Parameters
//    startTime[] - float array of event start times
//    endTime[] - float array of event end times
//    indx[] - array of indices that orders the end times
//    scheduled[] - int array to hold indices of scheduled events // this could be linked to what needs to be returned
//    len - int specifying the length of the arrays
// Returns
//    int value specifying number of events scheduled

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len){
  int counter = 0;
  scheduled[counter] = indx[0];
  for (int i = 1; i < len; i++){
    if(startTime[indx[i]] >= endTime[scheduled[counter]]){   
      scheduled[++counter] = indx[i];
      // counter++;
    }
  }
  return counter+1;
}
  

// printEvent() - prints an event to the console
// Converts float start and end times to hh:mm format and prints times
// along with description.  E.g. Study Session from 12.5 to 13.25 should
// print as "12:30 - 13:15 Study Session"
//
// Parameters
//    startTime - float event start time
//    endTime - float event end time
//    description - string event description



// this needs to be finished up
void printEvent(float startTime, float endTime, string description){
  // go through and look at floating point times and change them to a military timing instance
  const int intStart = startTime;
  const int intEnd = endTime;
  const int startMins = (startTime - intStart)*60;
  const int endMins = (endTime - intEnd)*60;
  if ((startTime < 10.00) || (endTime < 10.00) || (intEnd < 10.00 || intStart < 10.00)){
    cout << "0" << intStart << ":" << startMins << " - " << "0" << intEnd << ":" << endMins  << " " << description <<  "\n";
    }
  else if ((startTime > 10.00 && startTime < 12.5) && (endTime > 10.00 && endTime < 12.5)){
    cout << "0" << intStart << ":" << startMins << " - " <<  "0" << intEnd << ":" << endMins << " " << description << "\n";
  }
  // else then it just gets zeros
  else if ((startTime > 12.5 && startTime < 15.00) && (endTime > 12.5 && endTime <= 15.00)){
    cout <<  intStart << ":" << "0" << startMins << " - " << intEnd << ":" <<  endMins <<  " " << description << "\n";
  }
  // else then it just gets zeros
  else{
    cout <<  intStart << ":" << startMins << " - " << intEnd << ":" << endMins << " " << description << "\n";// could possibley use cmath floor
  }
  // else then it just gets zeroo
}
//int twefiveMin = 0.25*60;
//  int sevfiveMin = 0.75*60;
  


// MAIN PROGRAM - DO NOT CHANGE!

int main(){
  int indx[NUM_EVENTS];
  int scheduledEvents[NUM_EVENTS];
  int numSched;// number of events sheduelded(could be intilized to zero)
  // probeley need a while loop to get out all of the data as well as count the data to measure the length of the data
  
  
  // Sort by e   vent ending times
  sort(endTime, indx, NUM_EVENTS);
  
  // Call greedy scheduling algorithm
  // int numSched;
  numSched = sched(startTime, endTime, indx, scheduledEvents, NUM_EVENTS);

  // Display scheduled events
  for (int i = 0; i < numSched; i++){
    printEvent(startTime[scheduledEvents[i]], endTime[scheduledEvents[i]],
	       description[scheduledEvents[i]]);
  }
  return 0;
}

//
// FUNCTION IMPLEMENTATIONS GO HERE
//  
