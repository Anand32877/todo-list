/*Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other*/
#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Check columns
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Check main diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Check secondary diagonal

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // There is an empty space
        }
    }
    return true; // The board is full
}

// Function to play Tic-Tac-Toe
void playTicTacToe() {  
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Get the player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the board is full (a tie)
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playTicTacToe();
    return 0;
}
