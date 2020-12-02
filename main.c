#include <stdio.h>

#include "Headers\\rules.h"
#include "Headers\\board.h"
#include "Headers\\pawn.h"
#include "Headers\\validation.h"
#include "Headers\\errors.h"

int main() {
    PlayableBoard board = newBoard();

    int from[] = {0,0};
    int to[] = {2,2};

    printf("From: (%d, %d)\n", from[0], from[1]);
    printf("To: (%d, %d)\n\n", to[0], to[1]);

    printf("Top: '%c'\n", getTop(to, board));

    if(isValidMove(from, to, board))
        printf("\nValid\n");
    else
        printf("\nNot Valid\n");
}