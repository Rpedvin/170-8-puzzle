#include "algorithms.h"

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

// Potential heuristic functions

// Uniform Cost Search (AKA no heuristic)
int heuristicUniform(){
  return 0;
}

// Misplaced Tile Heuristic
int heuristicMisplaced(){

}

// Manhattan Distance heuristic
int heuristicManhattan(){

}

// A* algorithm
void aStar(){

}
