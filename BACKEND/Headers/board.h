#pragma once

#include <stdlib.h>
#include <string.h>
#include "pawn.h"

PlayableBoard newBoard();
void freeBoard(PlayableBoard grid);
int getRowSize(int row);
