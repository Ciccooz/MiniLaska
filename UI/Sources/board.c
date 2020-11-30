#include "..\\Headers\\UI.h"

void printBoard(PlayableBoard board, int size)
{
    int row, col;
    int i, j;
    int cell_side = ((size + 8)/7);

    for(row = 0; row < GRID_SIZE; row++)
    {
        for(i = 0; i < cell_side; i++)
        {
            for(col = 0; col < GRID_SIZE; col++)
            {
                for(j = 0; j < cell_side; j++)
                {
                    printf("X");
                }
            }

            printf("\n");
        }
    }

}

void printMessage(char* message)
{
    printf(message);
}
