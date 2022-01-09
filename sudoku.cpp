#include "sudoku.hpp"

bool Sudoku::promising(vector<vector<int>> &nextGrid, size_t &r, size_t &c) {
       
    if(rowCounter[r][nextGrid[r][c]] > 1) { // Checks for number of val in row
        return false;
    }

    if(colCounter[c][nextGrid[r][c]] > 1) { // Checks for number of val in column
        return false;
    }

    size_t k = (r/3) + 3*(c/3); // k is which square [r][c] is in

    if(sqrCounter[k][nextGrid[r][c]] > 1) { // Checks for number of val in square (3 x 3)
        return false;
    }

    return true;
}

bool Sudoku::solution(vector<vector<int>> &nextGrid, size_t in_row) {
    for(size_t r = in_row; r < nextGrid.size(); r++) {
        for(size_t c = 0; c < nextGrid[r].size(); c++) {
            if(nextGrid[r][c] == 0)
                return false;
        }
    }

    return true;
}

int Sudoku::checkGrid(vector<vector<int>> nextGrid, size_t r, size_t c) {
    int val = 0;

    if(promising(nextGrid,r,c)) {
        if(solution(nextGrid,r)) {
            answer = nextGrid; 
            return 1;
        }
        else {

            bool stop = false;
            for(size_t k = r; k < nextGrid.size() && stop == false; k++) {
                for(size_t j = 0; j < nextGrid[r].size(); j++) {
                    if(nextGrid[k][j] == 0) {
                        r = k;
                        c = j;
                        stop = true;
                        break;
                    }
                }
            }
                
            for(int j = 1; j <= 9; j++) {
                nextGrid[r][c] = j;

                size_t k = (r/3) + 3*(c/3);

                rowCounter[r][nextGrid[r][c]]++;
                colCounter[c][nextGrid[r][c]]++;
                sqrCounter[k][nextGrid[r][c]]++;

                val += checkGrid(nextGrid,r,c);

                rowCounter[r][nextGrid[r][c]]--;
                colCounter[c][nextGrid[r][c]]--;
                sqrCounter[k][nextGrid[r][c]]--;
            }
        }
    }

    return val;
}
    
Sudoku::Sudoku() {
    int temp = -1;
    for(size_t r = 0; r < grid.size(); r++) {
        for(size_t c = 0; c < grid[r].size(); c++) {
            cin >> temp; 

            grid[r][c] = temp; 

            if(temp != 0) {
                size_t k = (r/3) + 3*(c/3);
                rowCounter[r][grid[r][c]]++;
                colCounter[c][grid[r][c]]++;
                sqrCounter[k][grid[r][c]]++;
            }
        }
    }
}

void Sudoku::solve() {
    cout << "Attempting to solve...\n";
    printGrid(grid);
    cout << "\n";
        
    size_t r = 0;
    size_t c = 0;
    bool stop = false;

    for(size_t k = 0; k < grid.size() && stop == false; k++) {
        for(size_t j = 0; j < grid[r].size(); j++) {
            if(grid[k][j] == 0) {
                r = k;
                c = j;
                stop = true;
                break;
            }
        }
    }

        
    int num = checkGrid(grid,r,c);
    if(num > 0) {
        cout << num << " solution(s) found\n";
        printGrid(answer);
    }
    else {
        cout << "No solution found\n";
        printGrid(answer);
    }
}

void Sudoku::printGrid(vector<vector<int>> &inputGrid) {
    for(size_t r = 0; r < inputGrid.size(); r++) {
        for(size_t c = 0; c < inputGrid[r].size(); c++) {
            cout << inputGrid[r][c] << " ";
        }
        cout << "\n";
    }
}

