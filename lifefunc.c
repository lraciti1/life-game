// Lucia Raciti
// Fundamentals of Computing
// 11/5/24
// lifefunc.c is the functions file for the Conway's Game of Life that displays all the options for each mode, and it includes the functions for interactive versus batch mode

// librarys
#include <stdio.h>
#include "lifefunc.h"
#include <unistd.h>
#include <stdlib.h>

// sets up 2D array of the board positions
void Setup(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      board[i][j] = ' ';  // sets all parts of array to blank space
}

// displays board
void display(char board[SIZE][SIZE]) {
  system("clear"); // clears system
  // top row of display
  printf(" ");
  for (int i = 1; i < SIZE; i++) printf("-");
  printf("\n");

  for (int i = 1; i < SIZE; i++) {
    printf("|"); // left most side of board
    for (int j = 1; j < SIZE; j++) {
      printf("%c", board[i][j]); // position of all X's and blanks
    }
  printf("|\n"); // right most side of board
  }
  // bottom row of display
  printf(" ");
  for (int i = 1; i < SIZE; i++) printf("-");
  printf("\n"); 
}

// make a cell alive
void addCell(char board[SIZE][SIZE], int x, int y) {
  if (y < SIZE && x < SIZE)
    board[y][x] = 'X'; // sets the selected x and y to X
  else {
    printf("Out of range\n");
    usleep(100000);
  }
  display(board);
}

// make a cell dead
void removeCell(char board[SIZE][SIZE], int x, int y) {
  if (y < SIZE && x < SIZE) {
    board[y][x] = ' '; // removes X from the location and replaces with blank
  }
  else {
    printf("Out of range\n");
    usleep(100000);
  }
  display(board);
}

// counts cell's neighbors

int CountNeighbors(char board[SIZE][SIZE], int y, int x) {
  int count = 0;
  for (int i = y-1; i <= y+1; i++) {
    for (int j = x-1; j <= x+1; j++) {
      if (i == y && j == x) continue; // ignores position
      if ((i >= 1 && j >= 1) && (j < SIZE && j< SIZE)) {
        if (board[i][j] == 'X')
          count++;
      }
    }
  }
  return count;  
}

// advances the game one move
void advanceSim(char board[SIZE][SIZE]) {
  char newboard[SIZE][SIZE]; // variable to store new location
  Setup(newboard); // temporary board to store new play

  for (int y = 1; y < SIZE; y++) {
    for (int x = 1; x < SIZE; x++) {
      int count = CountNeighbors(board, y, x); // counts neighbor function
      if ((count == 2 || count == 3) && board[y][x] == 'X') // keeps cell alive
        newboard[y][x] = 'X';
      else if (count == 3 && board[y][x] == ' ')
        newboard[y][x] = 'X'; // makes cell alive
      else
        newboard[y][x] = ' '; // keeps cell dead
    }
  }
  for (int y = 1; y < SIZE; y++) {
    for (int x = 1; x < SIZE; x++)
      board[y][x] = newboard[y][x]; // allocates values of temporary board to original board
  }
  display(board);
}

// play the game continuously until ^C is typed
void playGame(char board[SIZE][SIZE]) {
  while(1) {
    display(board);
    advanceSim(board); // continuously runs simulation until ^C 
    usleep(100000);
  }
}

// interactive mode to play with user
int interactiveMode(char board[SIZE][SIZE]) {
  int playOn = 1;  // flag variable
  char choice;  // player's choice variable
  int x;  // column
  int y;  // row

  while(playOn) {
    printf("Command: ");
    scanf("%c", &choice); // reads choice
    // adds alive cell
    if (choice == 'a') {
      scanf("%d %d", &x, &y);
      addCell(board, x, y);
    }
    // removes alive cell
    else if (choice == 'r') {
      scanf("%d %d", &x, &y);
      removeCell(board, x, y);
    }
    // advances simulation one move
    else if (choice == 'n') advanceSim(board);
    // quits game and stops while loop
    else if (choice == 'q') playOn = 0;
    // continously runs simulation until forced exit
    else if (choice == 'p') playGame(board);
    // if letter is not one of the options
    else printf("%c is not an option\n", choice);
    getchar();
  }
  printf("Goodbye\n");
  return 0;
}

// batch mode that reads file and continously runs simulation
int batchMode(char board[SIZE][SIZE], char *filename) {
  FILE *fp = fopen(filename, "r"); // reads file
  if (!fp) {
    printf("Error: could not open file\n"); // error if file does not exist
    return 1;
  }

  char choice; // marks a or p on file
  int y; // row
  int x; // column
  while (1) {
    fscanf(fp, "%c", &choice); // scans letter of file
    // adds X to specified row and column
    // increments x and y by 1 so that it agrees with initial conditions of display
    if (choice == 'a') {
      fscanf(fp, "%d %d", &x, &y);
      addCell(board, x+1, y+1);
    }
    // stops while loop
    else if (choice == 'p')
      break;
  }
  // continously runs simulation until force quit
  playGame(board);
  fclose(fp); 
  return 0;
}
