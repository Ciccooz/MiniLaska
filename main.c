#include "main.h"

#include <stdio.h>
#include "BACKEND/Headers/input.h"
#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/errors.h"
#include "BACKEND/Headers/tower.h"
#include "BACKEND/Headers/playableBoard.h"

#include "UI/Headers/laskaBoard.h"

int main()
{
  int counter = 0;
	int gameMode = getGameMode();
	Names names = getNames(gameMode);

	int playerTurn = 0;
	int UIFrom[2];
	int UITo[2];
	int fromIsRight;
	int toIsRight;

	int gameOver = 0;

	int errorsOccurred = 0;

	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	printf("Memory for board successfully allocated\n");
	do
  {
    printBoard(board);
    do
    {
      printf("\n%s's TURN (%c)\n", names[playerTurn], playerTurn ? OFFICER1 : OFFICER0);
      promptErrors(errorsOccurred);
      getCoordinates("\nFROM", UIFrom, board);
      getCoordinates("\nTO", UITo, board);
    } while(errorsOccurred = isValidMove(UIFrom, UITo, board, playerTurn));

    move(board, UIFrom, UITo);
    checkPromotion(board, UITo);
    refreshTerminal();
    printf("\n%s moved from (%d, %c) to (%d, %c)\n", names[playerTurn], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
    playerTurn= !playerTurn;
    if(++counter == 4)
      break;
	}while(1);

	freeBoard(board);
	printf("\nBoard successfully freed\n");
}

int hasWon(PlayableBoard board, Names names)
{
	int p0Pawns = countPawns(board, SOLDIER0, OFFICER0);
	int p1Pawns = countPawns(board, SOLDIER1, OFFICER1);

	int p0Moves = countMoves(board, SOLDIER0, OFFICER0);
	int p1Moves = countMoves(board, SOLDIER1, OFFICER1);

	printf("\np0Pawns: %d\n", p0Pawns);
	printf("p1Pawns: %d\n", p1Pawns);

	printf("p0Moves: %d\n", p0Moves);
	printf("p1Moves: %d\n", p1Moves);

	if((p0Pawns == 0) || (p0Moves == 0))
	{
		printf("%s HAS won", names[1]);
		return 1;
	}

	if((p1Pawns == 0) || (p1Moves == 0))
	{
		printf("%s HAS won", names[0]);
		return 1;
	}

	return 0;
}

int countPawns(PlayableBoard board, char soldierTop, char officerTop)
{
	int row, col;
	int counter = 0;

	int coord[2];
	Tower tower;
	char top;

	for(row = 0; row < GRID_SIZE; row++)
	{
		coord[0] = row;

		for(col = 0; col < GRID_SIZE; col++)
		{
			if((row + col) % 2 == 0)
			{
				coord[1] = col;
				tower = UICoordinatesToTower(board, coord);
				top = getTop(tower);

				if((top == soldierTop) || (top == officerTop))
					counter++;
			}
		}
	}

	return counter;
}

int countMoves(PlayableBoard board, char soldierTop, char officerTop)
{
	int row, col;
	int fromBoard[2], toBoard[2];
	int counter = 0;
	Tower fromTower, toTower;
	char fromTop;

	for(row = 0; row < GRID_SIZE; row++)
	{
		fromBoard[0] = row;

		for(col = 0; col < GRID_SIZE; col++)
		{
			if((row + col) % 2 == 0)
			{
				fromBoard[1] = col;
				fromTower = UICoordinatesToTower(board, fromBoard);
				fromTop = getTop(fromTower);

				if(fromTop == soldierTop && soldierTop == SOLDIER1)
				{
					/*CONQUER*/
					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}

					/*SINGLE MOVE*/
					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}

				if(fromTop == officerTop && officerTop == OFFICER1)
				{
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}


					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}

					/*SINGLE MOVE*/
					/*DOWN*/
					{
						toBoard[0] = fromBoard[0] + 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}

					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}

				if(fromTop == soldierTop && soldierTop == SOLDIER1)
				{
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}

					/*SINGLE MOVE*/
					/*DOWN*/
					if(fromBoard[0] + 1 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}

				if(fromTop == officerTop && officerTop == OFFICER0)
				{
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}


					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;

						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}

					/*SINGLE MOVE*/
					/*DOWN*/
					if(fromBoard[0] + 1 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}


					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;

						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}

						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}
			}
		}
	}

	return counter;
}

static void checkPromotion(PlayableBoard board, int UITo[2])
{
	Tower promoted = UICoordinatesToTower(board, UITo);
	Pawn promotedTop = getTop(promoted);

	if((UITo[0] == 6 && promotedTop == SOLDIER1) || (UITo[0] == 0 && promotedTop == SOLDIER1))
		if(promotedTop != OFFICER0 || promotedTop != OFFICER1)
			promote(promoted);
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
