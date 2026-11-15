# So_long

> **42 School project** · C · 2D graphics · MiniLibX

A small 2D game where a player navigates a map, collects items, and reaches an exit.

## Overview

A small 2D game where a player navigates a map, collects items, and reaches an exit.

## Features

- Load a map and validate its structure
- Draw a 2D world with MiniLibX
- Handle keyboard movement and collisions
- Track player progress through the map

## Technical approach

The source is organized around parsing, game initialization, movement, and rendering. MiniLibX provides a window and graphics primitives.

**Stack:** C · MiniLibX · X11 · Make.

## Build and usage

**Platform:** Linux with X11 and the bundled Linux MiniLibX. The repository is not configured for native macOS builds.

```bash
git clone https://github.com/doooriian/So_long.git
cd So_long
make
```

Run `./so_long` with an existing `.ber` map path. Consult the tracked maps and the program's input validation to choose a valid map.

## Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.

## Notes and limitations

The program needs a graphical Linux environment with X11; it is not a native macOS application.

---

Part of the [42 curriculum](https://42.fr/). Explore the other projects on [my GitHub profile](https://github.com/doooriian).
