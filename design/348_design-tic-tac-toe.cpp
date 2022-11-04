// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
348_design-tic-tac-toe LeetCode

Solution: 
    - dummy solution using mat (O(N^2)) and O(N) move
    - use vector ("hashmap") to achieve O(N) space and O(1) move
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class TicTacToe {
    vector<vector<int>> map;
    int winner;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : map(2*n+2, vector<int>(2, 0)), winner(0) { }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        if (winner != 0) return winner;
        
        int n = map.size() / 2 - 1;
        
        if (++map[row][player-1] == n) {
            winner = player;
            return winner;
        }
            
        if (++map[n+1+col][player-1] == n) {
            winner = player;
            return winner;
        }
            
        if (row == col) {
            if (++map[n][player-1] == n) {
                winner = player;
                return winner;
            }
        }
        if (row + col == n-1) {
            if (++map[2*n+1][player-1] == n) {
                winner = player;
                return winner;
            }
        }
        return winner;
    }
//     vector<vector<int>> mat;
//     int winner;
// public:
//     /** Initialize your data structure here. */
//     TicTacToe(int n) : mat(n, vector<int>(n,0)), winner(0) {}
//     
//     /** Player {player} makes a move at ({row}, {col}).
//         @param row The row of the board.
//         @param col The column of the board.
//         @param player The player, can be either 1 or 2.
//         @return The current winning condition, can be either:
//                 0: No one wins.
//                 1: Player 1 wins.
//                 2: Player 2 wins. */
//     int move(int row, int col, int player) {
//         // 0 1
//         // 1 2
//         int n = mat.size();
//         if (winner != 0) return winner;
//         mat[row][col] = player;
//         bool win = true;
//         for (int i = 0; i < n; i++) {
//             if (mat[i][col] != player) {
//                 win = false;
//                 break;
//             }
//         }
//         if (win) return player;
//         win = true;
//         for (int j = 0; j < n; j++) {
//             if (mat[row][j] != player) {
//                 win = false;
//                 break;
//             }
//         }
//         if (win) return player;
//         if (row == col) {
//             win = true;
//             for (int k = 0; k < n; k++) {
//                 if (mat[k][k] != player) {
//                     win = false;
//                     break;
//                 }
//             }
//             if (win) return player;
//         }
//         if (row == n-1-col) {
//             win = true;
//             for (int k = 0; k < n; k++) {
//                 if (mat[k][n-1-k] != player) {
//                     win = false;
//                     break;
//                 }
//             }
//             if (win) return player;
//         }
//         return 0;
//     }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */