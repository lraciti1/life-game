// Lucia Raciti
// Fundamentals of Computing
// 11/5/24
// playlife.c is the main driver that runs the functions for Conway's game of life

// libraries
#include <stdio.h>
#include "lifefunc.h"
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  // initial conditions
  char board[SIZE][SIZE]; // initial board
 
  Setup(board); // sets up display
  display(board);

  // interactive mode
  if (argc == 1) interactiveMode(board);
  else if (argc == 2) {
  // if file is in command, runs batch mode
    batchMode(board, argv[1]);
  }
  // if argc > 2
  else printf("Argument is too large\n");


  return 0;
}
