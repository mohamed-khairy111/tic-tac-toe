#include <iostream>
#include <time.h>

using namespace std;

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';
int winningStates[8][3][2] = {{{0, 0}, {0, 1}, {0, 2}},
                              {{1, 0}, {1, 1}, {1, 2}},
                              {{2, 0}, {2, 1}, {2, 2}},
                              {{0, 0}, {1, 0}, {2, 0}},
                              {{0, 1}, {1, 1}, {2, 1}},
                              {{0, 2}, {1, 2}, {2, 2}},
                              {{0, 0}, {1, 1}, {2, 2}},
                              {{0, 2}, {1, 1}, {2, 0}}};

void Initialise(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void Display(char board[3][3]) // board is read-only in Display
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void SetValue(char board[3][3], int row, int col, char symbol)
{
    board[row][col] = symbol;
}

bool IsFree(char board[3][3], int row, int col) // board is read-only in IsFree
{
    return board[row][col] == '-';
}

bool HasWon(char board[3][3], char symbol) // board is read-only in HasWon
{
    for (int m = 0; m <= 7; m++)
    {
        bool match = true;
        for (int s = 0; s <= 2; s++)
        {
            int row = winningStates[m][s][0];
            int col = winningStates[m][s][1];
            if (board[row][col] != symbol)
            {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    char board[3][3];
    bool gameOver = false;
    int row = 0;
    int col = 0;
    char player = PLAYER_1;
    int count = 0;
    Initialise(board);

    while (!gameOver)
    {
        Display(board);
        cout << "Player " << player << ", enter the row number (0-2): ";
        cin >> row;
        cout << "Enter the col number (0-2): ";
        cin >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || !IsFree(board, row, col))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        SetValue(board, row, col, player);
        count++;

        if (HasWon(board, player))
        {
            Display(board);
            cout << "Player " << player << " HAS WON!" << endl;
            gameOver = true;
        }
        else if (count == 9)
        {
            Display(board);
            cout << "\tDRAW!" << endl;
            gameOver = true;
        }
        else
        {
            player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        }

        cout << "________________" << endl;
    }

    return 0;
}
