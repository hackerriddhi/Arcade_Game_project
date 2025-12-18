#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "snake.h"
#include "tictactoe.h"
#include "minesweeper.h"

void screen1() {
    printf("\n••••••••••••••••••••••••••\n•                        •\n•    WELCOME TO THE      •\n•        ARCADE          •\n•                        •\n•        LOADING...      •\n•                        •\n•                        •\n•••••••••••••••••••••••••");
}

void screen2() {
    printf("\n••••••••••••••••••••••••••\n•      Select Option     •\n•   1. Snake and Fruit   •\n•   2. Tic Tac Toe       •\n•   3. Minesweeper       •\n•   4. Exit              •\n•                        •\n•                        •\n•••••••••••••••••••••••••\n Enter a number :");
}

int main() {
    int choice;
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    screen1();
    Sleep(2000);
    system("cls");
    while (1) { 
        screen2();
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) snake_game();
        else if (choice == 2) tic_tac_toe();
        else if (choice == 3) minesweeper();
        else if (choice == 4) break;

        Sleep(2000);
        system("cls");
    }
    return 0;
}