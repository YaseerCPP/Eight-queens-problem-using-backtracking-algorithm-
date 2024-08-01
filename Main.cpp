#include <iostream>
#include <vector>

#define N 8

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        std::cout << std::endl;
    }
}

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col) {
    // Check the column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(std::vector<std::vector<int>>& board, int row) {
    if (row == N) {
        return true;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1)) {
                return true;
            }

            board[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        std::cout << "No solution exists" << std::endl;
    }

    return 0;
}
