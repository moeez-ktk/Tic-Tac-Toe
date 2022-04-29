#include <iostream>
#include <stdlib.h>
using namespace std;

void chooseCharacter(char &P1, char &P2)
{
    cout << "Player 1 choose any character to represent your moves. ";
    cin >> P1;
    cout << "Player 2 choose any character to represent your moves. ";
    cin >> P2;
}

void gameCheck(char arr[][3], char &win, char &P)
{
    if ((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && arr[0][0] != '-') // check diagnol
    {
        win = P;
    }
    else if ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][1]) && arr[0][0] != '-') // check diagnol
    {
        win = P;
    }
    else if ((arr[0][0] == arr[1][0]) && (arr[0][0] == arr[2][0]) && arr[0][0] != '-') // check 1st column
    {
        win = P;
    }
    else if ((arr[0][0] == arr[0][1]) && (arr[0][0] == arr[0][2]) && arr[0][0] != '-') // check 1st row
    {
        win = P;
    }
    else if ((arr[0][1] == arr[1][1]) && (arr[0][1] == arr[2][1]) && arr[0][1] != '-') // check 2nd column
    {
        win = P;
    }
    else if ((arr[1][0] == arr[1][1]) && (arr[1][0] == arr[1][2]) && arr[1][0] != '-') // check 2nd row
    {
        win = P;
    }
    else if ((arr[0][2] == arr[1][2]) && (arr[0][2] == arr[2][2]) && arr[0][2] != '-') // check 3rd column
    {
        win = P;
    }
    else if ((arr[2][0] == arr[2][1]) && (arr[2][0] == arr[2][2]) && arr[2][0] != '-') // check 3rd row
    {
        win = P;
    }
}

void checkMove(bool &check, int row, int col, char arr[][3])
{
    if (arr[row][col] != '-')
    {
        check = 0;
        cout << "Enter a valid row and column number." << endl;
    }
    else
        check = 1;
}

void putMove(char arr[][3], int row, int col, char put)
{
    arr[row][col] = put;
}

void displayGame(char arr[][3])
{
    system("CLS");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
}

void gameLogic(char arr[][3])
{
    char P1, P2, win = '-';
    bool check;
    chooseCharacter(P1, P2);
    int col, row;
    // PLAYER 1 TURN
    while (win == '-')
    {
        displayGame(arr);
        // PLAYER 1 TURN
        do
        {
            cout << "Player 1's Turn." << endl;
            cout << "Enter the row number: ";
            cin >> row;
            cout << "Enter the column number: ";
            cin >> col;
            checkMove(check, row - 1, col - 1, arr);
        } while (check == 0);
        putMove(arr, row - 1, col - 1, P1);
        gameCheck(arr, win, P1);
        if (win == P1)
        {
            displayGame(arr);
            cout << "Player 1 Wins!" << endl;
            break;
        }
        displayGame(arr);

        // PLAYER 2 TURN
        do
        {
            cout << "Player 2's Turn." << endl;
            cout << "Enter the row number: ";
            cin >> row;
            cout << "Enter the column number: ";
            cin >> col;
            checkMove(check, row - 1, col - 1, arr);
        } while (check == 0);
        putMove(arr, row - 1, col - 1, P2);
        gameCheck(arr, win, P2);
        if (win == P2)
        {
            displayGame(arr);
            cout << "Player 2 Wins!" << endl;
            break;
        }
        system("CLS");
    }
}

int main()
{
    char arr[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j] = '-';

    gameLogic(arr);

    return 0;
}
