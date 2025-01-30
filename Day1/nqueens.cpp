/*The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    
    void solve(int col, int n, vector<int>& board, vector<bool>& rows, vector<bool>& d1, vector<bool>& d2) {
        if (col == n) {
            results.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (!rows[row] && !d1[row + col] && !d2[row - col + n - 1]) {
                board[col] = row + 1;
                rows[row] = d1[row + col] = d2[row - col + n - 1] = true;
                
                solve(col + 1, n, board, rows, d1, d2);
                
                rows[row] = d1[row + col] = d2[row - col + n - 1] = false;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<int> board(n);
        vector<bool> rows(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
        solve(0, n, board, rows, d1, d2);
        return results;
    }
};