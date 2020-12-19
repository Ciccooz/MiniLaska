@echo off
gcc -ansi -pedantic-errors "../BACKEND/Sources/board.c" "../BACKEND/Sources/errors.c" "../BACKEND/Sources/moves.c" "../BACKEND/Sources/pawn.c" "../BACKEND/Sources/validation.c" "../BACKEND/Sources/input.c" "../UI/Sources/UI.c" "../UI/Sources/UIBoard.c" "../main.c" -o2 -o main.exe

pause
@echo on

