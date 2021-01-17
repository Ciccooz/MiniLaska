#include "../Headers/playableBoard.h"

#include <stdlib.h>
#include <string.h>
#include "../Headers/rules.h"
#include "../Headers/tower.h"

/**
*@brief 		Alloca dinamicamente la memoria del campo da gioco
*@details 		Prima alloca l'array che conterrà le righe della griglia,
*				poi alloca le righe della griglia utilizzando dimesioni
*				diverse, ottenute tramite il metodo getRowSize().
*				Nel caso in cui una delle allocazioni non vada a buon fine,
*				chiama il metodo freeBoard().
*
*@note			Abbiamo deciso di allocare array di dimensioni diverse per
*				risparmiare spazio, dato che molte celle non vengono
*				utilizzate.
**/
static PlayableBoard allocBoard();

/**
*@brief 		Posiziona le pedine sulla griglia
*@details 		Per prima cosa riempe la griglia di #NULL_PAWN. Poi
*				nella prima metà della griglia posiziona le pedine #SOLDIER0 e
*				nella seconda metà #SOLDIER1, la riga in mezzo non viene riempita.
*				Il numero di pedine posizionate in ogni riga dipende dal valore
*				restituito da getRowSize().
*
*@param grid	Griglia nella quale posizionare le pedine
**/
static void spawnPawns(PlayableBoard grid);


PlayableBoard newBoard()
{
   PlayableBoard board = allocBoard();
   if(board == NULL)
      return NULL;

   spawnPawns(board);
   return board;
}

int getRowSize(int row)
{
   if(row % 2)
      return GRID_SIZE / 2;

   return (GRID_SIZE / 2) + 1;
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
            board[row][col][0] = SOLDIER0;
         else if (row >= 4)
            board[row][col][0] = SOLDIER1;
      }
   }
}