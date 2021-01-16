#include "../Headers/playableBoard.h"

#include <stdlib.h>
#include <string.h>
#include "../Headers/rules.h"
#include "../Headers/tower.h"

static PlayableBoard allocBoard();
static void spawnPawns(PlayableBoard grid);

/*
Alloca la memoria per il campo da gioco tramite la chiamata ad allocBoard e posiziona le pedine
nella posizione di inizio partita tramite la chiamata a spawnPawns
Restituisce il puntatore base (PlayableBoard) o NULL in caso si verificasse un'eccezione durante
l'allocazione di memoria
*/
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
/*
Libera la memoria allocata per il campo da gioco. Nel caso dovesse trovare un puntatore NULL
procede direttamente con la free del buffer in cui tale puntatore è memorizzato.
*/
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



/*
Alloca dinamicamente la memoria per il campo da gioco (limitato alle caselle giocabili) e
restituisce il puntatore base (PlayableBoard)
Se la calloc non riesce ad allocare memoria la funzione ripulisce tutto ciò che eventualmente
era già stato allocato prima che si verificasse l'eccezione chiamando freeBoard e restituisce
NULL
*/
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
