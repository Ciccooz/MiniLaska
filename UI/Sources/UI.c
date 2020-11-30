#include "..\\Headers\\UI.h"

static void printHorizontalSeparator(int cellSide, unsigned char* symbols);
static void printUpperSeparator(int cellSide);
static void printMidSeparator(int cellSide);
static void printLowerSeparator(int cellSide);
static void printCellContent(char content, int cellSide);
static void printTopCoordinates(int cellSide);
/*la cellSide deve essere divisibile per 3*/
void printBoard(PlayableBoard board, int cellSide)
{
    int UIRow, UICol, boardRow, boardCol;

    if(cellSide % TOWER_HEIGHT || cellSide < 0)
        return;
    
    printTopCoordinates(cellSide);
    printUpperSeparator(cellSide);
    for(boardRow = 0; boardRow < GRID_SIZE; boardRow++)
    {
        for(UIRow = 0; UIRow < cellSide; UIRow++)
        {
            
            if(UIRow == cellSide / 2)
                printf("\t%d", boardRow);
            else 
                printf("\t ");

            printf("%c", (char)0xba);
            for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
            {

                if(boardRow % 2 != boardCol % 2)
                    printCellContent(UNPLAYABLE_PAWN, cellSide);
                else 
                {
                    char pawn = board[boardRow][boardCol / 2][TOWER_HEIGHT - 1 - (UIRow / (cellSide / TOWER_HEIGHT))];
                    printCellContent(pawn, cellSide);
                }

                printf("%c", (char)0xba);
            }
            printf("\n");
        }

        if(boardRow < GRID_SIZE - 1)
            printMidSeparator(cellSide);
        else
            printLowerSeparator(cellSide);
        
    }

    
}

static void printTopCoordinates(int cellSide)
{
    int currentChar = 0;
    int boardCol;

    printf("\n\t ");
    for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
    {
        printf(" ");
        for(currentChar = 0; currentChar < cellSide; currentChar++)
        {
            if(currentChar == cellSide / 2)
                printf("%d", boardCol);
            else 
                printf(" ");            
        }
    }


    printf("\n");

}

static void printHorizontalSeparator(int cellSide, unsigned char* symbols)
{
    int i, j;

    printf("\t %c", symbols[0]);
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < cellSide; j++)
            printf("%c", (char)0xcd);
        printf("%c", symbols[1]);
    }

    printf("\b%c\n", symbols[2]);
}

static void printUpperSeparator(int cellSide)
{
    unsigned char symbols[] = {0xc9, 0xcb, 0xbb};
    printHorizontalSeparator(cellSide, symbols);
}

static void printMidSeparator(int cellSide)
{
    unsigned char symbols[] = {0xcc, 0xce, 0xb9};
    printHorizontalSeparator(cellSide, symbols);
}

static void printLowerSeparator(int cellSide)
{
    unsigned char symbols[] = {0xc8, 0xca, 0xbc};
    printHorizontalSeparator(cellSide, symbols);
}

static void printCellContent(char content, int cellSide)
{
    int i;
    for(i = 0; i < cellSide; i++)
        printf("%c", content);
}

void printMessage(char* message)
{
    printf("%s\n", message);
}
