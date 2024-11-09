#include <iostream>
#include <time.h>

using namespace std;

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';
char board[3][3];

void Insitialise()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void Display()
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

void SetValue(int row, int col, char symbol)
{
    board[row][col] = symbol;
}

bool IsFree(int row, int col)
{
    if (board[row][col] == '-')
        return false;
    else
        return true;
}

int main()
{
    srand(time(NULL));
    bool gameOver = false;
    int row = 0;
    int col = 0;
    char player = PLAYER_1;
    int count = 0;
    Insitialise();

    while (!gameOver)
    {
        row = rand() % 3;
        col = rand() % 3;
        while (!IsFree(row, col))
        {
            SetValue(row, col, player);
            if (player == PLAYER_1)
                player = PLAYER_2;
            else
                player = PLAYER_1;
            count++;
            if (count == 9)
                gameOver = true;
            Display();
            cout << "________________" << endl;
        }
    }

    return 0;
}