<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/so_longm.png" alt="So_long 42 badge" width="125" /></a>

# So_long

**42 School · 🕹️ Software engineering project**

<img src="https://img.shields.io/badge/42_Project-C%20%7C%202D%20game-DB2777?style=flat-square" alt="So_long technology" />
<img src="https://img.shields.io/badge/Documentation-Project_Overview-334155?style=flat-square" alt="Project documentation" />

</div>

---


---

## 🔎 Overview

A small 2D game where a player navigates a map, collects items, and reaches an exit.


---

## ✨ Features

- Load a map and validate its structure
- Draw a 2D world with MiniLibX
- Handle keyboard movement and collisions
- Track player progress through the map


---

## 🧩 Technical approach

The source is organized around parsing, game initialization, movement, and rendering. MiniLibX provides a window and graphics primitives.

> **Tech stack** · C · MiniLibX · X11 · Make.


---

## 🚀 Build and usage

**Platform:** Linux with X11 and the bundled Linux MiniLibX. The repository is not configured for native macOS builds.

```bash
git clone https://github.com/doooriian/So_long.git
cd So_long
make
```

Run with a tracked valid map:

```bash
./so_long maps/valid/map1.ber
```


---

## 🧪 Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.


---

## ⚠️ Notes and limitations

The program needs a graphical Linux environment with X11; it is not a native macOS application.

---

<div align="center">

<sub>Part of the <a href="https://42.fr/">42 curriculum</a> · <a href="https://github.com/doooriian">Back to my GitHub profile</a></sub>

</div>
