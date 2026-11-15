<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/so_longm.png" width="125" alt="So_long 42 project badge" /></a>

# So_long

**2D game with MiniLibX · Linux**

<img src="https://img.shields.io/badge/42%20School-Project-DB2777?style=flat-square" alt="42 School project" />

</div>

---

## 🔎 Overview

**So_long** is a 2D game project developed during the 42 curriculum, where the goal is to create a simple yet engaging game through solid programming practices and creative design. The game is built using the MLX graphics library and features a maze-like map where the player collects items and navigates through obstacles.

While the base project is open to any theme, I chose a subtle nod to the classic Pacman for an added nostalgic touch—not as the main focus, but as an inspiration to enhance the gameplay experience.

---

## ✨ Key Features

- **Interactive Gameplay**: Navigate through the maze to collect items and reach the exit.
- **Graphics & Animations**: Utilizes the MLX library to provide smooth and dynamic visual effects.
- **Event Handling**: Real-time keyboard input for responsive and fluid movement.
- **Map Validation**: Ensures the provided map (in `.ber` format) is valid and playable.
- **Bonus Features**:
  - Seamless animations.
  - Optional enemy movements.
  - Enhanced effects (including optional sound support, if available).

---

## 🛠️ Technologies Used

- **[C](https://devdocs.io/c/)** — Core programming language.
- **[MLX (MiniLibX)](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)** — Graphics and window management library.
- **[Makefile](https://www.gnu.org/software/make/manual/make.html)** — Build automation tool.

---

## 🚀 How to Build and Run

**Platform:** Linux with X11 and MiniLibX; native macOS is not supported by this build.

Start by cloning the repository and then compile using the provided Makefile commands:

```bash
# Compile the project
make all

# Remove object files
make clean

# Remove object files and executable
make fclean

# Clean and recompile
make re

```
To launch the game, run the executable with a map file (in `.ber` format) as an argument:

```bash
./so_long maps/my_map.ber
```
> **Note:** Ensure your environment meets the prerequisites for MLX (e.g., X11 on Linux).

## 🎮 Game Controls

- **Arrow Keys or W, A, S, D:** Move your character around the maze.
- **ESC:** Exit the game immediately.

> **Note:** Ensure your environment meets the prerequisites for MLX (e.g., X11 on Linux) before running the game.

## 🧪 Testing

The project has undergone extensive testing to guarantee:

- **Fluid and responsive navigation** within the maze.
- **Correct map validation and layout consistency.**
- **Proper functionality of animations and bonus features.**

Custom map tests and internal debugging tools helped optimize the gameplay experience.


## 📚 Resources

- **[MLX Documentation:](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)** Essential documentation for mastering the MLX graphics library.

## 📬 Contact

Feel free to reach out or contribute to this project on [GitHub](https://github.com/doooriian)!
