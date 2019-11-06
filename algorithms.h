#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string> // for strings
#include <iostream> // for console io
#include <vector> // for holding the array
#include <queue> // for priority queue
#include <utility>  // for stoi
#include <algorithm> // for swap
using namespace std;

// Node Struct
struct Node{
  vector<vector<string>> n;
  int c;
  bool operator<(const Node& r) const{
    // Backwards, because we want the smallest cost first
    return c > r.c;
  }

  Node();
  Node(vector<vector<string>>, int);
};

// Algorithm to use
Node aStar(int, vector<vector<string>>, vector<vector<string>>, vector<vector<string>>);

// Heuristic functions, all return h(n)
int heuristicUniform();
int heuristicMisplaced(vector<vector<string>>);
int heuristicManhattan(vector<vector<string>>);

// Helper function for displaying overall puzzle
void printPuzzle(vector<vector<string>> );

// Helper function for checking puzzle's solved state
int checkPuzzle(vector<vector<string>>, vector<vector<string>>, vector<vector<string>>);

// Node handling helper functions
// Checks if nodes are the same
int checkNode(Node, Node);
// Checks if the value already exists in the expanded array
int checkExpand(Node, vector<Node>);

#endif
