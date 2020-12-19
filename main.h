#pragma once

#include <stdio.h>
#include "includer.h"

void refreshTerminal();

/*
Prende l'user input e lo converte a coordinate UI (matrice 7x7 con indici da 0 a 6)
Il risultato viene storato direttamente in UICoords
*/
static int getCoordinates(const char* title, int UICoords[2], PlayableBoard board);

static void checkPromotion(PlayableBoard boar, int UITo[2]);

int hasWon(PlayableBoard board, Names names);