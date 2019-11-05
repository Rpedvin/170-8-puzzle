#include "algorithms.h"



// Cast things to int. Do the thing!









// Helper function for displaying overall puzzle
// Doesn't need to be pass by ref, so no potential modification
void printPuzzle(vector<vector<string>> arr){
  for (int i = 0; i < arr.size(); i++){
    cout << "[ ";
    for (int j = 0; j < arr.at(i).size(); j++){
      cout << arr.at(i).at(j);
      if (( j + 1 )!=(arr.at(i).size())){
        cout << ", ";
      }
    }
    cout << " ]" << endl;
  }
}

int checkPuzzle(vector<vector<string>> arr){
  // Iterate over aray
  int value = 0;
  int n = 0;
  for (int i = 0; i < arr.size(); i++){
    n = arr.at(i).size();
    for (int j = 0; j < arr.at(i).size(); j++){
      value = arr.at(i).at(j);
      // If the item is equivalent to what it should be
      if (value == (i*n + j + 1)){
        continue;
      }
      // Check to see if we're in an impossible to solve state
      else if (i == n - 1){
        if (j == n - 3){
          if (value == ((n*n) - 1)){
            value = arr.at(i).at(j+1);
            if (value == ((n*n) - 2)){
              value = arr.at(i).at(j+2);
              if (value == 0){
                return -2;
              }
            }
          }
        }
      }
      // Reset value just in case
      value = arr.at(i).at(j);
      // Check to see if we're on the last number, and the last number is 0
      if (i == j == n - 1){
        if (value == 0){
          return 0;
        }
      }
      // Otherwise keep going
      else{
        return -1;
      }
    }
  }
  return 0;
}


// Potential heuristic functions

// Uniform Cost Search (AKA no heuristic)
int heuristicUniform(){
  return 0;
}

// Misplaced Tile Heuristic
int heuristicMisplaced(vector<vector<string>> arr, int x, int y){
  int n = arr.at(x).size();
  int misplaced = 0;
  int value = 0;
  // Iterate over aray
  for (int i = 0; i < arr.size(); i++){
    for (int j = 0; j < arr.at(i).size(); j++){
      value = arr.at(i).at(j);
      // If the item is equivalent to what it should be
      if (value == (i*n + j + 1)){
        continue;
      }
      // If the tile is 0, check if we're in the last position. If not, it's misplaced.
      if (value == 0){
       if (i == j == n - 1){
          continue;
        }
      }
      // Otherwise increment
      else{
        misplaced++;
      }
    }
  }
  return misplaced;
}

// Manhattan Distance heuristic
int heuristicManhattan(vector<vector<string>> arr, int i, int j){
  int dx = 0;
  int dy = 0;
  int n = arr.at(i).size();
  int value = arr.at(i).at(j);
  if (value == 0){
    dx = abs(i - (n - 1));
    dy = abs(j - (n - 1));
  }
  else{
    dx = abs(i - ((value - 1)/n));
    dy = abs(j - ((value - 1)%n));
  }
  return (dx + dy);
}

// A* algorithm
void aStar(){

}
