#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// initialization of constants and board
const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS] = {{'.', '.', '.'},
							 {'.', '.', '.'},
							 {'.', '.', '.'}};

bool game_ending_check()
{
	// initialization of local variable
	int filled_fields = 0;

	if ((board[0][0] == 'X' && board [1][1] == 'X' && board[2][2] == 'X') or (board[2][0] == 'X' && board [1][1] == 'X' && board[0][2] == 'X'))
	{
		cout << "You won!";
		return true;
	}

	for (int i = 0; i < ROWS; ++i)
	{
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
		{
			cout << "You won!";
			return true;
		}
	}

	for (int i = 0; i < COLUMNS; ++i)
	{
    	if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
    	{
			cout << "You won!";
				return true;
		}
	}

	if ((board[0][0] == 'O' && board [1][1] == 'O' && board[2][2] == 'O') or (board[2][0] == 'O' && board [1][1] == 'O' && board[0][2] == 'O'))
	{
		cout << "I won";
		return true;
	}

	for (int i = 0; i < ROWS; ++i)
	{
		if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
		{
			cout << "I won";
			return true;
		}
	}

	for (int i = 0; i < COLUMNS; ++i)
	{
		if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
		{
			cout << "I won";
			return true;
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (board[i][j] != '.')
			{
				filled_fields++;
			}
		}
	}

	if (filled_fields == 9)
	{
		cout << "Draw";
		return true;
	}

	return false;
}

void board_display()
{
	cout << "\t ___\n";

	for (int i = 0; i < ROWS; ++i)
	{
		cout << "\t|";

		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}

		cout << "|" << endl;
	}

	cout << "\t ¯¯¯\n";
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	// declaration and initialization of local variables and array
	int player_move_row;
	int player_move_column;

	int moves[9][2] = {{0, 0}, {0, 1}, {0, 2},
					   {1, 0}, {1, 1}, {1, 2},
					   {2, 0}, {2, 1}, {2, 2}};

	while (true)
	{
		board_display();

		// game ending check
		if (game_ending_check() == true) 
		{
			break;
		}

		// getting player's move
		cout << "Your turn\n";

		cout << "Row number: ";
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
		if (game_ending_check() == true) 
		{
			break;
		}

		// search for a possible move
		while (true)
		{
			int probable_move = rand() % 9;
			
			if (board[moves[probable_move][0]][moves[probable_move][1]] == '.')
			{
				board[moves[probable_move][0]][moves[probable_move][1]] = 'O';
				break;
			}
		}
	}
}
