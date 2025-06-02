#include <stdio.h>
#include <String.h>
#include <stdbool.h>
bool exist(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int a) {
    if (a >= strlen(word)) // Base case: all characters matched
        return true;

    // Check boundaries and character match
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || board[i][j] != word[a])
        return false;

    char temp = board[i][j]; // Save current cell
    board[i][j] = '#';       // Mark cell as visited

    // Up
    if (i > 0 && exist(board, boardSize, boardColSize, word, i - 1, j, a + 1)) {
        board[i][j] = temp; // Restore before returning
        return true;
    }

    // Right
    if (j + 1 < boardColSize[i] && exist(board, boardSize, boardColSize, word, i, j + 1, a + 1)) {
        board[i][j] = temp; // Restore before returning
        return true;
    }

    // Down
    if (i + 1 < boardSize && exist(board, boardSize, boardColSize, word, i + 1, j, a + 1)) {
        board[i][j] = temp; // Restore before returning
        return true;
    }

    // Left
    if (j > 0 && exist(board, boardSize, boardColSize, word, i, j - 1, a + 1)) {
        board[i][j] = temp; // Restore before returning
        return true;
    }

    board[i][j] = temp; // Restore cell value during backtracking
    return false; // No path found
}