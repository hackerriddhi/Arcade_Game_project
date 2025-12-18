#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tictactoe.h"

char tt[5][5]={" | | ", "-----", " | | ", "-----", " | | "};
int row, column;

void board(){
    for(int a=0; a<5; a++){
        for(int b=0; b<5; b++) printf("%c",tt[a][b]);
        printf ("\n");
    }
}

int winconditionp(){
    if((tt[0][0]=='O'&&tt[0][2]=='O'&&tt[0][4]=='O') || (tt[2][0]=='O'&&tt[2][2]=='O'&&tt[2][4]=='O') ||
       (tt[4][0]=='O'&&tt[4][2]=='O'&&tt[4][4]=='O') || (tt[0][0]=='O'&&tt[2][0]=='O'&&tt[4][0]=='O') ||
       (tt[0][2]=='O'&&tt[2][2]=='O'&&tt[4][2]=='O') || (tt[0][4]=='O'&&tt[2][4]=='O'&&tt[4][4]=='O') ||
       (tt[0][0]=='O'&&tt[2][2]=='O'&&tt[4][4]=='O') || (tt[0][4]=='O'&&tt[2][2]=='O'&&tt[4][0]=='O')) return 1;
    return 0;
}

int winconditionb(){
    if((tt[0][0]=='X'&&tt[0][2]=='X'&&tt[0][4]=='X') || (tt[2][0]=='X'&&tt[2][2]=='X'&&tt[2][4]=='X') ||
       (tt[4][0]=='X'&&tt[4][2]=='X'&&tt[4][4]=='X') || (tt[0][0]=='X'&&tt[2][0]=='X'&&tt[4][0]=='X') ||
       (tt[0][2]=='X'&&tt[2][2]=='X'&&tt[4][2]=='X') || (tt[0][4]=='X'&&tt[2][4]=='X'&&tt[4][4]=='X') ||
       (tt[0][0]=='X'&&tt[2][2]=='X'&&tt[4][4]=='X') || (tt[0][4]=='X'&&tt[2][2]=='X'&&tt[4][0]=='X')) return 1; 
    return 0;
}

void randommove(){
    int x = 2*(rand()%3), y = 2*(rand()%3);
    if(tt[x][y]==' ') tt[x][y]='X'; else randommove();
}

void botmove(){
    Sleep(1000); 
    randommove(); // Simplified for structure; logic can be expanded.
}

void ttl(){
    int moves = 0;
    while (1) {
        board();
        printf("\nUser row and column (1-3): "); 
        scanf("%d %d", &row, &column);
        if(row<=0 || row>3 || column<=0 || column>3 || tt[2*(row-1)][2*(column-1)]!=' ') { system("cls"); continue; }
        tt[2*(row-1)][2*(column-1)] = 'O'; moves++;
        if (winconditionp()) { board(); printf("\nPlayer Wins!\n"); break; } 
        if (moves >= 9) { board(); printf("\nDraw!\n"); break; } 
        botmove(); moves++;
        if (winconditionb()) { board(); printf("\nBot Wins!\n"); break; } 
        system("cls");
    }
}

int tic_tac_toe(){
    for(int i=0; i<5; i+=2) for(int j=0; j<5; j+=2) tt[i][j]=' ';
    ttl(); return 0;
}