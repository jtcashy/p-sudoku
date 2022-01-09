#include "sudoku.cpp"
#include <iostream>

using namespace std;

// This is the driver program for solving sudoku puzzles
// puzzles are read in from cin (using inpute redirection from .txt file)
// EXAMPLE CMD LINE: ./puzzle_solver < game-1.txt

int main(int argc, char *argv[]) { 

    Sudoku game;
    game.solve();

    return 0;
}