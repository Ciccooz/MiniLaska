#include "rules.h"
#include <math.h>


/*Esegue tutti i controlli che seguono..............................*/
int isValidMove(int from[], int to[]);

/*Controlla che le coordinate siano interne al grid.................*/
int coordinatesWithinBounds(int from[], int to[]);

/*Controlla che la posizione di partenza sia una posizione giocabile*/
int movesFromPlayableCell(int from[]);

/*
Controlla che la pedina si sia spostata esattamente di una posizione
Se è rimasta ferma la mossa non è considerata valida
Entrambe le coordinate devono essere variate perchè sono permessi solo movimenti in diagonale
*/
int isSingleMove(int from[], int to[]);
