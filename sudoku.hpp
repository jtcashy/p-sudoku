
#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Sudoku {
    vector<vector<int>> grid = vector<vector<int>>(9,vector<int>(9,0)); // Representation of original puzzle (9x9)
    vector<vector<int>> answer; // Representation of solved puzzle (9x9)
    
    // Holds the number of times each digit (1-9) has been used in each row, column and 3x3 square respectively
    vector<unordered_map<int,int>> rowCounter = vector<unordered_map<int,int>>(9,unordered_map<int,int>()); // For Rows
    vector<unordered_map<int,int>> colCounter = vector<unordered_map<int,int>>(9,unordered_map<int,int>()); // For Columns
    vector<unordered_map<int,int>> sqrCounter = vector<unordered_map<int,int>>(9,unordered_map<int,int>()); // For 3x3 Squares

    
    // Determines if the current grid is a valid grid
    // Returns true if valid and false if not
    // O(1) runtime
    bool promising(vector<vector<int>> &nextGrid, size_t &r, size_t &c);

    // Determines if every position has been filled 
    // Returns true if every square is filled and false if not
    // Operates row major
    // O(n^2) runtime
    bool solution(vector<vector<int>> &nextGrid, size_t in_row);

    // Recursive function which controls the backtracking and pruning of the sudoku puzzle
    // Operates row major
    int checkGrid(vector<vector<int>> nextGrid, size_t r, size_t c);
    
public:
    
    // Constructor which uses cin (using input redirection) to
    // read in unsolved sudoku puzzle (9x9)
    Sudoku();

    // Helper function which finds the first empty space and computes
    // the number of possible solutions for the read in puzzle
    void solve();

    // Prints to terminal a representation of the puzzle with 
    // 0 representing unfilled spaces (space delimiter)
    void printGrid(vector<vector<int>> &inputGrid);
};

#endif