#include <stdio.h>

int main(int argc, char *argv[]) {

  char *usage = "Usage: %s [fileName]";

  // check is there any parameters
  if (argc < 2) {
    fprintf(stderr, usage, argv[0]);
    return 1;
  }

  char *fileName = argv[1];

  FILE *file = fopen(fileName, "r");

  // check is file loaded correctly
  if (file == NULL) {
    perror(fileName);
    return 1;
  }

  int character;
  while ((character = fgetc(file)) != EOF) {
    putchar(character);
  }

  return 0;
}
