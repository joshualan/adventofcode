/* Solution for Day 6b for adventofcode.com Puzzles!
 * by Alan Estrada
 * 
 * If programmers don't code Christmas puzzles, Krampus
 * will come and delete your github account! Spooky!
 */

#include <stdio.h>
#include <stdlib.h>


/* Could've used an enum for this but let's not over-engineer */
#define ON 1
#define OFF 2
#define TOGGLE 3

void switchLights(int grid[][1000], 
		  int upperX, int upperY,
		  int lowerX, int lowerY,
		  int mode) {
  int x, y;
  
  for (x = upperX; x <= lowerX; x++) {
    for (y = upperY; y <= lowerY; y++) {
      switch (mode) {
      case ON:
	grid[y][x]++;
	break;
      case OFF:
	grid[y][x] = !grid[y][x] ? 0 : grid[y][x] - 1 ;
	break;
      case TOGGLE:
	grid[y][x] = grid[y][x] + 2;
	break;
      }
    }
  }

  return ;
}

int main(int argc, char *argv[]) {
  FILE *fp;

  int grid[1000][1000] = {0};
  char modeBuf[10];
  int mode;
  int upperX, upperY;
  int lowerX, lowerY;
  int x, y;
  int totalBrightness = 0; 

  if (argc != 2) {
    printf( "Incorrect number of args, give me an input file!\n" );
    return -1;
  }

  fp = fopen(argv[1], "r");

  /* Cheated and edited the file to make it easier to parse ;)
     But it's Christmas so whatever! */
  while (fscanf(fp, "%s %d,%d %d,%d", 
		modeBuf, &upperX, &upperY, &lowerX, &lowerY) !=  EOF) {

    /* Lazy but efficient right here. */
    switch (modeBuf[1]) {
    case 'n':
      mode = ON;
      break;
    case 'f':
      mode = OFF;
      break;
    case 'o':
      mode = TOGGLE;
      break;
    }

    switchLights(grid, upperX, upperY, lowerX, lowerY, mode);
  }

  for (x = 0; x < 1000 ; x++) {
    for (y = 0 ; y < 1000; y++) {
      totalBrightness += grid[y][x]; 
    }
  }
		
  printf( "Your Nordic Elvish light display has %d brightness!\n", totalBrightness) ;
  return 0;
}
