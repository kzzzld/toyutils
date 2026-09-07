#include <unistd.h>
#include <stdio.h>

int main() {
  char wd[1000];
  printf("%s \n", getcwd(wd,sizeof(wd)));

  return 0;
}
