// *********************************************************************
// *********************************************************************
// **                                                                 **
// **                   MY VERY FIRST GAME PROGRAM!                   **
// **                                                                 **
// **                            OTHELLO                              **
// **                                                                 **
// **                              by:                                **
// **                                                                 **
// **                        David Campbell                           **
// **                                                                 **
// *********************************************************************
// *********************************************************************

#include <iostream>
#include <cstring>
#include "constants.h"
#include "init.h"
#include "valid.h"
#include "help.h"
#include "draw.h"


void swap_the_enemy(int turn, Board b, int row, int col, int & white_score, int & black_score)
{
	if (is_valid_position_at_in_NORTH_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			for (int r0 = row - 1; row >= 0; r0--)
			{
				if (b[r0][col] == WHITE_PIECE)
				{
					b[r0][col] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			for (int r0 = row - 1; row >= 0; r0--)
			{
				if (b[r0][col] == BLACK_PIECE)
				{
					b[r0][col] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	
	if (is_valid_position_at_in_SOUTH_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int r0 = row + 1; row <= BOARD_SIZE; r0++)
			{
				if (b[r0][col] == WHITE_PIECE)
				{
					b[r0][col] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int r0 = row + 1; row <= BOARD_SIZE; r0++)
			{
				if (b[r0][col] == BLACK_PIECE)
				{
					b[r0][col] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_EAST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col + 1; col <= BOARD_SIZE; c0++)
			{
				if (b[row][c0] == WHITE_PIECE)
				{
					b[row][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col + 1; col <= BOARD_SIZE; c0++)
			{
				if (b[row][c0] == BLACK_PIECE)
				{
					b[row][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_WEST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col - 1; col >= 0; c0--)
			{
				if (b[row][c0] == WHITE_PIECE)
				{
					b[row][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col - 1; col >= 0; c0--)
			{
				if (b[row][c0] == BLACK_PIECE)
				{
					b[row][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_NORTH_EAST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col + 1, r0 = row - 1; c0 < BOARD_SIZE && r0 > -1; c0++, r0--)
			{
				if (b[r0][c0] == WHITE_PIECE)
				{
					b[r0][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col + 1, r0 = row - 1; c0 < BOARD_SIZE && r0 > -1; c0++, r0--)
			{
				if (b[r0][c0] == BLACK_PIECE)
				{
					b[r0][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_SOUTH_EAST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col + 1, r0 = row + 1; c0 < BOARD_SIZE && r0 < BOARD_SIZE; c0++, r0++)
			{
				if (b[r0][c0] == WHITE_PIECE)
				{
					b[r0][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col + 1, r0 = row + 1; c0 < BOARD_SIZE && r0 < BOARD_SIZE; c0++, r0++)
			{
				if (b[r0][c0] == BLACK_PIECE)
				{
					b[r0][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_SOUTH_WEST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col - 1, r0 = row + 1; c0 > -1 && r0 < BOARD_SIZE; c0--, r0++)
			{
				if (b[r0][c0] == WHITE_PIECE)
				{
					b[r0][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col - 1, r0 = row + 1; c0 > -1 && r0 < BOARD_SIZE; c0--, r0++)
			{
				if (b[r0][c0] == BLACK_PIECE)
				{
					b[r0][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}
	}
	if (is_valid_position_at_in_NORTH_WEST_direction(turn, b, row, col))
	{
		if (turn == BLACK)
		{
			
			for (int c0 = col - 1, r0 = row - 1; c0 > -1 && r0 > -1; c0--, r0--)
			{
				if (b[r0][c0] == WHITE_PIECE)
				{
					b[r0][c0] = BLACK_PIECE;
					black_score++;
					white_score--;
				}
				else
					break;
			}
		}
		else
		{
			
			for (int c0 = col - 1, r0 = row - 1; c0 > -1 && r0 > -1; c0--, r0--)
			{
				if (b[r0][c0] == BLACK_PIECE)
				{
					b[r0][c0] = WHITE_PIECE;
					black_score--;
					white_score++;
				}
				else
					break;
			}
		}	
	}
	if (turn != BLACK)
	{
		b[row][col] = WHITE_PIECE;
		white_score++;
	}
	else
	{
		b[row][col] = BLACK_PIECE;
		black_score++;
	}
}


void reset_valid_moves(int valid_row[], int valid_col[], int & valid_len)
{
	for (int i = 0; i < valid_len; i++)
	{
		valid_row[i] = 0;
		valid_col[i] = 0;
	}

	valid_len = 0;
}





int main()
{
	Board b;
	
	while (1)
	{
		// **************************************************************
		// Print out the welcome screen and ask what the user wants to do
		// **************************************************************
		std::cout << "Welcome to Super Othello Version 0.1" << std::endl
				  << "by David Campbell" << std::endl
				  << "\n[?] Help" << std::endl
				  << "[P/p] Play a new game" << std::endl
				  << "[L/l] Load a previous game" << std::endl
				  << "[S/s] Setup the board" << std::endl
				  << "[Q/q] Quit" << std::endl
				  << "Enter option: ";
		char option = ' ';
		std::cin >> option;
		std::cout << std::endl;
		
		switch (option)
		{
			case '?': help(); 
				break;
			case 'p': play(b, white_score, black_score);
				break;
			case 'P': play(b, white_score, black_score);
				break;
			// Implement Later -----------
			case 'L': //load();
				{
					std::cout << "TO BE IMPLEMENTED\n\n";
					break;
				}
			case 'l': //load();
				{
					std::cout << "TO BE IMPLEMENTED\n\n";
					break;
				}
			case 'S': //setup();
				{
					std::cout << "TO BE IMPLEMENTED\n\n";
					break;
				}
			case 's': //setup();
				{
					std::cout << "TO BE IMPLEMENTED\n\n";
					break;
				}
			case 'q':
				return 0;
			case 'Q':
				return 0;
		}
	}
	
	return 0;
}
	
// *************************************************************
// Where the actual action takes place. This function finds out
// from the user where it wants to move, and the function will
// determine where to put the piece and how it affects the board
// *************************************************************
void play(Board b, int & white_score, int & black_score)
{
	// ****************************************************************************
	// Initialize the board by setting all values to ' ' (except for middle portion)
	// *****************************************************************************
	init(b);
	// **************
	// Draw the board
	// **************
	draw(b);
	// ***************************************
	// This variable will accept the next move
	// ***************************************
	char move[100] = {' '};
	// ***********************************************************
	// This variable will determine if it is Black or White's turn
	// ***********************************************************
	int turn = 0;
	// ***********************************************************************************
	// These arrays and variable will determine what values of the 'b' array (board array)
	// are valid. The 'valid_row[]' array will store the value of each valid row and the
	// 'valid_col[]' array will store the value of each valid column. 'valid_len' will be
	// the size of the container that holds the valid values
	// ***********************************************************************************
	int valid_row[1000] = {0};
	int valid_col[1000] = {0};
	int valid_len = 0;
	//*****************************************************************************
	// While the move entered does not equal 'q' or 'Q', get input from the players
	// ****************************************************************************
	while (move[0] != 'Q' && move[0] != 'q')
	{
		// Find all of the valid moves for the current player
		reset_valid_moves(valid_row, valid_col, valid_len);
		get_valid_positions(turn, b, valid_row, valid_col, valid_len);
		if (valid_len > 0)
		{
			// Black's turn
			while (turn == BLACK)
			{
				std::cout << "\nBLACK's turn: ";
				std::cin >> move;
				std::cout << std::endl;
				// *************************************
				// col = the first half of value entered
				// row = second half of value entered
				// *************************************
				int col = move[0] - 'A';
				int row = move[1] - '1';

				if (move[0] == 'Q' || move[0] == 'q')
				{
					std::cout << std::endl;
					break;
				}
				//***********************************************************************
				// If the value entered is not on the board, then print "Invalid position
				// and ask for the turn again. (The variable 'invalid' will be true if
				// the position is invalid thus returning to the beginning of the loop.)
				// **********************************************************************
				else if (col < 0 || col > BOARD_SIZE - 1 || row < 0 || row > BOARD_SIZE - 1 || b[row][col] != ' '
				|| !is_valid_option(move[0] - 'A', move[1] - '1', valid_row, valid_col, valid_len))
				{
					std::cout << "Invalid position\n";
				}
				else
				{
					// ***********************************
					// The value entered = black piece (@)
					// ***********************************
					if (is_valid_option(col, row, valid_row, valid_col, valid_len))
					{
						
						// do the swap function to flip enemy
						swap_the_enemy(turn, b, row, col, white_score, black_score);
						
						draw(b);
						std::cout << "\nBLACK score - " << black_score
							<< "\nWHITE score - " << white_score << std::endl;
						turn++;
					}
				}
			}
			// White's turn
			while (turn != BLACK)
			{
				// Reset the valid values
				reset_valid_moves(valid_row, valid_col, valid_len);
				
				// Find all of the valid moves for the current player
				get_valid_positions(turn, b, valid_row, valid_col, valid_len);
				if (valid_len < 1)
					break;
				
				std::cout << "\nWHITE's turn: ";
				std::cin >> move;
				// *************************************
				// col = the first half of value entered
				// row = second half of value entered
				// *************************************
				int col = move[0] - 'A';
				int row = move[1] - '1';
				
				if (move[0] == 'Q' || move[0] == 'q')
				{
					std::cout << std::endl;
					break;
				}
				//***********************************************************************
				// If the value entered is not on the board, then print "Invalid position
				// and ask for the turn again. (The variable 'invalid' will be true if
				// the position is invalid thus returning to the beginning of the loop.)
				// **********************************************************************
				else if (col < 0 || col > BOARD_SIZE - 1 || row < 0 || row > BOARD_SIZE - 1 || b[row][col] != ' '
				|| !is_valid_option(col, row, valid_row, valid_col, valid_len))
				{
					std::cout << "\nInvalid position\n";
				}
				else
				{
					// ***********************************
					// The value entered = white piece (O)
					// ***********************************
					if (is_valid_option(col, row, valid_row, valid_col, valid_len))
					{
						// do the swap function to flip enemy
						swap_the_enemy(turn, b, row, col, white_score, black_score);
						
						std::cout << std::endl;
						draw(b);
						std::cout << "\nBLACK score - " << black_score
							<< "\nWHITE score - " << white_score << std::endl;
						turn--;
					}
				}
			}
		}
		else
		{
			std::cout << "\nThe game is ended." << std::endl
				<< "BLACK - " << black_score << '\n'
				<< "WHITE - " << white_score << '\n';

			if (white_score > black_score) 
				std::cout << "WHITE is the winner.\n\n";
			else 
				std::cout << "BLACK is the winner.\n\n";
			break;
		}
	}
}
