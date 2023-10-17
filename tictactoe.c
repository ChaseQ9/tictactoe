#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void printBoard(); // Done
void resetBoard(); // Done
char checkWinner(); // Done
int checkFree(); // Done
void playerMove(); // Done
void computerMove(); // Done
void printWinner(char winner); // Done 

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
char winner = ' ';

int main(void) {
    resetBoard();

    while (winner == ' ' && checkFree() != 0) {
        printBoard();
        playerMove();
        winner = checkWinner();
        
        if (winner != ' ' || checkFree() == 0) {
            break;
        } 
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFree() == 0) {
            break;
        } 
    }
    printBoard();
    printWinner(winner);

}
// Print out the game board
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}
// Clear out the game board
void resetBoard() {
    system("clear");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int checkFree() {
    int freeSpaces = 9;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
// Allow player to make a move
void playerMove() {
    int row;
    int col; 
    printf("Please enter row you would like to use: ");
    scanf("%d", &row);
    printf("Please enter column you would like to use: ");
    scanf("%d", &col);
    if (row <= 0 || row > 3 || board[row - 1][col - 1] != ' ') {
        printf("Invalid row choice\n");
    }
    if (col <= 0 || col > 3 || board[row - 1][col - 1] != ' ') {
        printf("Invalid column choice\n");
    }
    row -= 1;
    col -= 1;
    board[row][col] = PLAYER;
}
// Simulate a computer move
void computerMove() {
    srand(time(0));
    int random;
    int random2;

    if (checkFree() > 0) {
        do {
            random = rand() % 3;
            random2 = rand() % 3;
        } while (board[random][random2] != ' ');
        board[random][random2] = COMPUTER;
    } else {
        printWinner(' ');
    }
    
}
// Check for a winner in the game
char checkWinner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }

    }
    // check cols
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
        
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}
// Print out who wins (Player, Computer, or tie)
void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN\n");
    }
    else if (winner == COMPUTER) {
        printf("YOU LOSE\n");
    } else {
        printf("ITS A TIE\n");
    }
}