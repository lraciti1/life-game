// Lucia Raciti
// Fundamentals of Computing
// 11/5/24
// header file to the Conway's Game of Life simulation

#define SIZE 41 // defines size of array as global variable

void Setup(char [SIZE][SIZE]);
void display(char [SIZE][SIZE]);
void addCell(char [SIZE][SIZE], int, int);
void removeCell(char [SIZE][SIZE], int, int);
int CountNeighbors(char [SIZE][SIZE], int, int);
void advanceSim(char [SIZE][SIZE]);
void playGame(char [SIZE][SIZE]);
int interactiveMode(char [SIZE][SIZE]);
int batchMode(char [SIZE][SIZE], char *);
