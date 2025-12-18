#ifndef MINESWEEPER_H
#define MINESWEEPER_H

int minesweeper();
void tt_boardp();
int is_mine(int x, int y);
void mine_setup(int mines);
int count_adjacent_mines(int x, int y);

#endif