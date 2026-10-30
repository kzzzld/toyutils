#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  // check is there any arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s directoryname\n", argv[0]);
    return 1;
  }

  char *dirName = argv[1];

  if (mkdir(dirName, 0777) == -1) {
    perror(dirName);
    return 1;
  }

  return 0;
}
