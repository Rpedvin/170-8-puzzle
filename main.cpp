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
        cout << "Puzzle loaded." << endl;
        return 3;
        break;
      case 2:
        while(true){
          cout << "How large would you like the array? Choose a number from 2 - 5: ";
          cin >> n;
          cout << endl;
          // Verify that n is in the range
          if (!(n > 1 && n < 6)){
            cout << "Invalid Input" << endl;
            // Force the loop to restart
            continue;
          }
          else{
            arr.resize(n);
            // Get and process input using stringstreams
            for (int i = 0; i < n; i++){
              arr.at(i).resize(n);
              for (int j = 0; j < n; j++){
                cout << "Insert index (" << i << ','<< j << ")'s item. Use 0 as the blank space: ";
                cin >> arr.at(i).at(j);
              }
            }
            printPuzzle(arr);
            cout << "Puzzle created. Does this look correct? (Y/N): ";
            while(true){
              cin >> tmp;
              if ((tmp.compare("y") || tmp.compare("Y")) == 1){
                  return n;
              }
              else if((tmp.compare("n") || tmp.compare("N")) == 0){
                  cout << "Please restart program to fix input." << endl;
                  return -1;
              }
              else{
                cout << "Please type 'Y' or 'N': ";
              }
            }
          }
        }
        break;
      default:
        cout << "Invalid Input" << endl;
        break;
    }
  }
}

int menu(){
  vector<vector<string>> puzzleVector;
  cout << "Welcome to Renee Pedvin's 8-Puzzle solver." << endl;
  int x = grabInput(puzzleVector);
  if (x == -1){
    return -1;
  }
  cout << "What type of algorithm would you like to solve this with?: " << endl;
  cout << "    1) "

}

int main(){
  int y = menu();
  return 0;
}
