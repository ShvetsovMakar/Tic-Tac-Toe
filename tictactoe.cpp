#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// initialization of constants and board
const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS] = {
				{'.', '.', '.'},
				{'.', '.', '.'},
				{'.', '.', '.'}
			    };

char game_ending_check()
{
    // initialization of local variables
    bool player_won = false;
    bool computer_won = false;
    int filled_fields = 0;

    if ((board[0][0] == 'X' && board [1][1] == 'X' && board[2][2] == 'X') or (board[2][0] == 'X' && board [1][1] == 'X' && board[0][2] == 'X'))
    {
	    return 'l';
    }
	    
    for (int i = 0; i < ROWS; ++i)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            {
                return 'l';
                break;
            }
    }
	    
    for (int i = 0; i < COLUMNS; ++i)
    {
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            {
            	return 'l';
            	break;
            }
    }
    
    if ((board[0][0] == 'O' && board [1][1] == 'O' && board[2][2] == 'O') or (board[2][0] == 'O' && board [1][1] == 'O' && board[0][2] == 'O'))
    {
        return 'w';
    }
	    
    for (int i = 0; i < ROWS; ++i)
    {
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            return 'w';
            break;
        }
    }
	    
    for (int i = 0; i < COLUMNS; ++i)
    {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            return 'w';
            break;
        }
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
        return 'd';
    }
}

void board_display()
{
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
}	

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    // declaration of local variables
    int player_move_row;
    int player_move_column;
    int computer_move_row;
    int computer_move_column;
	
    int probable_move;
	
    while (true)
    {
	board_display();
	
        // game ending check
	if (game_ending_check() == 'l')
	{
	    cout << "You won!";
	    break;
	}
	else if (game_ending_check() == 'd')
	{
            cout << "Draw!";
	    break;
	}
	else if (game_ending_check() == 'w')
	{
	    cout << "I won";
	    break;
	}
	    
        // getting player's move
        cout << "Your turn";
	    
        cout << "\nRow number: ";
        cin >> player_move_row;
        player_move_row--;
	   
        cout << "Column number: ";
        cin >> player_move_column;
        player_move_column--;
	    
        // check player's move for feasibility
        if (board[player_move_row][player_move_column] == '.')
        {
            board[player_move_row][player_move_column] = 'X';
        }
        else
        {
            cout << "Your move is illegal\n";
            continue;
        }
	    
	board_display();
	    
        // game ending check
        if (game_ending_check() == 'l')
        {
            cout << "You won!";
	    break;
	}
    	else if (game_ending_check() == 'd')
	{
            cout << "Draw!";
            break;
	}
        else if (game_ending_check() == 'w')
        {
            cout << "I won";
            break;
        }
	    
        // search for a possible move
        while (true)
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
                break;
            }
        }
    }
}
