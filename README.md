# Snake Game in C++ Using Raylib

This repository contains a classic **Snake Game** implementation in C++ using the **Raylib** graphics library. The game features simple controls, clean graphics, and an engaging gameplay loop. It is designed as a fun project to demonstrate basic game development concepts using **Object-Oriented Programming (OOP)** in C++.

---

## Features

- **Classic Snake Gameplay**:
  - Navigate the snake to eat food, grow longer, and avoid collisions.
- **Dynamic Difficulty**:
  - The game becomes progressively more challenging as the snake grows.
- **Simple Graphics**:
  - Utilizes Raylib for clean, minimalistic visuals.
- **Keyboard Controls**:
  - Arrow keys for movement.
- **Score Tracking**:
  - Track your score as the snake eats more food.

---

## Prerequisites

Before running the game, ensure you have the following:

1. **C++ Compiler**:
   - A compiler such as GCC (`g++`) or Clang is required.
2. **Raylib Library**:
   - Download and install Raylib from [raylib.com](https://www.raylib.com/).
   - Ensure it is properly linked during compilation.

---

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/KagE-Akumaa/Snake-Game-Raylib-cpp-.git
```

### 2. Navigate to the Project Directory

```bash
cd Snake-Game-Raylib-cpp-
```

### 3. Run the Game

- If you are on Windows and the `main.exe` file is provided, you can simply double-click on the `main.exe` file to run the game.
  - **Note**: The `lib` folder contains the required Raylib DLL files. Ensure the `main.exe` file and the `lib` folder are in the same directory for the game to run properly.
- Otherwise, you can build and run the game manually:

  #### Build the Game:

  - If a `Makefile` is provided, simply run:

    ```bash
    make
    ```

  - Otherwise, compile manually:

    ```bash
    g++ -o snake_game main.cpp -lraylib
    ```

  #### Run the Game:

  ```bash
  ./snake_game
  ```

---

## Gameplay Instructions

- **Objective**:
  - Guide the snake to eat the food and grow longer while avoiding collisions with the walls or itself.
- **Controls**:
  - Use the **Arrow Keys** to control the snake's movement.
- **Scoring**:
  - Your score increases by 1 for every food item eaten.

### Game Over Conditions

1. The snake collides with the wall.
2. The snake collides with its own body.

---

## Code Structure

### **Main Components**

1. **Snake**:
   - Handles the snake's movement, growth, and collision detection.
2. **Food**:
   - Randomly spawns on the screen and increases the snake's size when consumed.
3. **Game Loop**:
   - Manages the rendering, input handling, and game logic.

### **Key Files**
- `main.cpp`: Contains the core game logic.
- `Snake` and `Food` classes (if separate): Encapsulate functionality related to the snake and food.

---

## Challenges and Learning Outcomes

This project demonstrates:
- **Object-Oriented Programming (OOP)** concepts such as encapsulation and class design.
- **Event-Driven Programming** for handling user input.
- **Game Development Basics**:
  - Handling game loops.
  - Detecting collisions.
  - Dynamic rendering of sprites.

---

## Future Improvements

Some ideas for extending the game:
1. **Add Difficulty Levels**:
   - Increase speed as the game progresses.
2. **Introduce Obstacles**:
   - Add static or moving obstacles for more challenges.
3. **Multiplayer Mode**:
   - Allow two players to compete in a shared environment.
4. **High Score Tracking**:
   - Save and display high scores between sessions.
5. **Themed Graphics**:
   - Add skins for the snake or food items.

---

## Acknowledgments

1. **Raylib**:
   - Thanks to Raylib for providing an easy-to-use C++ game development library.
2. **Inspiration**:
   - Inspired by the classic Snake games played on older mobile devices.

---
