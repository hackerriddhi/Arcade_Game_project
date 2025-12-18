#  Technical Logic & Architecture

This project is built using **Procedural Programming** in C, focusing on logic-driven modules and real-time user interaction.

##  System Overview (main.c)
The entire arcade experience is orchestrated through `main.c`, which acts as the central engine. It handles:
- **Game Selection:** A persistent loop for choosing between different modules.
- **Process Flow:** Cleanly transitioning from the menu to a game and back.
- **System Calls:** Utilizing `system("cls")` and `Sleep()` for a smooth UI experience.

---

##  Core Game Modules

### 1. Snake and Fruit
- **Movement Logic:** Implements a coordinate-based system for the snake's head and body.
- **Fruit Generation:** Uses `rand()` with time-seeding to ensure unpredictable fruit placement.
- **Collision Engine:** Real-time checks for border impact and self-collision.
- **Real-Time Input:** Uses `GetAsyncKeyState` to allow continuous movement without waiting for user "Enter" keys.

### 2. Tic-Tac-Toe (AI Integrated)
- **Input Handling:** Validates 2D coordinate inputs against the current board state.
- **Bot Logic:** I developed a logic-driven bot that prioritizes:
    1. Winning moves.
    2. Blocking the player's potential winning lines.
    3. Strategic center/corner placement.
- **State Detection:** Scans the 3x3 grid for 8 possible winning combinations after every turn.

### 3. Minesweeper
- **Grid Setup:** A dual-layer 10x10 array system (one for mine placement, one for the player's view).
- **Reveal System:** Uses an algorithm similar to **Breadth-First Search (BFS)** to automatically reveal empty adjacent tiles when a zero-mine tile is clicked.
- **Flagging Logic:** Allows users to mark suspected mines to prevent accidental clicks.

---

