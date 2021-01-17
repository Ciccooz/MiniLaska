@echo off
gcc -ansi -pedantic-errors "../BACKEND/Sources/endGameChecks.c" "../BACKEND/Sources/errors.c" "../BACKEND/Sources/input.c" "../BACKEND/Sources/moves.c" "../BACKEND/Sources/playableBoard.c" "../BACKEND/Sources/tower.c" "../BACKEND/Sources/validation.c" "../UI/Sources/laskaBoard.c" "../main.c" -o2 -o "../bin/Windows/MiniLaska.exe" -lm

pause
@echo on
