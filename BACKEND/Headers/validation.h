#pragma once

#include <math.h>
#include "errors.h"
#include "rules.h"
#include "board.h"
#include "pawn.h"
#include "../../UI/Headers/UIBoard.h"

/*Esegue tutti i controlli che seguono...........................................*/
int isValidMove(int from[2], int to[2], PlayableBoard board);

/*Controlla che le coordinate siano interne al grid..............................*/
int coordinatesWithinBounds(int from[2], int to[2]);

/*Controlla che la posizione di partenza sia una posizione giocabile.............*/
int movesFromPlayableCell(int from[2]);

/*Controlla che il movimento sia effettuato in diagonale.........................*/
int movesDiagonally(int from[2], int to[2]);

/*Controlla se si vuole spostare la pedina (o la torre) verso l'alto.............*/
int isGoingUp(int from[2], int to[2]);

/*Controlla se si vuole spostare la pedina (o la torre) verso il basso...........*/
int isGoingDown(int from[2], int to[2]);

/*Controlla se la pedina (o la torre) può spostarsi verso l'alto.................*/
int canGoUp(Tower tower);

/*Controlla se la pedina (o la torre) può spostarsi verso il basso...............*/
int canGoDown(Tower tower);

/*Controlla se si cerca di far rimanere ferma la pedina (o la torre).............*/
int isInSamePosition(int from[2], int to[2]);

/*Controlla se si cerca di muovere la pedina (o la torre) di più di due posizioni*/
int isMovingTooMuch(int from[2], int to[2]);

/*Controlla che la pedina si sia spostata esattamente di una posizione--.........*/
int isSingleMove(int from[2], int to[2]);

/*Controlla che la pedina si sia spostata di due posizioni.......................*/
int isDoubleMove(int from[2], int to[2]);

/*Controlla che la cella selezionata sia vuota...................................*/
int topIsNull(Tower tower);

/*Controlla se la cella precedente (in base alla mossa appena fatta)
possa essere conquistata, ovvero deve essere diversa dalla pedina
(o la pedina che controlla la torre) con la quale si intende conquistare
la pedina (o la torre)...........................................................*/
int canConquer(int from[2], int to[2], PlayableBoard board);
