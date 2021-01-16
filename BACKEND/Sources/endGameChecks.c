#include "../Headers/endGameChecks.h"

#include "../Headers/playableBoard.h"
#include "../Headers/tower.h"
#include "../Headers/rules.h"
#include "../../UI/Headers/laskaBoard.h"

static int hasAvailableMoves(PlayableBoard board, int player);
static int canMoveInSurroundingArea(PlayableBoard board, int playerPos[2], int player);
static int hasPawnsLeft(PlayableBoard board, int player);


GameOverCode isGameOver(PlayableBoard board)
{
  int player;

  for(player = 0; player <=1; player++)
    if(!hasAvailableMoves(board, player) || !hasPawnsLeft(board, player))
      return player ? PLAYER_0_WON : PLAYER_1_WON;
}


static int hasAvailableMoves(PlayableBoard board, int player)
{
  int coordinates[2];
  int row, col;

  for(row = 0; row < GRID_SIZE; row++)
    for(col = 0; col < GRID_SIZE; col++)
    {
      if(row % 2 != col % 2)
        continue;

      coordinates[0] = row;
      coordinates[1] = col;

      if(!isYourPawn(coordinates, board, player))
        continue;

      if(canMoveInSurroundingArea(board, coordinates, player))
        return 1;
    }

  return 0;
}

static int canMoveInSurroundingArea(PlayableBoard board, int playerPos[2], int player)
{
  Pawn playerPawn = getTop(UICoordinatesToTower(board, playerPos));
  int verticalDir = player ? -1 : 1;
  int horizontalDir = 1;
  int destinationCoords[2];
  int i, j, offset;

  for(i = 0; i <= 2; i++)
  {
    for(j = 0; j < 2; j++)
    {
      for(offset = 1; offset <= 2; offset++)
      {
        destinationCoords[0] = playerPos[0] + verticalDir * offset;
        destinationCoords[1] = playerPos[1] + horizontalDir * offset;

        if(isValidMove(playerPos, destinationCoords, board, player))
          return 1;
      }
      horizontalDir *= -1;
    }

    if(playerPawn == OFFICER0 || playerPawn == OFFICER1)
      verticalDir *= -1;
    else
      break;
  }

  return 0;
}

static int hasPawnsLeft(PlayableBoard board, int player)
{
  int coordinates[2];
  int row, col;

  for(row = 0; row < GRID_SIZE; row++)
    for(col = 0; col < GRID_SIZE; col++)
    {
      if(row % 2 != col % 2)
        continue;

      coordinates[0] = row;
      coordinates[1] = col;

      if(isYourPawn(coordinates, board, player))
        return 1;
    }

  return 0;
}
