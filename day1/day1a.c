#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char c;
  int floor = 0;

  if (argc != 2) {
    printf( "Incorrect # of args.\n");
    return -1;
  }

  fp = fopen(argv[1], "r");

  if (!fp) {
    printf("File not found\n");
    return -1;
  }

  while (fscanf(fp, "%c", &c) != EOF) {
    if (c == '(') {
      floor++;
    }
    else if (c == ')')  {
      floor--;
    }
  }

  printf( "Santa's ends up at floor %d!\n", floor);
  return 0;

}
