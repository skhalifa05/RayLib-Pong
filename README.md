# Paddle Bounce Game 🎮

A simple **paddle bounce game** built using **C++** and **Raylib**. The game features a paddle controlled by the player, a bouncing ball, and a lives system. The goal is to keep the ball from falling off the screen while increasing your score.

## Game Concept
**Paddle Bounce** challenges players to control a paddle at the bottom of the screen, bouncing a ball to keep it in play. The goal is to maintain control, avoid missing the ball, and rack up points by bouncing it off the paddle. Players have a limited number of lives, and the game ends when all lives are lost.

## Gameplay
* 	Use the left (←) and right (→) arrow keys to move the paddle.
* 	The ball bounces off the paddle and walls, but if it falls below the screen, you lose a life.
* 	The game tracks your score and lives, displaying them in real time.
* 	The ball changes color when it bounces off the paddle.
* 	The game ends when you run out of lives.

## Features

* **Paddle Control**: Move left and right to hit the ball.
* **Dynamic Ball Physics**: Ball bounces off walls, ceiling, and paddle.
* **Score System**: Gain points for successful paddle hits.
* **Life System**: Lose a life when the ball touches the bottom.
* **Color Switching**: Paddle hits change the background color.
* **Screen Wrapping**: Paddle re-enters from the opposite side if it moves beyond the screen boundaries.

## Code Structure

The game follows an object-oriented design and includes the following classes:


Class | Responsibility 
--- | --- | 
GameManager | Controls game logic, updates, and rendering (Singleton Pattern).
Ball | Handles movement, bouncing, and resets.
Paddle | Controls user input and movement.
LivesManager | Tracks player lives and updates the UI.

## 📂 Project Structure

    📦 PongBreaker
    ├── include/
    ├── lib/
    ├── src/
    │   ├── main.cpp        # Game loop and initialization
    │   ├── GameManager.cpp # Singleton managing game logic
    │   ├── Ball.cpp        # Ball physics and movement
    │   ├── Paddle.cpp      # Paddle control
    │   ├── LivesManager.cpp # Lives tracking
    │   ├── GameManager.h   # Header for GameManager
    │   ├── Ball.h          # Header for Ball class
    │   ├── Paddle.h        # Header for Paddle class
    │   ├── LivesManager.h  # Header for LivesManager class
    ├── README.md           # Project documentation
    └── Makefile            # Build instructions
## Prerequisites
* 	C++ Compiler (GCC, Clang, MSVC)
* 	Raylib installed (https://github.com/raysan5/raylib/releases)



## Possible Improvements 🚀

* 	Add difficulty levels (ball speed increases over time).
* 	Implement a pause menu and restart option.
* 	Add sound effects for collisions.
* 	Introduce power-ups (e.g., bigger paddle, slow-motion).

## License

This project is open-source under the MIT License.