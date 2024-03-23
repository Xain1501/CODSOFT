#include <iostream>

using namespace std;

class TicTacToe
{

    char board[3][3];
    int currentPlayer;

    int validateRowCol(int num)
    {
        while (num < 1 || num > 3) // chk if col and row with in range or not
        {
            cout << "Wrong Row/Column number entered. The valid numbers are 1, 2, and 3: ";
            cin >> num;
        }

        return num;
    }

    int checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            {
                return currentPlayer + 1; // row chk for win
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            {
                return currentPlayer + 1; // col chk for win
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            if (board[1][1] != ' ')
                return currentPlayer + 1;
        } // diagonals chk for win

        return 0;
    }

    int checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    return 0; // chking if no space empty on board
                }
            }
        }
        return 1;
    }

public:
    TicTacToe()
    {
        currentPlayer = 0; // initializing current player to player 1 and assigning x

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) // forming board
            {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard()
    {
        cout << endl
             << endl;
        cout << "     " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << endl
             << " ---------|---------|--------" << endl
             << "     " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << endl
             << " ---------|---------|--------" << endl
             << "     " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << endl;
        cout << endl
             << endl;
    }

    void updateBoard()
    {
        int row, col;

        cout << "Enter the row and column where you want to mark" << endl // prompting user for marking
             << "Enter row (1-3): ";
        cin >> row;
        row = validateRowCol(row); // chl if valid row number entered

        cout << "Enter column (1-3): ";
        cin >> col;
        col = validateRowCol(col); // chk if valid col number entered

        if (board[row - 1][col - 1] == ' ')
        {
            if (currentPlayer == 0)
            {
                board[row - 1][col - 1] = 'X';
            }
            else
            {
                board[row - 1][col - 1] = 'O';
            }
        }
        else
        {
            cout << "This position is already occupied. Please choose an empty position." << endl;
            updateBoard(); // in case user needs to re enter recalling update
        }
    }

    void switchPlayer()
    {
        if (currentPlayer == 0)
        {
            currentPlayer = 1; // switching turns
        }
        else
        {
            currentPlayer = 0;
        }
    }

    int displayResult()
    {
        int result = checkWin();
        if (result != 0)
        {
            cout << endl;
            displayBoard(); // showing final result

            cout << "Player " << result << " with the symbol ";
            if (result == 1)
            {
                cout << "(X)";
            }
            else
            {
                cout << "(O)";
            }
            cout << " has won the game." << endl
                 << endl;
            return result;
        }
        else if (checkDraw()) // chk draw after chk win to make sure the user hasnt won already
        {
            cout << endl;
            displayBoard(); // showing final result
            cout << "It's a DRAW!!" << endl
                 << endl;
            return 3;
        }
        else
        {
            cout << "Game is ongoing" << endl;
            return 0;
        }
    }
};

int main()
{
    char playAgain = 'Y';

    cout << "---------------------------------------------------" << endl
         << "--------Welcome To Zain's Simple Calculator--------" << endl
         << "----------------------------------------------------" << endl;
    // Instructions for the games displayed below
    cout << "Follow the Instructions below to play the game" << endl
         << endl
         << "1.This is a two player Game. " << endl
         << "2. You will be marking spaces in the 3x3 grid in with your symbols and will be alternativly playing the game." << endl
         << "3. The player who marks three spaces in a row ,coloumn or diagonally will win the game. " << endl
         << endl
         << "Enjoyyy!!!" << endl
         << endl
         << endl;
    do
    {

        TicTacToe game;

        while (game.displayResult() == 0) // chking if someone won after every turn
        {
            // single players turn
            game.displayBoard();
            game.updateBoard();
            game.switchPlayer();
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
        {
            cout << "Invalid input. Exiting the game." << endl;
            playAgain = 'N';
        }
    } while (playAgain == 'Y' || playAgain == 'y');

    cout <<endl<<endl
        << "---------------------------------------------------" << endl
         << "--------------------THE END-------------------------" << endl
         << "---------------------------------------------------" << endl;

    return 0;
}
