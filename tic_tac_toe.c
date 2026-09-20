#include <stdio.h>

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard(void) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(void) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

int checkDraw(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;

    return 1;
}

void makeMove(char player) {
    int choice;

    while (1) {
        printf("\nPlayer %c, enter position (1-9): ", player);

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Enter a number from 1 to 9.\n");
            continue;
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid position. Enter 1 to 9.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already occupied. Try again.\n");
        } else {
            board[row][col] = player;
            break;
        }
    }
}

int main(void) {
    char player = 'X';

    printf("=================================\n");
    printf("        TIC-TAC-TOE GAME\n");
    printf("=================================\n");

    for (int turn = 0; turn < 9; turn++) {
        displayBoard();
        makeMove(player);

        if (checkWin()) {
            displayBoard();
            printf("\nPlayer %c wins!\n", player);
            return 0;
        }

        if (checkDraw()) {
            displayBoard();
            printf("\nGame draw!\n");
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
