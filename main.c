#include "main.h"

#include <stdio.h>
#include "BACKEND/Headers/input.h"
#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/errors.h"
#include "BACKEND/Headers/tower.h"
#include "BACKEND/Headers/playableBoard.h"
#include "BACKEND/Headers/endGameChecks.h"


#include "UI/Headers/laskaBoard.h"

int main()
{
  int counter = 0;
	Names names = getNames();
  GameOverCode gameOver;
  int errorsOccurred = 0;

	int playerTurn = 0;
	int UIFrom[2];
	int UITo[2];

	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	do
  {
    printBoard(board);
    do
    {
      printf("\n%s's TURN (%c)\n", names[playerTurn], playerTurn ? OFFICER1 : OFFICER0);
      promptErrors(errorsOccurred);
      getCoordinates("\nFROM", UIFrom, board);
      getCoordinates("\nTO", UITo, board);
    } while(errorsOccurred = invalidMove(UIFrom, UITo, board, playerTurn));

    move(board, UIFrom, UITo);
    refreshTerminal();
    printf("\n%s moved from (%d, %c) to (%d, %c)\n", names[playerTurn], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
    playerTurn= !playerTurn;
	}while(!(gameOver = isGameOver(board)));

  printf("%s won!",  names[gameOver - 1]);

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
