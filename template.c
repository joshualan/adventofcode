/* Solution for Day __ for adventofcode.com Puzzles!
 * by Alan Estrada
 * 
 * If programmers don't code Christmas puzzles, Krampus
 * will come and delete your github account! Spooky!
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;

  if (argc != 2) {
    printf( "Incorrect number of args, give me an input file!\n");
    return -1;
  }

  fp = fopen(argv[1], "r");

  if (!fp) {
    printf("Uh, invalid file bro.\n");
  }

  return 0;
}
