// **********************************
// This function prints the rules out
// **********************************
void help()
{
	std::cout << "\nThe official rules can be found at" << std::endl
			  << "http://en.wikipedia.org/wiki/Reversi" << std::endl
			  << "\nThe Othello board is set up is the following manner" << std::endl
			  << "\n  ABCDEFGH" << std::endl
			  << " +--------+" << std::endl
			  << "1|        |1" << std::endl
			  << "2|        |2" << std::endl
			  << "3|        |3" << std::endl
			  << "4|   " << WHITE_PIECE << BLACK_PIECE << "   |4" << std::endl
			  << "5|   " << BLACK_PIECE << WHITE_PIECE << "   |5" << std::endl
			  << "6|        |6" << std::endl
			  << "7|        |7" << std::endl
			  << "8|        |8" << std::endl
			  << " +--------+" << std::endl
			  << "  ABCDEFGH" << std::endl
			  << "\nBLACK plays X and WHITE plays O. Players take turn in entering" << std::endl
			  << "moves. The first player to enter a move is BLACK. To place an X" << std::endl
			  << "at row 6 and column E, BLACK enters E6. The result of the move" << std::endl
			  << "\n  ABCDEFGH" << std::endl
			  << " +--------+" << std::endl
			  << "1|        |1" << std::endl
			  << "2|        |2" << std::endl
			  << "3|        |3" << std::endl
			  << "4|   " << WHITE_PIECE << BLACK_PIECE << "   |4" << std::endl
			  << "5|   " << BLACK_PIECE << BLACK_PIECE << "   |5" << std::endl
			  << "6|    " << BLACK_PIECE << "   |6" << std::endl
			  << "7|        |7" << std::endl
			  << "8|        |8" << std::endl
			  << " +--------+" << std::endl
			  << "  ABCDEFGH" << std::endl
			  << "\nThe WHITE piece at E5 is now a BLACK piece.\n" << std::endl;
}