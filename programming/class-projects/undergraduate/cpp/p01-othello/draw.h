// *************************************************
// Function to print board b onto the console window
// *************************************************
void draw(Board b)
{
	std::cout << "  ABCDEFGH" << std::endl;
	std::cout << " +--------+"<< std::endl;

	for	(int row = 0; row < BOARD_SIZE; row++)
	{
		std::cout << row + 1 << '|';
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			std::cout << b[row][col];
		}
		std::cout << '|' << row + 1 << std::endl;
	}
	std::cout << " +--------+" << std::endl;
	std::cout << "  ABCDEFGH" << std::endl;
}