#include <vector>
#include <iostream>

using namespace std;

// Pass vector by reference, so we can modify on the fly
// return n, the length/width of the n x n matrix
int grabInput(vector<vector<int>> &arr){
  while (true){
    int choice = 0, n = 0;

    cout << "Please insert 1 if you would like the default puzzle, or 2 if you would like to customize: ";
    cin >> choice;
    cout << endl;

    switch(choice){
      case 1:
        cout << "Loading Default 3x3 Puzzle..." << endl;
        arr.assign({1, 2, 3}, {4, 0, 6}, {7, 5, 8});
        return 3;
        break;
      case 2:
        while (true):
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
            
          }
        break;
      default:
        cout << "Invalid Input" << endl;
        break;
    }
}

int menu(){
  vector<vector<int>> puzzleVector;
  cout << "Welcome to Renee Pedvin's 8-Puzzle solver." << endl;

}

int main(){

  return 0;
}
