#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool isValidSudoku(vector<vector<char> > & board) {
    // Check Rows
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> rowSet;
        for (int j = 0; j < 9; ++j) {
            char current;
            cout << "Enter value at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> current;
            board[i][j] = current;  // Update the board with user input
            if (current != '.' && rowSet.find(current) != rowSet.end()) {
                return false; // Duplicate in the same row
            }
            rowSet.insert(current);
        }
    }
    // Check Columns
    for (int j = 0; j < 9; ++j) {
        unordered_set<char> colSet;
        for (int i = 0; i < 9; ++i) {
            char current = board[i][j];
            if (current != '.' && colSet.find(current) != colSet.end()) {
                return false; // Duplicate in the same column
            }
            colSet.insert(current);
        }
    }
    // Check 3 x 3 Sub-boxes
    for (int box = 0; box < 9; ++box) {
        unordered_set<char> boxSet;
        for (int i = box / 3 * 3; i < box / 3 * 3 + 3; ++i) {
            for (int j = (box % 3) * 3; j < (box % 3) * 3 + 3; ++j) {
                char current = board[i][j];
                if (current != '.' && boxSet.find(current) != boxSet.end()) {
                    return false; // Duplicate in the same sub-box
                }
                boxSet.insert(current);
            }
        }
    }

    return true; // The board is valid
}
int main() {
    vector<vector<char> > sudokuBoard(9, vector<char>(9, '.'));

    if (isValidSudoku(sudokuBoard)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}
