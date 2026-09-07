#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
  DIR *dir;
  struct dirent *dent;

  int has_l = (argc > 1 && strcmp(argv[1], "-l") == 0);
  char *sep = has_l ? "\n" : " ";
  
  int path_idx = has_l ? 2 : 1;
  
  char *path = (argc > path_idx) ? argv[path_idx] : ".";

  dir = opendir(path);

  if(dir != NULL) {
    while ((dent = readdir(dir)) != NULL) {
      if (*dent->d_name == '.') {
      } else {
        printf("%s%s", dent->d_name, sep);
      }
    }
    if (!has_l) printf("\n");
    closedir(dir);
  }

  return 0;
}
