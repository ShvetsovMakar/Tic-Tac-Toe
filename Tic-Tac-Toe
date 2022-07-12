#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] =    {
					                {'.', '.', '.'},
					                {'.', '.', '.'},
					                {'.', '.', '.'}
				       		       };
    int move;
    int o_move[2];
    int x_move[2];
    int filled_fields = 0;
    bool x_won = false;
    bool o_won = false;
    bool move_legal = false;
    while (true)
    {
        move_legal = false;
        filled_fields = 0;
        cout << "            ___\n";
        for (int i = 0; i < ROWS; ++i)
        {
            cout << "           |";
            for (int j = 0; j < COLUMNS; ++j)
		    {
                cout << board[i][j];
		    }

            cout << "|" << endl;
        }
        cout << "            ¯¯¯\n";
        if ((board[0][0] == 'O' && board [1][1] == 'O' && board[2][2] == 'O') or (board[2][0] == 'O' && board [1][1] == 'O' && board[0][2] == 'O'))
        {
            cout << "I won!";
            break;
        }
        for (int i = 0; i < ROWS; ++i)
        {
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            {
                o_won = true;
                break;
            }
        }
        for (int i = 0; i < COLUMNS; ++i)
        {
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            {
                o_won = true;
                break;
            }
        }
        if (o_won == true)
        {
            cout << "I won!";
            break;
        }
        cout << "Your turn";
        cout << "\nRow number: ";
        cin >> x_move[0];
        x_move[0]--;
        cout << "Column number: ";
        cin >> x_move[1];
        x_move[1]--;

        if (board[x_move[0]][x_move[1]] == '.')
        {
           board[x_move[0]][x_move[1]] = 'X';
        }
        else
        {
            cout << "Your move is illegal\n";
            continue;
        }
        cout << "            ___\n";
        for (int i = 0; i < ROWS; ++i)
        {
            cout << "           |";
            for (int j = 0; j < COLUMNS; ++j)
            {
                cout << board[i][j];
            }

            cout << "|" << endl;
        }
        cout << "            ¯¯¯\n";
        if ((board[0][0] == 'X' && board [1][1] == 'X' && board[2][2] == 'X') or (board[2][0] == 'X' && board [1][1] == 'X' && board[0][2] == 'X'))
        {
            cout << "You won!";
            break;
        }
        for (int i = 0; i < ROWS; ++i)
        {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            {
                x_won = true;
                break;
            }
        }
        for (int i = 0; i < COLUMNS; ++i)
        {
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            {
                x_won = true;
                break;
            }
        }
        if (x_won == true)
        {
            cout << "You won!";
            break;
        }
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] != '.')
                {
                    filled_fields += 1;
                }
            }
        }
        if (filled_fields == 9)
        {
            cout << "Draw!";
            break;
        }
        while (!move_legal)
        {
            move = rand() % 9 + 1;

            if (move == 1 || move == 2 || move == 3)
            {
                o_move[0] = 0;
            }
            else if (move == 4 || move == 5 || move == 6)
            {
                o_move[0] = 1;
            }
            else if (move == 7 || move == 8 || move == 9)
            {
                o_move[0] = 2;
            }

            if (move == 1 || move == 4 || move == 7)
            {
                o_move[1] = 0;
            }
            else if (move == 2 || move == 5 || move == 8)
            {
                o_move[1] = 1;
            }
            else if (move == 3 || move == 6 || move == 9)
            {
                o_move[1] = 2;
            }

            if (board[o_move[0]][o_move[1]] == '.')
            {
                board[o_move[0]][o_move[1]] = 'O';
                move_legal = true;
            }
        }
    }
}
