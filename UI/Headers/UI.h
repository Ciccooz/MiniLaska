#pragma once

#include "UIBoard.h"

/*
cellSide indica la dimensione della cella (bordi esclusi) in char
cellSide deve essere un multiplo di TOWER_HEIGHT
*/
void printBoard(PlayableBoard board, int cellSide);
