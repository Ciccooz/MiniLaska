#include "../Headers/playableBoard.h"

#include <stdlib.h>
#include <string.h>
#include "../Headers/rules.h"
#include "../Headers/tower.h"
#include "../../UI/Headers/laskaBoard.h"

PlayableBoard newBoard()
{
   PlayableBoard board = allocBoard();
   if(board == NULL)
      return NULL;

   spawnPawns(board);
   return board;
}

static PlayableBoard allocBoard()
{
   int row, col;
   PlayableBoard board = (PlayableBoard) calloc(GRID_SIZE, sizeof(Tower*));
   if(board == NULL)
      return NULL;

   for(row = 0; row < GRID_SIZE; row++)
   {
      int rowSize = getRowSize(row);

      board[row] = (Tower*) calloc(rowSize, sizeof(Tower));
      if(board[row] == NULL)
      {
         freeBoard(board);
         return NULL;
      }

      for(col = 0; col < rowSize; col++)
      {
         board[row][col] = (Tower) calloc(TOWER_HEIGHT, sizeof(Pawn));
         if(board[row][col] == NULL)
         {
            freeBoard(board);
            return NULL;
         }
      }
   }

   return board;
}

static void spawnPawns(PlayableBoard board)
{
   int row, col;
   for(row = 0; row < GRID_SIZE; row++)
   {
		int rowSize = getRowSize(row);
		for(col = 0; col < rowSize; col++)
		{
			memset(board[row][col], NULL_PAWN, TOWER_HEIGHT * sizeof(char));
			if(row <= 2)
				board[row][col][0] = SOLDIER1;
		
			if(row >=4)
				board[row][col][0] = SOLDIER2;
		}
	}
}

int getRowSize(int row)
{
   if(row % 2)
      return 3;

   return 4;
}

void freeBoard(PlayableBoard board)
{
   int row, col;

   if(board == NULL)
      return;

   for(row = 0; row < GRID_SIZE; row++)
   {
      int rowSize;

      if(board[row] == NULL)
         break;

      rowSize = getRowSize(row);
      for(col = 0; col < rowSize; col++)
         free(board[row][col]);

      free(board[row]);
   }

   free(board);
}

Tower getPrevious(int from[2], int to[2], PlayableBoard board)
{
	Tower previous;
	
	int coord[2];
	coord[0] = (from[0] + to[0]) / 2;
	coord[1] = (from[1] + to[1]) / 2;

	previous = UICoordinatesToTower(board, coord);

	return previous;
}
