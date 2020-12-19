#pragma once

#include <stdlib.h> /*for malloc/free*/
#include <string.h> /*for memset*/
#include "../../includer.h"


PlayableBoard newBoard();
void freeBoard(PlayableBoard grid);
int getRowSize(int row);
Tower getPrevious(int from[2], int to[2], PlayableBoard board);
