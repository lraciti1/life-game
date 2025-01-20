# Life Game

The playlife.c program is a C-based implementation of Conway's Game of Life, a cellular automaton created by mathematician John Conway. This simulation models the evolution of cells on a grid, where each cell follows a set of simple rules to determine whether it survives, dies, or is born in the next generation. The program supports both interactive and batch modes, allowing users to view and interact with the grid or process pre-defined input files.

## Features

- Interactive Mode: When no arguments are provided, the program runs in interactive mode. Users can observe the evolution of the grid step-by-step.
- Batch Mode: If a file name is provided as an argument, the program enters batch mode, reading and processing the file to display the initial grid and then evolve the grid according to the rules.
- Grid Setup and Display: The grid is initialized with predefined conditions, and a display function is used to show the current state of the game.
- Dynamic Evolution: The grid evolves over time based on the rules of Conway's Game of Life, which include cell survival, underpopulation, overpopulation, and birth conditions.

## How It Works
- The program initializes a 2D board (array) representing the grid.
- The Setup function initializes the grid with starting conditions, preparing it for evolution.
- The display function renders the current state of the grid to the console, so users can visually track the game’s progress.
- Interactive Mode: If no arguments are provided, the program allows users to observe the grid evolve step by step.
- Batch Mode: If a file name is passed as an argument, the program loads the initial board configuration from the file and processes it automatically.
- Invalid Argument Handling: If the user provides more than one command-line argument (other than the file), the program will display an error message.
