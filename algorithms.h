#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Algorithm to use
void aStar();

// Heuristic functions, all return h(n)
int heuristicUniform();
int heuristicMisplaced();
int heuristicManhattan();

// Helper function for displaying overall puzzle
void printPuzzle(vector<vector<string>> );

#endif
