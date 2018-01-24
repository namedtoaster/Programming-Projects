// Typedefs
typedef char Board[BOARD_SIZE][BOARD_SIZE];

int black_score = 2;
int white_score = 2;

// Function prototypes
void help();
void play(Board b, int & white_score, int & black_score);
void setup();
void load();
void draw(Board b);

// **********************************
// Function to initialize the board b
// **********************************
void init(Board b)
{
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
			b[row][col] = ' ';
	}

	b[3][3] = WHITE_PIECE;
	b[4][4] = WHITE_PIECE;
	b[3][4] = BLACK_PIECE;
	b[4][3] = BLACK_PIECE;
}