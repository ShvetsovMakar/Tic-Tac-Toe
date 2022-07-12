#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    // declaration and initialization of variables and board
	char board[ROWS][COLUMNS] = {
					{'.', '.', '.'},
					{'.', '.', '.'},
					{'.', '.', '.'}
				    };
    int player_move_row;
    int player_move_column;
    int computer_move_row;
    int computer_move_column;
	
    int probable_move;
	
    int filled_fields = 0;
	
    bool player_won = false;
    bool computer_won = false;			    
    bool move_legal = false;
	
    while (true)
    {
        // обнуляет переменные
        move_legal = false;
        filled_fields = 0;
	    
        // board display
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
        
	// game ending check
        if ((board[0][0] == 'O' && board [1][1] == 'O' && board[2][2] == 'O') or (board[2][0] == 'O' && board [1][1] == 'O' && board[0][2] == 'O'))
        {
            cout << "I won!";
            break;
        }
	    
        for (int i = 0; i < ROWS; ++i)
        {
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            {
                computer_won = true;
                break;
            }
        }
	    
        for (int i = 0; i < COLUMNS; ++i)
        {
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            {
                computer_won = true;
                break;
            }
        }
	    
        if (player_won == true)
        {
            cout << "I won!";
            break;
        }
	    
        // gets player's move
        cout << "Your turn";
	    
        cout << "\nRow number: ";
        cin >> player_move_row;
        player_move_row--;
	   
        cout << "Column number: ";
        cin >> player_move_column;
        player_move_column--;
	    
        // проверяет, возможен ли ход игрока 
        if (board[player_move_row][player_move_column] == '.')
        {
           board[player_move_row][player_move_column] = 'X';
        }
        else
        {
            cout << "Your move is illegal\n";
            continue;
        }
	    
        // board display
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
	    
        // game ending check
        if ((board[0][0] == 'X' && board [1][1] == 'X' && board[2][2] == 'X') or (board[2][0] == 'X' && board [1][1] == 'X' && board[0][2] == 'X'))
        {
            cout << "You won!";
            break;
        }
	    
        for (int i = 0; i < ROWS; ++i)
        {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            {
                player_won = true;
                break;
            }
        }
	    
        for (int i = 0; i < COLUMNS; ++i)
        {
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            {
                player_won = true;
                break;
            }
        }
	    
        if (player_won == true)
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
	    
        // search for a possible move
        while (!move_legal)
        {
            probable_move = rand() % 9 + 1;

            if (probable_move == 1 || probable_move == 2 || probable_move == 3)
            {
                computer_move_row = 0;
            }
            else if (probable_move == 4 || probable_move == 5 || probable_move == 6)
            {
                computer_move_row = 1;
            }
            else if (probable_move == 7 || probable_move == 8 || probable_move == 9)
            {
                computer_move_row = 2;
            }

            if (probable_move == 1 || probable_move == 4 || probable_move == 7)
            {
                computer_move_column = 0;
            }
            else if (probable_move == 2 || probable_move == 5 || probable_move == 8)
            {
                computer_move_column = 1;
            }
            else if (probable_move == 3 || probable_move == 6 || probable_move == 9)
            {
                computer_move_column = 2;
            }

            if (board[computer_move_row][computer_move_column] == '.')
            {
                board[computer_move_row][computer_move_column] = 'O';
                move_legal = true;
            }
        }
    }
}
