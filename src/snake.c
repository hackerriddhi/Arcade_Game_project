#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "snake.h"

int x[100], y[100];  
int xf, yf, score = 0;
char s1[12][27] = {
    "***************************", "* *", "* *",
    "* *", "* *", "* *",
    "* *", "* *", "* *",
    "* *", "* *", "***************************"
};

clock_t T;
char moveA, prev_move = 'q';

void stage1() {
    system("cls");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 27; j++) printf("%c", s1[i][j]);
        printf("\n");
    }
}

int slcheck() {
    if (x[0] <= 0 || x[0] >= 11 || y[0] <= 0 || y[0] >= 26) return 0; 
    for(int i=1 ; i<=score ; i++) if(x[i]==x[0] && y[i]==y[0]) return 0;
    return 1;
}

void fruitlocation() {
    xf = rand()%10 + 1; yf = rand()%25 + 1;
    for (int i = 0; i <= score; i++) if (x[i] == xf && y[i] == yf) { fruitlocation(); return; }
    s1[xf][yf] = 'F';
}

void snakemovement() {
    s1[x[score]][y[score]] = ' ';
    for (int i = score; i > 0; i--) { x[i] = x[i - 1]; y[i] = y[i - 1]; }
}

void snake_conti_move() {
    T = clock();
    while(clock() - T < 250) {  
        if (GetAsyncKeyState('W') & 0x8000) { moveA = 'w'; break; } 
        if (GetAsyncKeyState('S') & 0x8000) { moveA = 's'; break; } 
        if (GetAsyncKeyState('A') & 0x8000) { moveA = 'a'; break; }
        if (GetAsyncKeyState('D') & 0x8000) { moveA = 'd'; break; } 
    }
}

void level1() {
    fruitlocation();
    while (1) {
        stage1();
        printf("Score: %d\n", score); 
        snake_conti_move();
        char move = moveA;
        if((move=='w' && prev_move=='s') || (move=='s' && prev_move=='w') || 
           (move=='a' && prev_move=='d') || (move=='d' && prev_move=='a')) move=prev_move;
        if(move=='s'||move=='w') Sleep(100);
        snakemovement();
        prev_move = move;
        if (move == 'w') x[0]--; if (move == 's') x[0]++;
        if (move == 'a') y[0]--; if (move == 'd') y[0]++;
        if (slcheck() == 0) return;
        if (x[0] == xf && y[0] == yf) { score++; fruitlocation(); }
        for (int i = 0; i <= score; i++) s1[x[i]][y[i]] = 'o';
        if (move == 'w') s1[x[0]][y[0]] = '^'; if (move == 's') s1[x[0]][y[0]] = 'v';
        if (move == 'a') s1[x[0]][y[0]] = '<'; if (move == 'd') s1[x[0]][y[0]] = '>';
        Sleep(100);
    }
}

int snake_game() {
    x[0] = 1, y[0] = 1; s1[x[0]][y[0]] = '>';
    level1();
    printf("\n GAME OVER \n"); 
    s1[xf][yf]=' '; moveA=' ';
    for(int i=0 ; i<=score ; i++) s1[x[i]][y[i]]=' ';
    score = 0; return 0;
}