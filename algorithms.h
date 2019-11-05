#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Algorithm to use
void aStar();

// Heuristic functions, all return h(n)
int heuristicUniform(vector<vector<string>>, int, int);
int heuristicMisplaced(vector<vector<string>>, int, int);
int heuristicManhattan(vector<vector<string>>, int, int);

// Helper function for displaying overall puzzle
void printPuzzle(vector<vector<string>> );

// Helper function for checking puzzle's solved state
int checkPuzzle(vector<vector<string>> );

#endif
