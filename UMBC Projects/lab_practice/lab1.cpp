#include <iostream>
#include <cmath>
using namespace std;

const int NUM_STUDENTS = 25;  // maximum number of scores

// Function prototypes - do not change!

int max(int data[], int dataLen);
int min(int data[], int dataLen);
float average(int data[], int dataLen);

int main() {
  int scores[NUM_STUDENTS] = {0};
  int numScores = 0;
  int inputValue;

  /////////////////////////////////////////////////////
  // CODE TO READ SCORES FROM THE KEYBOARD GOES HERE //
  /////////////////////////////////////////////////////
  //  cout << "Enter a score (-1 when done): ";
  //cin >> inputValue;
  // scores[numScores] = inputValue;
  while(inputValue!= -1){
    cout << "Enter a score (-1 when done): ";
    cin >> inputValue;
    scores[numScores] = inputValue;
    numScores++;
    if (inputValue == -1){
      break;
    }
  }
  int maxVal = max(scores, numScores);
  int minVal = min(scores, numScores);
  float avgVal = average(scores, numScores);
  //////////////////////////////////////////
  // CALLS TO min() AND average() GO HERE //   
  //////////////////////////////////////////

  cout << "Max score is " << maxVal << endl;
  cout << "Min score is " << minVal << endl;
  cout << "Average is " << avgVal << endl;
    
  return 0;
}

// max() - computes maximum value in an int array
// Assumes data[] contains at least one element

int max(int data[], int dataLen){
  int currentMax = data[0];
  for (int i = 1; i < dataLen; i++) {
    if (data[i] > currentMax) {
      currentMax = data[i];
    }
  }

  return currentMax;
} 

int min(int data[], int dataLen) {
  int currentMin;
  for (int i = 1; i < dataLen; i++) {
    if (data[i] < data[i+1] && data[i]!= -1) {
      currentMin = data[i];
      data[i] = data[i+1];
      data[i+1] = currentMin;
    }
  }
  return currentMin;
}

float average(int data[], int dataLen){
  dataLen = dataLen - 1;
  float getAverage;
  float sum = 0;
  cout << "Checking dataLen " << dataLen << endl;
  for (int i = 0; i < dataLen; i++){
    if (data[i]!= -1){
      sum = sum + data[i];
      getAverage = (sum/dataLen);
    }
    // getAverage = avg(sum);
  }

  return getAverage;
}
