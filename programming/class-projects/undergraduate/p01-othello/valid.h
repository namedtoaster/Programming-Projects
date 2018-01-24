// ********************************************************************************
// This function checks to see if the space being checked is a space and everything
// going from it, all the way to the next piece of its color, is the opposite color.
// 
// Eg. If we were to check a piece that is 2 pieces south of a black piece, we need
// to make sure that it's a space and everything leading from it to the black piece
// is white:
// 
//		@	< step 3. make sure that's black piece
//		O	< step 2. make sure that's a white piece
//		' ' < step 1. make sure that's a space
// 
// ********************************************************************************

// This function will determine if the move made by the player is a valid option
bool is_valid_option(int col, int row, int valid_row[], int valid_col[], int valid_len)
{
	bool valid = false;
	
	// Go through the array 'valid_row[]' and 'valid_col[]' to see if the move is within the allowed values
	for (int i = 0; i < valid_len; i++)
	{
		if (valid_row[i] == row && valid_col[i] == col)
			valid = true;
	}
	
	return valid;
}


bool is_valid_position_at_in_NORTH_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row; r0 > -1; r0--)
		{
			if (r0 == row)
			{
				if (b[r0][col] == ' ')
					continue;
			}
			else if (r0 < row)
			{
				if (b[r0][col] == WHITE_PIECE)
					continue;
				else if (b[r0][col] == ' ')
					return false;
				else if (b[r0][col] == BLACK_PIECE
					&& r0 == row - 1)
					return false;
				else if (r0 != row - 1 && b[r0][col] == BLACK_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row; r0 > -1; r0--)
		{
			if (r0 == row)
			{
				if (b[r0][col] == ' ')
					continue;
			}
			else if (r0 < row)
			{
				if (b[r0][col] == BLACK_PIECE)
					continue;
				else if (b[r0][col] == ' ')
					return false;
				else if (b[r0][col] == WHITE_PIECE
					&& r0 == row - 1)
					return false;
				else if (r0 != row - 1 && b[r0][col] == WHITE_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_SOUTH_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row; r0 < BOARD_SIZE; r0++)
		{
			if (r0 == row)
			{
				if (b[r0][col] == ' ')
					continue;
			}
			else if (r0 > row)
			{
				if (b[r0][col] == WHITE_PIECE)
					continue;
				else if (b[r0][col] == ' ')
					return false;
				else if (b[r0][col] == BLACK_PIECE
					&& r0 == row + 1)
					return false;
				else if (r0 != row + 1 && b[r0][col] == BLACK_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row; r0 < BOARD_SIZE; r0++)
		{
			if (r0 == row)
			{
				if (b[r0][col] == ' ')
					continue;
			}
			else if (r0 > row)
			{
				if (b[r0][col] == BLACK_PIECE)
					continue;
				else if (b[r0][col] == ' ')
					return false;
				else if (b[r0][col] == WHITE_PIECE
					&& r0 == row + 1)
					return false;
				else if (r0 != row + 1 && b[r0][col] == WHITE_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_EAST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int c0 = col; c0 < BOARD_SIZE; c0++)
		{
			if ( c0== col)
			{
				if (b[row][c0] == ' ')
					continue;
			}
			else if (c0 > col)
			{
				if (b[row][c0] == WHITE_PIECE)
					continue;
				else if (b[row][c0] == ' ')
					return false;
				else if (b[row][c0] == BLACK_PIECE
					&& c0 == col + 1)
					return false;
				else if (c0 != col + 1 && b[row][c0] == BLACK_PIECE)
					return true;
			}
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int c0 = col; c0 < BOARD_SIZE; c0++)
		{
			if (c0 == col)
			{
				if (b[row][c0] == ' ')
					continue;
			}
			else if (c0 > col)
			{
				if (b[row][c0] == BLACK_PIECE)
					continue;
				else if (b[row][c0] == ' ')
					return false;
				else if (b[row][c0] == WHITE_PIECE
					&& c0 == col + 1)
					return false;
				else if (c0 != col + 1 && b[row][c0] == WHITE_PIECE)
					return true;
			}
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_WEST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int c0 = col; c0 > -1; c0--)
		{
			if (c0 == col)
			{
				if (b[row][c0] == ' ')
					continue;
			}
			else if (c0 < col)
			{
				if (b[row][c0] == WHITE_PIECE)
					continue;
				else if (b[row][c0] == ' ')
					return false;
				else if (b[row][c0] == BLACK_PIECE
					&& c0 == col - 1)
					return false;
				else if (c0 != col - 1 && b[row][c0] == BLACK_PIECE)
					return true;
			}
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int c0 = col; c0 > -1; c0--)
		{
			if (c0 == col)
			{
				if (b[row][c0] == ' ')
					continue;
			}
			else if (c0 < col)
			{
				if (b[row][c0] == BLACK_PIECE)
					continue;
				else if (b[row][c0] == ' ')
					return false;
				else if (b[row][c0] == WHITE_PIECE
					&& c0 == col - 1)
					return false;
				else if (c0 != col - 1 && b[row][c0] == WHITE_PIECE)
					return true;
			}
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_NORTH_EAST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (row < 2) 
			return false;
		if (b[row][col] != ' ')
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row - 1, c0 = col + 1; r0 > -1 && c0 < BOARD_SIZE; r0--, c0++)
		{
			// If it is a white piece and it's the second piece or greater
			if (b[r0][c0] == BLACK_PIECE
				&& !(r0 == row - 1 && c0 == col + 1)
				)
				return true;
			else if (b[r0][c0] == WHITE_PIECE && r0 >= row - 1 && c0 >= col + 1)
				continue;
			else if (b[r0][c0] == ' ')
				return false;
			else if (b[r0][c0] == BLACK_PIECE
				&& (r0 == row - 1 && c0 == col + 1))
				return false;
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;
		// Otherwise scan upwards ...
		for (int r0 = row, c0 = col; r0 > -1 && c0 < BOARD_SIZE; r0--, c0++)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 < row && c0 > col)
			{
				if (b[r0][c0] == BLACK_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == WHITE_PIECE
					&& r0 == row - 1 && c0 == col + 1)
					return false;
				else if (r0 != row - 1 && c0 != col + 1 && b[r0][c0] == WHITE_PIECE)
					return true;
			}
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_SOUTH_EAST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 < BOARD_SIZE && c0 < BOARD_SIZE; r0++, c0++)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 > row && c0 > col)
			{
				if (b[r0][c0] == WHITE_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& (r0 == row + 1 && c0 == col + 1))
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& !(r0 == row + 1 && c0 == col + 1)
					) 
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 < BOARD_SIZE && c0 < BOARD_SIZE; r0++, c0++)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 > row && c0 > col)
			{
				if (b[r0][c0] == BLACK_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == WHITE_PIECE
					&& r0 == row + 1 && c0 == col + 1)
					return false;
				else if (r0 != row + 1 && c0 != col + 1 && b[r0][c0] == WHITE_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_SOUTH_WEST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 < BOARD_SIZE && c0 > -1; r0++, c0--)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 > row && c0 < col)
			{
				if (b[r0][c0] == WHITE_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& (r0 == row + 1 && c0 == col - 1))
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& !(r0 == row + 1 && c0 == col - 1)
					) 
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 < BOARD_SIZE && c0 > -1; r0++, c0--)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 > row && c0 < col)
			{
				if (b[r0][c0] == BLACK_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == WHITE_PIECE
					&& r0 == row + 1 && c0 == col - 1)
					return false;
				else if (r0 != row + 1 && c0 != col - 1 && b[r0][c0] == WHITE_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}


bool is_valid_position_at_in_NORTH_WEST_direction(int turn, Board b, int row, int col)
{
	// If it's black's turn
	if (turn == BLACK)
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 > -1 && c0 > -1; r0--, c0--)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
					continue;
			}
			else if (r0 < row && c0 < col)
			{
				if (b[r0][c0] == WHITE_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& (r0 == row - 1 && c0 == col - 1))
					return false;
				else if (b[r0][c0] == BLACK_PIECE
					&& !(r0 == row - 1 && c0 == col - 1)
					) 
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
	// If it's white's turn
	else
	{
		// *****************************************************************************
		// First check that b[row][col] is a space. If it's not, then it's not available
		// therefore return false.
		// *****************************************************************************
		if (b[row][col] != ' ') 
			return false;

		// Otherwise scan upwards ...
		
		for (int r0 = row, c0 = col; r0 > -1 && c0 > -1; r0--, c0--)
		{
			if (r0 == row && c0 == col)
			{
				if (b[r0][c0] == ' ')
				{
					continue;
				}
			}
			else if (r0 < row && c0 < col)
			{
				if (b[r0][c0] == BLACK_PIECE)
					continue;
				else if (b[r0][c0] == ' ')
					return false;
				else if (b[r0][c0] == WHITE_PIECE
					&& r0 == row - 1 && c0 == col - 1)
					return false;
				else if (r0 != row - 1 && c0 != col - 1 && b[r0][c0] == WHITE_PIECE)
					return true;
			}
			
		}
		// If the loop is done and nothing has been returned, the move is not valid
		return false;
	}
}

// **************************************************************************
// Check each position to see if it is valid. It is valid if, in at least one
// direction it can be put in a spot (that spot must be a space) and from
// that space to where the function starts checking there are pieces of the 
// opposite color
// **************************************************************************
void get_valid_positions(int turn, Board b, int valid_row[], int valid_col[], int & valid_len)
{
	
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			if (is_valid_position_at_in_NORTH_direction(turn, b, row, col)
				|| is_valid_position_at_in_EAST_direction(turn, b, row, col)
				|| is_valid_position_at_in_SOUTH_direction(turn, b, row, col)
				|| is_valid_position_at_in_WEST_direction(turn, b, row, col)
				|| is_valid_position_at_in_NORTH_EAST_direction(turn, b, row, col)
				|| is_valid_position_at_in_SOUTH_EAST_direction(turn, b, row, col)
				|| is_valid_position_at_in_SOUTH_WEST_direction(turn, b, row, col)
				|| is_valid_position_at_in_NORTH_WEST_direction(turn, b, row, col))
			{
				valid_row[valid_len] = row;
				valid_col[valid_len] = col;
				valid_len++;
			}
		}	
	}
}