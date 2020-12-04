#include "main.h"

int main()
{
	int from[2];
	int to[2];
	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	printf("Memory for board successfully allocated\n");

	do
	{
		refreshTerminal();
		printBoard(board, 6);
		getCoordinates("FROM", from);
		if(from[0] < 0)
			break;
		getCoordinates("TO", to);

		if(isValidMove(from, to, board))
			move(board, from, to);

	} while(1);

	freeBoard(board);
	printf("Board successfully freed\n");
}

static void getCoordinates(const char* title, int coords[2])
{
	char temp;
	printf("%s:\n\tColumn: ", title);
	scanf(" %c", &temp);
	coords[1] = temp - 'a';

	printf("\tRow: ");
	scanf("%d", &coords[0]);
}

static void refreshTerminal()
{
  #ifdef __unix__
  system("clear");
  #endif
  #ifdef _WIN32
  system("cls");
  #endif
}
