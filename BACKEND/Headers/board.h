#pragma once

#include "rules.h"
#include <stdlib.h> /*for malloc/free*/
#include <string.h> /*for memset*/

PlayableBoard newBoard();
void freeBoard(PlayableBoard grid);
int getRowSize(int row);
