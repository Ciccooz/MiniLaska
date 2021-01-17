#include "main.h"

#include <stdio.h>
#include "BACKEND/Headers/input.h"
#include "BACKEND/Headers/errors.h"
#include "BACKEND/Headers/playableBoard.h"
#include "BACKEND/Headers/endGameChecks.h"

/**
*@file  		main.c
*@mainpage      Progetto MiniLaska
* 				Questo progetto consiste nella creazione di una variante del gioco Laska.\n
*				In questa variante, chiamata MiniLaska, ci sono regole diverse, ovvero:\n
*				1. L'altezza massima delle torri è 3\n
*				2. Superata l'altezza massima, la pedina alla base viene rimossa\n
*				3. Non è possibile conquistare più volte in una sola mossa\n
**/

int main()
{
	int counter = 0;
	Names names = getNames();
	GameOverCode gameOver;
	int errorsOccurred = 0;

	int playerTurn = 1;
	int UIFrom[2];
	int UITo[2];

	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	do
	{
		do
		{
		refreshTerminal();
		printBoard(board);
		promptErrors(errorsOccurred);
		printf("\n%s's TURN (%c)\n", names[playerTurn], playerTurn ? OFFICER1 : OFFICER0);
		printf("Input format example: a3\n");
		getCoordinates("\nFROM", UIFrom, board);
		getCoordinates("\nTO", UITo, board);
	} while(errorsOccurred = invalidMove(UIFrom, UITo, board, playerTurn));

	move(board, UIFrom, UITo);
	refreshTerminal();

	playerTurn = !playerTurn;

	}while(!(gameOver = isGameOver(board)));

	printf("%s won!",  names[gameOver - 1]);


	freeNames(names);
	freeBoard(board);
}

void refreshTerminal()
{
	#ifdef __unix__
	system("clear");
	#endif

	#ifdef _WIN32
	system("cls");
	#endif
}