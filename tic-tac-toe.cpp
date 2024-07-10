#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3; // Size of the tic-tac-toe board
char board[SIZE][SIZE]; // The tic-tac-toe board

// Function to initialize the board
void initializeBoard() {
    char cell = '1';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = cell++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    char player = 'X';
    while (true) {
        displayBoard();
        cout << "Player " << player << ", enter the number of the cell where you want to place your mark: ";
        int move;
        cin >> move;

        // Convert move to board indices
        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        // Check if the move is valid
        if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player; // Place the player's mark on the board

            // Check if the player has won
            if (checkWin(player)) {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                break;
            }

            // Check if the board is full
            if (isBoardFull()) {
                displayBoard();
                cout << "The game is a draw!\n";
                break;
            }

            // Switch players
            player = (player == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}
