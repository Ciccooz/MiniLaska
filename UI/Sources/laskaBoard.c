#include "../Headers/laskaBoard.h"

#include <stdio.h>
#include "../../main.h"
#include "../../BACKEND/Headers/rules.h"

/*la cellSide deve essere un multiplo di TOWER_HEIGHT*/
void printBoard(PlayableBoard board)
{
    int cellSide = TOWER_HEIGHT;
    int boardRow, terminalRow;
    char boardCol;

    printUpperSeparator(cellSide);
    for(boardRow = FIRST_ROW; boardRow > 0; boardRow --)
    {
        for(terminalRow = 0; terminalRow < cellSide; terminalRow++)
        {
            printRowCoordinates(cellSide, terminalRow, boardRow);

            printf("%c", VERTICAL_SIDE);
            for(boardCol = FIRST_COLUMN; boardCol < FIRST_COLUMN + GRID_SIZE; boardCol++)
            {
                int UICoords[2];
                UserInput userInput;
                userInput.column = boardCol;
                userInput.row = boardRow;

                UserInputToUICoords(userInput, UICoords);

                if(UICoords[0] % 2 == UICoords[1] % 2)
                {
                    int pawnIndex = TOWER_HEIGHT - 1 - (terminalRow / (cellSide / TOWER_HEIGHT)); /*indice della pedina da printare*/
                    char pawn;

                    pawn = UICoordinatesToTower(board, UICoords)[pawnIndex];
                    printCellContent(pawn, cellSide);
                }
                else
                    printCellContent(UNPLAYABLE_PAWN, cellSide);

                printf("%c", VERTICAL_SIDE);
            }
            printf("\n");
        }

        if(boardRow > 1)
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
void UserInputToUICoords(UserInput input, int UICoordinates[2])
{
  UICoordinates[0] = GRID_SIZE - input.row;
  UICoordinates[1] = input.column - FIRST_COLUMN;
}
Tower getTowerInBetween(PlayableBoard board, int UIPos1[2], int UIPos2[2])
{
  int coords[2];
  coords[0] = (UIPos1[0] + UIPos2[0]) / 2;
  coords[1] = (UIPos1[1] + UIPos2[1]) / 2;

  return UICoordinatesToTower(board, coords);
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
    char boardCol;

    printf("\t ");
    for(boardCol = FIRST_COLUMN; boardCol < FIRST_COLUMN + GRID_SIZE; boardCol++)
    {
        printf(" ");
        for(currentChar = 0; currentChar < cellSide; currentChar++)
        {
            if(currentChar == cellSide / 2)
                printf("%c", boardCol);
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
