#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

// printf(USAGE, argv[0]);
const char *USAGE = "Usage: %s [source] [location]\n";

int main(int argc, char *argv[]) {

    // get arguments
    const char *srcpath  = argv[1];
    const char *destpath = argv[2];
    int is_move = 0;

    if (argc == 4 && strcmp(argv[1], "--mv") == 0) { // if there's --mv, make is_move 1
      is_move = 1;
      srcpath = argv[2];
      destpath = argv[3];
    } else if (argc == 3) {
      srcpath = argv[1];
      destpath = argv[2];
    } else {
      fprintf(stderr, USAGE, argv[0]);
      return 1;
    }

    // read file
    int srcfd = open(srcpath, O_RDONLY);

    // if there is no file let's quit the app
    if ( srcfd < 0 ) {
        perror("open");
        return 1;
    }

    // get permissions
    struct stat st;
    if (fstat(srcfd, &st) < 0) {
        perror("fstat");
        close(srcfd);
        return 1;
    }

    // create destination file
    int destfd = open(destpath, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
    if (destfd < 0) {
        perror("can't create destination file");
        close(srcfd);
        return 1;
    }

    // write file
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // if there's a byte to write, do it
    while ((bytes_read = read(srcfd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destfd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write error");
            close(srcfd);
            close(destfd);
            return 1;
        }
    }

    if (bytes_read < 0) {
        perror("read file error");
    }

    close(srcfd);
    close(destfd);

    // if there's move flag, just remove main file
    if (is_move) {
        if (unlink(srcpath) < 0) {
          perror("unlink error");
          return 1;
        }
    }

    return 0;
}
