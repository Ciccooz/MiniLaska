#include "main.h"

int main()
{
  int counter = 0;
	int UIFrom[2];
	int UITo[2];
	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	printf("Memory for board successfully allocated\n");

	do
	{
		refreshTerminal();
		printBoard(board, 6);

    do
    {
      getCoordinates("FROM", UIFrom);
      getCoordinates("TO", UITo);
    } while(!isValidMove(UIFrom, UITo, board));

		move(board, UIFrom, UITo);
    counter++;

	} while(counter < 5);

	freeBoard(board);
	printf("Board successfully freed\n");
}

static void getCoordinates(const char* title, int UICoords[2])
{
	UserInput input;
	printf("%s:\n\tColumn: ", title);
	scanf(" %c", &input.column);

	printf("\tRow: ");
	scanf("%d", &input.row);

  UserInputToUICoords(input, UICoords);
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
