#include "..\\Headers\\grid.h"

PlayableBoard newBoard()
{
   PlayableBoard board = allocBoard();
   spawnPawns(board);
   return board;
}

PlayableBoard allocBoard()
{
   PlayableBoard board = (PlayableBoard) malloc(PLAYABLE_CELLS * sizeof(Tower));
   int i;
   for(i = 0; i < PLAYABLE_CELLS; i++)
      board[i] = (Tower) malloc(TOWER_HEIGHT * sizeof(Pawn));
   return board;
}

void spawnPawns(PlayableBoard board)
{
   int i;
   for(i = 0; i < PLAYABLE_CELLS; i++)
   {
      memset(board[i], NULL_PAWN, TOWER_HEIGHT * sizeof(char));
      if(i < 11)
         board[i][0] = SOLDIER1;
      else if (i > 13)
         board[i][0] = SOLDIER2;
   }
}

Tower towerAt(PlayableBoard board, int coords[2])
{
   int index = ((coords[0] / 2) * 7) + (coords[1] / 2);

   if(coords[0] % 2)
      index += 4;

   return board[index];
}

void freeBoard(PlayableBoard board)
{
   int i;
   for(i = 0; i < PLAYABLE_CELLS; i++)
      free(board[i]);

   free(board);
}
