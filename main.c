#include <stdio.h>

#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/board.h"
#include "BACKEND/Headers/pawn.h"
#include "BACKEND/Headers/validation.h"
#include "BACKEND/Headers/errors.h"
#include "UI/Headers/UI.h"

int main() {
  /*
    PlayableBoard board = newBoard();

    int from[] = {0,0};
    int to[] = {2,2};

    printf("From: (%d, %d)\n", from[0], from[1]);
    printf("To: (%d, %d)\n\n", to[0], to[1]);

    printf("Top: '%c'\n", getTop(to, board));

    if(isValidMove(from, to, board))
        printf("\nValid\n");
    else
        printf("\nNot Valid\n");*/

        PlayableBoard board = newBoard();
        int n;
        if(board == NULL)
          return 1;

        printf("Memory for board successfully allocated\n");

        do
        {
            printf("Insert size (negative number to exit): ");
            scanf("%d", &n);
            if(n < 0)
              break;
            printBoard(board, n);
        } while(1);

        freeBoard(board);
        printf("Board successfully freed\n");
}
