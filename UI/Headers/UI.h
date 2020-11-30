#include "..\\..\\BACKEND\\Headers\\board.h"
#include <stdio.h>
#define UNPLAYABLE_PAWN (char)176
/*
cellSide indica la dimensione della cella (bordi esclusi) in char
cellSide deve essere un multiplo di 3
*/
void printBoard(PlayableBoard board, int cellSide);

void printMessage(char* message);
