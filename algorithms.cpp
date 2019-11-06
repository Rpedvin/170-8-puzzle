#include "algorithms.h"

// Definitions for the Node Struct
Node::Node(){
}

Node::Node(vector<vector<string>> arr, int cost){
  n = arr;
  c = cost;
}

// Check if nodes are the same
int checkNode(Node a, Node b){
  for (int i = 0; i < a.n.size(); i++){
    for (int j = 0; j < a.n.at(i).size(); j++){
      if (a.n.at(i).at(j) == b.n.at(i).at(j)){
        continue;
      }
      else{
        // Nodes are not the same;
        return 1;
      }
    }
  }
  // Nodes are the same
  return 0;
}

int checkExpand(Node a, vector<Node> vec){
  // loop through expanded nodes, check if current node exists inside of it
  for (int i = 0; i < vec.size(); i++){
    if (checkNode(a, vec.at(i)) == 0){
      return 0;
    }
  }
  return 1;
}

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

// Check Puzzle for solved, insolvable, or unsolved states
int checkPuzzle(vector<vector<string>> arr){
  // Iterate over aray
  int value = 0;
  int n = 0;
  for (int i = 0; i < arr.size(); i++){
    n = arr.at(i).size();
    for (int j = 0; j < arr.at(i).size(); j++){
      value = stoi(arr.at(i).at(j));
      // If the item is equivalent to what it should be
      if (value == (i*n + j + 1)){
        continue;
      }
      // Check to see if we're in an impossible to solve state
      else if (i == n - 1){
        if (j == n - 3){
          if (value == ((n*n) - 1)){
            value = stoi(arr.at(i).at(j+1));
            if (value == ((n*n) - 2)){
              value = stoi(arr.at(i).at(j+2));
              if (value == 0){
                return -2;
              }
            }
          }
        }
      }
      // Reset value just in case
      value = stoi(arr.at(i).at(j));
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
int heuristicMisplaced(vector<vector<string>> arr){
  int n = arr.at(0).size();
  int misplaced = 0;
  int value = 0;
  // Iterate over aray
  for (int i = 0; i < arr.size(); i++){
    for (int j = 0; j < arr.at(i).size(); j++){
      value = stoi(arr.at(i).at(j));
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
  int value = stoi(arr.at(i).at(j));
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
Node aStar(int selec, vector<vector<string>> arr){
  // Grab the size of the nxn vector
  int m = arr.at(0).size();
  // Create the initial state node with no cost
  Node n = Node(arr, 0);
  // Create an empty node with nothing assigned.
  Node diff = Node();
  // Unexpanded nodes
  priority_queue<Node> freshNodes;
  // Expanded nodes
  vector<Node> oldNodes;
  // A value for the check to return to
  int check = 0;
  // Location of '0'
  int x = -1, y = -1;
  // String for holding swap value
  string temp;

  // push initial state
  freshNodes.push(n);

  // While the queue is not empty
  while(freshNodes.size() != 0){
    // Pop a node off the queue
    n = freshNodes.top();
    // Push the node onto the expanded nodes vector
    oldNodes.push_back(n);
    check = checkPuzzle(n.n);
    // If the puzzle solved properly
    if (check == 0)
      return n;
    // If we're in an impossible state;
    else if(check = -2){
      cout << "Puzzle cannot be solved!" << endl;
      return n;
    }
    // Otherwise
    else{
      // Find the '0'
      for (int i = 0; i < n.n.size(); i++){
        for (int j = 0; j < n.n.at(i).size(); j++){
          // If we find 0
          if (n.n.at(i).at(j) == "0"){
            x = i;
            y = j;
            break;
          }
        }
        // If we've already found 0
        if ((x != -1) && (y != -1)){
          break;
        }
      }
      // Search potential expansions
      // Search up
      if (x != 0){
        diff = n;
        // Swap values
        temp = diff.n.at(x).at(y);
        diff.n.at(x).at(y) = diff.n.at(x-1).at(y);
        diff.n.at(x).at(y) = temp;

        // Check if expanded already
        if (checkExpand(diff, oldNodes) == 1){
          // Assign a value based on the item moved
          if (selec == 1){
            diff.c = heuristicUniform();
          }
          if (selec == 2){
            diff.c = heuristicMisplaced(diff.n);
          }
          if (selec == 3){
            diff.c = heuristicManhattan(diff.n, x-1, y);
          }
          // push node to queue
          freshNodes.push(diff);
        }
        // Otherwise, toss the node and move to the next one
      }
      // Search left
      if (y != 0){
        diff = n;
        // Swap values
        temp = diff.n.at(x).at(y);
        diff.n.at(x).at(y) = diff.n.at(x).at(y-1);
        diff.n.at(x).at(y) = temp;

        // Check if expanded already
        if (checkExpand(diff, oldNodes) == 1){
          // Assign a value based on the item moved
          if (selec == 1){
            diff.c = heuristicUniform();
          }
          if (selec == 2){
            diff.c = heuristicMisplaced(diff.n);
          }
          if (selec == 3){
            diff.c = heuristicManhattan(diff.n, x, y-1);
          }
          // push node to queue
          freshNodes.push(diff);
        }
        // Otherwise, toss the node and move to the next one
      }
      // Search right
      if (y != (m - 1)){
        diff = n;
        // Swap values
        temp = diff.n.at(x).at(y);
        diff.n.at(x).at(y) = diff.n.at(x).at(y+1);
        diff.n.at(x).at(y) = temp;

        // Check if expanded already
        if (checkExpand(diff, oldNodes) == 1){
          // Assign a value based on the item moved
          if (selec == 1){
            diff.c = heuristicUniform();
          }
          if (selec == 2){
            diff.c = heuristicMisplaced(diff.n);
          }
          if (selec == 3){
            diff.c = heuristicManhattan(diff.n, x, y+1);
          }
          // push node to queue
          freshNodes.push(diff);
        }
        // Otherwise, toss the node and move to the next one
      }
      // Search down
      if (x != (m - 1)){
        diff = n;
        // Swap values
        temp = diff.n.at(x).at(y);
        diff.n.at(x).at(y) = diff.n.at(x+1).at(y);
        diff.n.at(x).at(y) = temp;

        // Check if expanded already
        if (checkExpand(diff, oldNodes) == 1){
          // Assign a value based on the item moved
          if (selec == 1){
            diff.c = heuristicUniform();
          }
          if (selec == 2){
            diff.c = heuristicMisplaced(diff.n);
          }
          if (selec == 3){
            diff.c = heuristicManhattan(diff.n, x+1, y);
          }
          // push node to queue
          freshNodes.push(diff);
        }
        // Otherwise, toss the node and move to the next one
      }
    }
    // Reset all necessary variables, reset loop
    x = (-1);
    y = (-1);
    // Pop top node off of queue
    freshNodes.pop();
  }
  // If all else fails, return empty node
  return Node();
}
