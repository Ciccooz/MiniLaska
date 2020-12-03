#include "main.h"

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
            refreshTerminal();
            printBoard(board, n);
        } while(1);

        freeBoard(board);
        printf("Board successfully freed\n");
}

static void refreshTerminal()
{
  #ifdef __unix__
  system("clear");
  #endif
  #ifdef _WIN32
  system("cls");
  #endif
}
