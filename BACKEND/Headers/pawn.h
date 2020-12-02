#pragma once

#include "rules.h"
#include "board.h"

/*Restituisce la pedina (o la pedina che comanda la torre) che occupa la cella selezionata
Se la cella è vuota, viene restituito il NULL_PAWN (ovvero uno spazio vuoto)............*/
char getTop(int from[], PlayableBoard board);

/*Restituisce l'indice nella quale si trova la pedina 
(o la pedina che comanda la torre) nella cella selezionata
Se la cella è vuota, restituisce -1.....................................................*/
int getTopIndex(int from[], PlayableBoard board);

/*Cambia la pedina (o la pedina che comanda la torre) della cella selezionata 
da SOLDIER ad OFFICIER, nel caso in cui essa raggiunga la fine del campo da gioco.......*/
void changeTop(int from[], char top, PlayableBoard board);

/* MANCA IL MOVE */