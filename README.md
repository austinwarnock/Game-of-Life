# Conway's Game of Life

This repository contains a C program that implements Conway's Game of Life. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It consists of a grid of cells that can live, die, or multiply based on a few mathematical rules.

## Features

- Randomly initializes the game board.
- Displays the board and updates it continuously to simulate the game.
- Counts neighbors and updates cells based on the rules of the game.
- Clears the terminal screen and prints the board for each iteration.

## How to Compile and Run

### Prerequisites

- A C compiler (e.g., `gcc`).

### Compilation

To compile the program, use the following command:

```bash
gcc -o game_of_life game_of_life.c
```

### Running the Program

After compilation, run the program using:

```bash
./game_of_life
```

## Rules of Conway's Game of Life

1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

## Code Structure

- **countNeighbors**: Counts the number of live neighbors for a given cell.
- **print_board**: Prints the current state of the board to the terminal.
- **init_board**: Initializes the board with random cells.
- **update_board**: Updates the board based on the rules of the game.
- **clearScreen**: Clears the terminal screen.
- **animate**: Continuously updates and prints the board to simulate the game.

## Example Output

When you run the program, you will see an output similar to the following:

```
 @    
@@@   
 @    
     
Population Size: 4
```

The board will continuously update to show the evolution of the cells.

## Author

Austin Warnock

