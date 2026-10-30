#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    return 1;
  }

  char *fileName = argv[1];

  FILE *file = fopen(fileName, "a");

  if (file == NULL) {
    perror(fileName);
    return 1;
  }

  fclose(file);

  return 0;
}
