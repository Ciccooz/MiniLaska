#pragma once

#include "../../UI/Headers/UIBoard.h"

#define OUT_OF_BOUNDS           0x01
#define NOT_PLAYABLE_CELL       0x02
#define NOT_DIAGONAL            0x04
#define CANT_GO_UP              0x08
#define CANT_GO_DOWN            0x10
#define NOT_MOVING              0x20
#define MOVING_TOO_MUCH         0x40
#define CANT_CONQUER            0x80
#define TOP_NOT_NULL            0x100


/*Controlla quali errori possono essere verificati nel caso in cui si tenti di eseguire una mossa
Se si verifica un errore, si porta un bit della variabile char a 1
Infine la variabile viene restituita...........................................................*/
int errorFill(int from[2], int to[2], PlayableBoard board);

/*Controlla bit a bit una variabile char precedentemente returnata
Se il bit è a 1 si è verificato l'errore, altrimenti è 0.......................................*/
void promptErrors(int errors);
