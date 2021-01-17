@echo off
gcc -ansi -pedantic-errors "../BACKEND/Sources/playableBoard.c" "../BACKEND/Sources/errors.c" "../BACKEND/Sources/moves.c" "../BACKEND/Sources/tower.c" "../BACKEND/Sources/validation.c" "../BACKEND/Sources/input.c" "../BACKEND/Sources/endGameChecks.c" "../UI/Sources/laskaBoard.c" "../main.c" -o2 -o minilaska.exe

pause
@echo on

