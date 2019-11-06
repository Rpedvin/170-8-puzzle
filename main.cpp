#include <vector>
#include <iostream>
#include "algorithms.h"

using namespace std;

// Pass vector by reference, so we can modify on the fly
// return n, the length/width of the n x n matrix
int grabInput(vector<vector<string>> &arr){
  int choice = 0, n = 0, j = 0;
  string tmp = "";

  while(true){
    cout << "Please insert 1 if you would like the default puzzle, or 2 if you would like to customize: ";
    cin >> choice;
    cout << endl;

    switch(choice){
      case 1:
        cout << "Loading Default 3x3 Puzzle..." << endl;
        arr.resize(3);
        arr.at(0).resize(3);
        arr.at(1).resize(3);
        arr.at(2).resize(3);
        // Sadly need to brute force this
        arr.at(0).at(0) = '1'; arr.at(0).at(1) = '2'; arr.at(0).at(2) = '3';
        arr.at(1).at(0) = '4'; arr.at(1).at(1) = '0'; arr.at(1).at(2) = '6';
        arr.at(2).at(0) = '7'; arr.at(2).at(1) = '5'; arr.at(2).at(2) = '8';
        printPuzzle(arr);
        cout << "Puzzle loaded." << endl << endl;
        return 3;
        break;
      case 2:
        while(true){
          cout << "How large would you like the array? Choose a number from 3 - 5: ";
          cin >> n;
          cout << endl;
          // Verify that n is in the range
          if (!(n > 2 && n < 6)){
            cout << "Invalid Input" << endl;
            // Force the loop to restart
            continue;
          }
          else{
            arr.resize(n);
            for (int i = 0; i < n; i++){
              arr.at(i).resize(n);
              for (int j = 0; j < n; j++){
                cout << "Insert index (" << i << ','<< j << ")'s item. Use 0 as the blank space: ";
                cin >> arr.at(i).at(j);
              }
            }
            printPuzzle(arr);
            return 1;
          }
        }
        break;
      default:
        cout << "Invalid Input" << endl;
        break;
    }
  }
}

Node menu(){
  vector<vector<string>> puzzleVector;
  vector<vector<string>> sol;
  vector<vector<string>> imp;
  int choice = 0;
  string tmp;

  cout << "Welcome to Renee Pedvin's 8-Puzzle solver." << endl;
  int x = grabInput(puzzleVector);
  int size = puzzleVector.at(0).size();

  // Create the solution and impossible solution vectors
  sol.resize(puzzleVector.size());
  imp.resize(puzzleVector.size());
  for (int i = 0; i < size; i++){
    sol.at(i).resize(size);
    imp.at(i).resize(size);
    for (int j = 0; j < size; j++){
        sol.at(i).at(j) = to_string(i*size + j + 1);
        imp.at(i).at(j) = to_string(i*size + j + 1);
    }
  }
  sol.at(size-1).at(size-1) = "0";
  imp.at(size-1).at(size-1) = "0";

  tmp = imp.at(size-1).at(size-2);
  imp.at(size-1).at(size-2) = imp.at(size-1).at(size-3);
  imp.at(size-1).at(size-3) = tmp;


  if (x == -1){
    // return empty node
    return Node();
  }
  cout << "What type of algorithm would you like to solve this with?: " << endl;
  cout << "    1) Uniform Cost Search" << endl;
  cout << "    2) A* with Misplaced Tile Heuristic" << endl;
  cout << "    3) A* with Manhattan Distance Heuristic" << endl << endl;
  while(true){
    cout << "Please input a number 1-3, or 0 to quit: ";
    cin >> choice;

    switch(choice){
      case 0:
        // return empty node
        return Node();
        break;
      case 1:
        return aStar(1, puzzleVector, sol, imp);
        break;
      case 2:
        return aStar(2, puzzleVector, sol, imp);
        break;
      case 3:
        return aStar(3, puzzleVector, sol, imp);
        break;
      default:
        break;
    }
  }
}

int main(){
  Node y = menu();
  if (y.n.size() == 0){
    cout << "Result: " << endl;
    printPuzzle(y.n);
  }
  return 0;
}
