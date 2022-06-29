// A demonstration of 2D arrays using tic tac toe.
// W17A, June 2022

#include <stdio.h>

#define SIZE 5
#define TRUE 1
#define FALSE 0

int did_player_win(char player, char board[SIZE][SIZE]);
int check_row(char player, char board[SIZE][SIZE]);
int check_column(char player, char board[SIZE][SIZE]);
int check_diagonal(char player, char board[SIZE][SIZE]);
int check_off_diagonal(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', 'X', ' '},
        {' ', 'O', 'X', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Determines whether 'player' won; that is, the board has
// a complete row, column or diagonal filled with the given
// 'player' character
// Inputs
// - player: either 'X' or 'O'
// - board: a 2D array, each entry either 'X', 'O' or ' '
// Returns 1 if 'player' won and 0 otherwise
int did_player_win(char player, char board[SIZE][SIZE]) {
    return check_row(player, board) || check_column(player, board) 
        || check_diagonal(player, board) || check_off_diagonal(player, board);
}

// Check if a consecutive row has the 'player' character
int check_row(char player, char board[SIZE][SIZE]) {
    // For each row, 
    int row = 0;
    while (row < SIZE) {
        // count the number of 'player' characters
        int count = 0;
        int col = 0;
        while (col < SIZE) {
            if (player == board[row][col]) {
                count++;
            }
            col++;
        }
        if (count == SIZE) {
            return TRUE;
        }
        row++;
    }
    // Otherwise return FALSE
    return FALSE;
}

// Check if a consecutive column has the 'player' character
int check_column(char player, char board[SIZE][SIZE]) {
    // For each col, 
    int col = 0;
    while (col < SIZE) {
        // count the number of 'player' characters
        int count = 0;
        int row = 0;
        while (row < SIZE) {
            if (player == board[row][col]) {
                count++;
            }
            row++;
        }
        if (count == SIZE) {
            return TRUE;
        }
        col++;
    }
    // Otherwise return FALSE
    return FALSE;
}

// Check if the diagonal is filled with the 'player' character
int check_diagonal(char player, char board[SIZE][SIZE]) {
    int count = 0;
    int row = 0;
    while (row < SIZE) {
        if (board[row][row] == player) {
            count++;
        }
        row++;
    }
    if (count == SIZE) {
        return TRUE;
    }
    return FALSE;
}

// Check if the off diagonal is filled with the 'player' character 
int check_off_diagonal(char player, char board[SIZE][SIZE]) {
    int count = 0;
    int row = 0;
    while (row < SIZE) {
        if (board[row][SIZE - 1 - row] == player) {
            count++;
        }
        row++;
    }
    if (count == SIZE) {
        return TRUE;
    }
    return FALSE;    
}