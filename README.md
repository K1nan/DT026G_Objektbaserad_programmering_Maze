# Maze Generator

This project implements a maze generator in C++ using the Depth-First Search (DFS) algorithm. The maze is represented as a grid of cells and features randomly generated paths, as well as start ('S') and end ('E') points.

---

## Features

- **Customizable Maze Dimensions**: Create a maze with custom dimensions or use the default size of 11x11.
- **DFS Algorithm**: Uses Depth-First Search (DFS) to carve out paths in the maze.
- **Random Start and End Points**: Automatically places start ('S') and end ('E') points in the maze.
- **Console Output**: Displays the maze grid in a console-friendly format.
- **Boundary Checks**: Ensures that all operations stay within the bounds of the maze grid.

---

## Code Overview

### Header File (`maze.h`)

The header file defines the `Maze` class and its associated methods and attributes.

#### Key Components:

- **Public Methods**:
  - `Maze(int x, int y)`: Constructor to create a maze with specified dimensions.
  - `Maze()`: Default constructor to create a maze of size 11x11.
  - `void print()`: Prints the maze to the console.

- **Private Methods**:
  - `void add(int x, int y)`: Initializes the maze grid with unvisited nodes.
  - `void Start()`: Randomly selects the starting point of the maze.
  - `void End()`: Randomly selects the ending point of the maze.
  - `void generate()`: Generates the maze paths using DFS.
  - `bool Inside_the_maze(int x, int y)`: Checks if a position is within maze bounds.
  - `std::vector<node> possible_neighbour(int x, int y)`: Identifies potential neighboring nodes for path creation.
  - `node randomgranne(std::vector<node> const s)`: Selects a random neighbor from a list of possible neighbors.

- **Private Attributes**:
  - `struct node`: Represents individual cells in the maze with the following:
    - `int x, y`: Coordinates of the node.
    - `char cell`: Visual representation of the node ('X' for walls, 'S' for start, 'E' for end, and ' ' for paths).
    - `bool IsVisited`: Tracks whether the node has been visited.
  - `std::vector<std::vector<node>> myVec`: 2D grid representing the maze.

---

### Implementation File (`maze.cpp`)

The implementation file contains the logic for the `Maze` class methods. 

#### Highlights:
- **`add(int x, int y)`**: Creates the grid and initializes all nodes with default values.
- **`generate()`**: Uses a stack-based DFS approach to carve out paths in the maze.
- **`Start()` and `End()`**: Randomly assign start and end points within the maze boundaries.
- **`print()`**: Outputs the maze structure to the console.

  
#### A sample 11x11 maze output:
XXXXXXXXXXX
X   X     X
X X X XXX X
X X     X X
XXX XXX X X
X   X     X
X XXXXX XXX
X X     X X
X XXX XXX X
X       S X
XXXXXXXXXEX
XXXXXXXXXXX X X X X X X XXX X X X X X XXX XXX X X X X X X XXXXX XXX X X X X X XXX XXX X X S X XXXXXXXXXEX



In the maze:
- **`S`** represents the starting point.
- **`E`** represents the ending point.
- **`X`** represents walls.
- Empty spaces represent the maze's traversable path.
