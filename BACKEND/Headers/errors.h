#pragma once

#include "rules.h"
#include "validation.h"
#include <stdio.h>

#define OUT_OF_BOUNDS           1
#define NOT_PLAYABLE_CELL       2
#define CANT_GO_UP              4
#define CANT_GO_DOWN            8
#define NOT_MOVING              16      
#define MOVING_TOO_MUCH         32      
#define CANT_CONQUER            64
#define TOP_NOT_NULL            128


/*Controlla quali errori possono essere verificati nel caso in cui si tenti di eseguire una mossa
Se si verifica un errore, si porta un bit della variabile char a 1
Infine la variabile viene restituita...........................................................*/
int errorFill(int from[], int to[], PlayableBoard board);

/*Controlla bit a bit una variabile char precedentemente returnata
Se il bit è a 1 si è verificato l'errore, altrimenti è 0.......................................*/
void errorCheck(int errors);