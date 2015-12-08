/* Solution for Day 2a for adventofcode.com Puzzles!
 * by Alan Estrada
 * 
 * If programmers don't code Christmas puzzles, Krampus
 * will come and delete your github account! Spooky!
 */

#include <stdio.h>
#include <stdlib.h>

/* Note, to save the pain of string parsing, I just
   did a sed and removed all x's in the input! */
int main(int argc, char *argv[]) {
  int w, l, h, lw, wh, hl;
  int smallestArea, totalPaper = 0;
  FILE *fp;

  if (argc != 2) {
    printf( "Incorrect number of args, give me an input file!\n");
    return -1;
  }

  fp = fopen(argv[1], "r");

  if (!fp) {
    printf("Uh, invalid file bro.\n");
  }

  while (fscanf(fp, "%d %d %d", &w, &l,  &h) != EOF) {
    smallestArea = lw = l*w;

    if (smallestArea > (wh = w*h)) {
      smallestArea = wh;
    }

    if (smallestArea > (hl = h*l)) {
      smallestArea = hl;
    }

    totalPaper += 2*lw + 2*wh + 2*hl + smallestArea;
  }

  printf("Y'all need to go to Staples and get %d sq feet of wrapping paper!\n", totalPaper);

  return 0;
}
