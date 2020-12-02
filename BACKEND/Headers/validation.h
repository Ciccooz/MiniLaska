#pragma once

#include "rules.h"
#include "errors.h"
#include "pawn.h"
#include <math.h>
#include <stdlib.h>

/*Esegue tutti i controlli che seguono...........................................*/
int isValidMove(int from[], int to[], PlayableBoard board);

/*Controlla che le coordinate siano interne al grid..............................*/
int coordinatesWithinBounds(int from[], int to[]);

/*Controlla che la posizione di partenza sia una posizione giocabile.............*/
int movesFromPlayableCell(int from[]);

/*Controlla se si vuole spostare la pedina (o la torre) verso l'alto.............*/
int isGoingUp(int from[], int to[]);

/*Controlla se si vuole spostare la pedina (o la torre) verso il basso...........*/
int isGoingDown(int from[], int to[]);

/*Controlla se la pedina (o la torre) può spostarsi verso l'alto.................*/
int canGoUp(int from[], int to[], PlayableBoard board);

/*Controlla se la pedina (o la torre) può spostarsi verso il basso...............*/
int canGoDown(int from[], int to[], PlayableBoard board);

/*Controlla se si cerca di far rimanere ferma la pedina (o la torre).............*/
int isInSamePosition(int from[], int to[]);

/*Controlla se si cerca di muovere la pedina (o la torre) di più di due posizioni*/
int isMovingTooMuch(int from[], int to[]);

/*Controlla che la pedina si sia spostata esattamente di una posizione--.........*/
int isSingleMove(int from[], int to[]);

/*Controlla che la pedina si sia spostata di due posizioni.......................*/
int isDoubleMove(int from[], int to[]);

/*Controlla che la cella selezionata sia vuota...................................*/
int topIsNull(int from[], PlayableBoard board);

/*Controlla se la cella precedente (in base alla mossa appena fatta)
possa essere conquistata, ovvero deve essere diversa dalla pedina 
(o la pedina che controlla la torre) con la quale si intende conquistare
la pedina (o la torre)...........................................................*/
int canConquer(int from[], int to[], PlayableBoard board);