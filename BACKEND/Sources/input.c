#include "../Headers/input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../UI/Headers/laskaBoard.h"



Names getNames(int gameMode)
{
	int i;

	Names names = malloc(sizeof(char *) * 2);
	char player1[15];
	char player2[15];
	char cpu[] = "CPU";

	for(i = 0; i < 2; i++)
		names[i] = malloc(sizeof(char) * 15);

	printf("Insert Player 1 name: ");
	fgets(player1, 15, stdin);
	printf("\n\nInsert Player 2 name: ");
	fgets(player2, 15, stdin);

	player1[0] = toupper(player1[0]);		/*Prima lettera maiuscola*/
	player2[0] = toupper(player2[0]);

	player1[strlen(player1)-1] = 0;			/*Cancello il carattere \n*/
	player2[strlen(player2)-1] = 0;

	strcpy(names[1], player2);


	strcpy(names[0], player1);
	refreshTerminal();

	return names;
}
int getCoordinates(const char* title, int UICoords[2], PlayableBoard board)
{
	UserInput input;
	char move[5];
	int row;
	char col;

	printf("%s: ", title);
	fgets(move, 4, stdin);

	printf("\nMove: %s", move);
	printf("Length:%ld\n\n", strlen(move));

	if(atoi(&move[0]) != 0)
		printf("'%d' is an integer\n", atoi(&move[0]));

	else
		printf("'%d' is NOT an integer\n", atoi(&move[0]));

	if(isalpha(move[1]))
		printf("'%c' is a char\n\n", move[1]);

	else
		printf("'%c' is NOT a char\n\n", move[1]);

	if((atoi(&move[0]) != 0) && isalpha(move[1]))
	{
		row = atoi(&move[0]);
		col = tolower(move[1]);

		printf("Row: %d\n", row);
		printf("Col: %c\n", col);

		input.row = row;
		input.column = col;
		UserInputToUICoords(input, UICoords);
		return 1;
	}

	else
		return 0;
}
