#include "../Headers/UIBoard.h"

/*la cellSide deve essere un multiplo di TOWER_HEIGHT*/
void printBoard(PlayableBoard board, int cellSide)
{
    int boardRow, boardCol, terminalRow, UICol;

    printUpperSeparator(cellSide);
    for(boardRow = 0; boardRow < GRID_SIZE; boardRow++)
    {
        for(terminalRow = 0; terminalRow < cellSide; terminalRow++)
        {
            printRowCoordinates(cellSide, terminalRow, boardRow);

            printf("%c", VERTICAL_SIDE);
            for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
            {

                if(boardRow % 2 == boardCol % 2)
                {
                    int UICoords[2];
                    int pawnIndex = TOWER_HEIGHT - 1 - (terminalRow / (cellSide / TOWER_HEIGHT)); /*indice della pedina da printare*/
                    char pawn;

                    UICoords[0] = boardRow;
                    UICoords[1] = boardCol;
                    pawn = UICoordinatesToTower(board, UICoords)[pawnIndex];
                    printCellContent(pawn, cellSide);
                }
                else
                    printCellContent(UNPLAYABLE_PAWN, cellSide);

                printf("%c", VERTICAL_SIDE);
            }
            printf("\n");
        }

        if(boardRow < GRID_SIZE - 1)
            printMidSeparator(cellSide);
        else
        {
            printLowerSeparator(cellSide);
            printColumnCoordinates(cellSide);
        }
    }
}

Tower UICoordinatesToTower(PlayableBoard board, int UICoords[2])
{
  return board[UICoords[0]][UICoords[1] / 2];
}



static void printRowCoordinates(int cellSide, int terminalRow, int boardRow)
{
    printf("\t");
    if(terminalRow == cellSide / 2)
        printf("%d", boardRow);
    else
        printf(" ");
}
static void printColumnCoordinates(int cellSide)
{
    int currentChar = 0;
    int boardCol;

    printf("\t ");
    for(boardCol = 0; boardCol < GRID_SIZE; boardCol++)
    {
        printf(" ");
        for(currentChar = 0; currentChar < cellSide; currentChar++)
        {
            if(currentChar == cellSide / 2)
                printf("%c", 'a' + boardCol);
            else
                printf(" ");
        }
    }
    printf("\n");
}
static void printHorizontalSeparator(int cellSide, char left, char intersection, char right)
{
    int i, j;

    printf("\t %c", left);
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < cellSide; j++)
            printf("%c", HORIZONTAL_SIDE);
        printf("%c", intersection);
    }

    printf("\b%c\n", right);
}
static void printUpperSeparator(int cellSide)
{
    printHorizontalSeparator(
        cellSide,
        TOP_LEFT_CORNER,
        TOP_INTERSECTION,
        TOP_RIGHT_CORNER);
}
static void printMidSeparator(int cellSide)
{
    printHorizontalSeparator(
        cellSide,
        MID_LEFT_SIDE,
        MID_INTERSECTION,
        MID_RIGHT_SIDE);
}
static void printLowerSeparator(int cellSide)
{
    printHorizontalSeparator(
        cellSide,
        BOTTOM_LEFT_CORNER,
        BOTTOM_INTERSECTION,
        BOTTOM_RIGHT_CORNER);
}
static void printCellContent(char content, int cellSide)
{
    int i;
    for(i = 0; i < cellSide; i++)
        printf("%c", content);
}
