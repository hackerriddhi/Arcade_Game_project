# Arcade in C

An interactive collection of three classic games developed entirely in C. This project demonstrates real-time input handling, computer-controlled logic, and dynamic menu systems.

## Included Games

### 1. Snake Game
* **Goal:** Navigate the snake to eat fruit and achieve the highest score possible. 
* **Mechanics:** The snake grows in size with every fruit consumed. 
* **Game Over:** The game ends if the snake touches the boundary or its own body. 
* **Controls:** Use `w`, `s`, `a`, and `d` for directional movement. 

### 2. Tic-Tac-Toe
* **Goal:** Create a sequence of three 'O's horizontally, vertically, or diagonally. 
* **Bot Logic:** Features an AI that actively tries to win and intercepts the player's moves to prevent them from winning. 
* **Controls:** Enter two integers (1-3) representing the row and column (e.g., `1 2`). 

### 3. Minesweeper
* **Goal:** Reveal all tiles on the board without triggering a hidden mine. 
* **Mechanics:** Numbered tiles indicate how many mines are in the surrounding area.
* **Controls:** Enter row and column coordinates to select a tile. 

---

##  Technical Challenges & Learning
This project pushed our understanding of C programming in several areas:
**Real-time Input:** Used `GetAsyncKeyState()` and `clock()` to handle continuous movement in the Snake game without waiting for user enters.
* **Dynamic Rendering:** Implemented page-refresh logic to show real-time movement and updates for all games. 
* **Logic Design:** Developed algorithms for bot decision-making in Tic-Tac-Toe and mine-proximity counting in Minesweeper. 

---


##  Future Improvements
* Smoothing the refresh rate for the Snake game. 
* Adding attractive graphics and colored text output. 
