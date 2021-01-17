#include "../Headers/input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../UI/Headers/laskaBoard.h"

Names getNames()
{
	int i;

	Names names = malloc(sizeof(char *) * 2);
	char player1[15];
	char player2[15];

	for(i = 0; i < 2; i++)
		names[i] = malloc(sizeof(char) * 15);

	printf("Insert Player 1 name: ");
	fgets(player1, 15, stdin);
	printf("\nInsert Player 2 name: ");
	fgets(player2, 15, stdin);

	player1[0] = toupper(player1[0]);		/*Prima lettera maiuscola*/
	player2[0] = toupper(player2[0]);

	player1[strlen(player1)-1] = 0;			/*Cancello il carattere \n*/
	player2[strlen(player2)-1] = 0;

	strcpy(names[0], player1);
	strcpy(names[1], player2);

	return names;
}

void freeNames(Names names)
{
  int i;
  for(i = 0; i < 2; i++)
    free(names[i]);
  free(names);
}

int getCoordinates(const char* title, int UICoords[2], PlayableBoard board)
{
	UserInput input;
	char move[5];
	int row;
	char col;

	printf("%s: ", title);
	fgets(move, 4, stdin);
	
	row = atoi(&move[0]);
	col = tolower(move[1]);

	if((atoi(&move[0]) != 0) && isalpha(move[1]))
	{
		input.row = row;
		input.column = tolower(col);
		UserInputToUICoords(input, UICoords);
		return 1;
	}

	else
		return 0;
}