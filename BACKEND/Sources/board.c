#include "..\\Headers\\board.h"

static PlayableBoard allocBoard();
static void spawnPawns(PlayableBoard grid);


PlayableBoard newBoard()
{
   PlayableBoard board = allocBoard();
   spawnPawns(board);
   return board;
}

PlayableBoard allocBoard()
{
   PlayableBoard board = (PlayableBoard) malloc(GRID_SIZE * sizeof(Tower*));

   int row, col;
   for(row = 0; row < GRID_SIZE; row++)
   {
      int rowSize = getRowSize(row);

      board[row] = (Tower*) malloc(rowSize * sizeof(Tower));
      for(col = 0; col < rowSize; col++)
         board[row][col] = (Tower) malloc(TOWER_HEIGHT * sizeof(Pawn));
   }

   return board;
}

void spawnPawns(PlayableBoard board)
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
         else if (row >= 4)
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
   for(row = 0; row < GRID_SIZE; row++)
   {
      int rowSize = getRowSize(row);
      for(col = 0; col < rowSize; col++)
         free(board[row][col]);

      free(board[row]);
   }

   free(board);
}
