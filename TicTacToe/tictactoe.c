#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printBoard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool isGameFinished(char board[][3])
{
    // horizontal
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return true;
        }
    }
    
    // vertical
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return true;
        }
    }

    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] != '-')
            return true;
    }
}

int *playRandomMove(char board[][3])
{
    int move[2];
    bool isValidMove = false;

    while(!isValidMove)
    {
        move[0] = rand() % 3;
        move[1] = rand() % 3;

        if(board[move[0]][move[1]] == '-')
        {
            isValidMove = true;
        }
    }

    return move;
}

int *getMoveFromPlayer()
{
    int move[2] = {-1, -1};
    printf("Enter row (0-2): ");
    scanf("%d", &move[0]);
    printf("Enter column (0-2): ");
    scanf("%d", &move[1]);

    if (move[0] < 0 || move[0] > 2 || move[1] < 0 || move[1] > 2)
    {
        printf("Invalid move, try again\n");
        return getMoveFromPlayer();
    }

    return move;
}
void play(char board[][3])
{
    if (isGameFinished(board))
    {
        printBoard(board);
        printf("Game finished\n");
        return;
    }

    printBoard(board);

    int *playerMove = getMoveFromPlayer();
    int row = playerMove[0];
    int col = playerMove[1];

    if (board[row][col] != '-')
    {
        printf("Invalid move, position already filled\n");
        play(board);
    }

    if (board[row][col] == '-') 
    {
        board[row][col] = 'X';
    }

    int *computerMove = playRandomMove(board);
    int comp_row = computerMove[0];
    int comp_col = computerMove[1];

    board[comp_col][comp_row] = '0';

    play(board);

}   

int main()
{
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    play(board);
    return 0;
}
