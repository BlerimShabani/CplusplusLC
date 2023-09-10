/*36. Valid Sudoku
Medium
9.6K
991
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without
repetition. Note:

A Sudoku board (partially filled) could be valid but is not necessarily
solvable. Only the filled cells need to be validated according to the mentioned
rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rows(9, vector<bool>(9, false));
    vector<vector<bool>> cols(9, vector<bool>(9, false));
    vector<vector<bool>> boxes(9, vector<bool>(9, false));

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0' - 1;
          int boxIdx = (i / 3) * 3 + (j / 3);

          if (rows[i][num] || cols[j][num] || boxes[boxIdx][num]) {
            return false; // Duplicate number found
          }

          rows[i][num] = true;
          cols[j][num] = true;
          boxes[boxIdx][num] = true;
        }
      }
    }

    return true;
  }
};

int main() {
  Solution solution;

  vector<vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  bool result1 = solution.isValidSudoku(board1);

  cout << "Is board 1 valid? " << (result1 ? "Yes" : "No")
       << endl; // Output: Yes

  return 0;
}
/*Here's how this code works:

We initialize three 2D vectors (rows, cols, and boxes) to keep track of the
numbers in each row, column, and 3x3 sub-box. Initially, all values are set to
false.

We iterate through each cell of the Sudoku board.

For each non-empty cell, we convert the character to an integer (num) and adjust
it to a 0-based index.

We calculate the index of the 3x3 sub-box (boxIdx) based on the current cell's
position.

We check if the current number has already been seen in the same row, column, or
3x3 sub-box. If so, the Sudoku board is not valid.

If the number is unique in all three aspects, we update the vectors to mark the
number as seen.

If we complete the iteration without finding any duplicates, the Sudoku board is
valid, and we return true.

You can use this Solution class to check if a Sudoku board is valid. For
example:*/