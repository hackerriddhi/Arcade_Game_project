#include <stdio.h>
#include <stdlib.h>
#include "minesweeper.h"

char tt_board[10][10];
int mx[10], my[10], flag = 0;

void tt_boardp() {
    printf("\n  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) printf("%c ", tt_board[i][j]);
        printf("\n");
    }
}

int is_mine(int x, int y) {
    for (int i = 0; i < 10; i++) if (mx[i] == x && my[i] == y) return 1; 
    return 0;
}

void mine_setup(int mines) {
    while (mines < 10) {
        int x = rand() % 10, y = rand() % 10, already = 0;
        for (int i = 0; i < mines; i++) if (mx[i] == x && my[i] == y) already = 1;
        if (!already) { mx[mines] = x; my[mines] = y; mines++; }
    }
}

int count_adjacent_mines(int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
            if (x+dx>=0 && x+dx<10 && y+dy>=0 && y+dy<10 && is_mine(x+dx, y+dy)) count++; 
    return count;
}

int minesweeper() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) tt_board[i][j] = '*';
    mine_setup(0);
    while (1) {
        tt_boardp();
        char rf; int rx, ry;
        printf("\nEnter move R(Reveal)/F(Flag)/B(Back) and x y: ");
        scanf(" %c", &rf); if(rf=='b') return 0;
        scanf("%d %d", &rx, &ry);
        if (rf == 'r') {
            if (is_mine(rx, ry)) { printf("BOOM! Game Over.\n"); break; }
            tt_board[rx][ry] = '0' + count_adjacent_mines(rx, ry);
        } else if (rf == 'f') { tt_board[rx][ry] = 'F'; flag++; }
        if(flag == 10) { printf("You Win!\n"); break; } 
    }
    flag = 0; return 0;
}