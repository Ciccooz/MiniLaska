#pragma once

#include "rules.h"
#include <stdlib.h>
#include <string.h>

PlayableBoard newBoard();
Tower towerAt(PlayableBoard grid, int coords[2]);
void freeBoard(PlayableBoard grid);
