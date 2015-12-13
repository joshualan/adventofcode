/* Solution for Day 2b for adventofcode.com Puzzles!
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
  int smallestPerim, totalRibbon = 0;
  FILE *fp;

  if (argc != 2) {
    printf( "Incorrect number of args, give me an input file!\n");
    return -1;
  }

  fp = fopen(argv[1], "r");

  if (!fp) {
    printf("Uh, invalid file bro.\n");
    return -1;
  }

  while (fscanf(fp, "%d %d %d", &w, &l,  &h) != EOF) {
    smallestPerim = lw = l*2 + w*2;

    if (smallestPerim > (wh = w*2 + h*2)) {
      smallestPerim = wh;
    }

    if (smallestPerim > (hl = h*2 + l*2)) {
      smallestPerim = hl;
    }

    totalRibbon += l*w*h + smallestPerim;
  }

  printf("Y'all need to go to Staples and get %d sq feet of ribbon!\n", totalRibbon);

  return 0;
}
