<br />
<p align="center">
  <a href="https://raw.githubusercontent.com/othneildrew/Best-README-Template/master/images/logo.png">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="42 Logo" width="250" height="250">
  </a>

  <h1 align="center">So_long</h1>

  <p align="center">
    A 2D game project from 42 School
    <br />
    <br />
    <img src="https://github.com/doooriian/42-Badges/blob/main/badges/so_longm.png" alt="So_long Badge" width="150">
  </p>
</p>

<p align="center">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/doooriian/So_long?color=1A237E" />
  <img alt="Code language count" src="https://img.shields.io/github/languages/count/doooriian/So_long?color=00BCD4" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/doooriian/So_long?color=7B1FA2" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/doooriian/So_long?color=D32F2F" />
</p>

---

## ✨ Overview

**So_long** is a 2D game project developed during the 42 curriculum, where the goal is to create a simple yet engaging game through solid programming practices and creative design. The game is built using the MLX graphics library and features a maze-like map where the player collects items and navigates through obstacles.

While the base project is open to any theme, I chose a subtle nod to the classic Pacman for an added nostalgic touch—not as the main focus, but as an inspiration to enhance the gameplay experience.

---

## 📑 Key Features

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

## 🔥 Game Controls

- **Arrow Keys or W, A, S, D:** Move your character around the maze.
- **ESC:** Exit the game immediately.

> **Note:** Ensure your environment meets the prerequisites for MLX (e.g., X11 on Linux) before running the game.

## 🧪 Testing

The project has undergone extensive testing to guarantee:

- **Fluid and responsive navigation** within the maze.
- **Correct map validation and layout consistency.**
- **Proper functionality of animations and bonus features.**

Custom map tests and internal debugging tools helped optimize the gameplay experience.

## 📸 Visual Example

 ![Sorting Process](https://github.com/doooriian/42-Badges/blob/main/push_swap.gif)

## ✅ Results

Here’s my score for the Push_swap project:

<p align="center">
  <img src="https://github.com/doooriian/42-Badges/blob/main/badges/LibftGrade.png" alt="Push_swap Grade">
</p>

## 📚 Resources

- **[MLX Documentation:](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)** Essential documentation for mastering the MLX graphics library.

## 📬 Contact

Feel free to reach out or contribute to this project on [GitHub](https://github.com/doooriian)!
