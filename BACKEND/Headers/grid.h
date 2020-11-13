#pragma once

#include "rules.h"
#include <stdlib.h>
#include <string.h>

PlayableBoard newBoard();
PlayableBoard allocBoard();
void spawnPawns(PlayableBoard grid);
Tower towerAt(PlayableBoard grid, int coords[2]);
void freeBoard(PlayableBoard grid);
