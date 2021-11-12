#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // make mask to 777
    umask(0);
    // create a file diskriptor
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_EXCL, 0666);

    // check for errors
    if(fd < 0) {
        perror("Open() doens't work: ");
        return EXIT_FAILURE;
    }

    char *s = "Chris is there";

    // write text to file
    if(write(fd, s, strlen(s)) < 0) {
        perror("Write doesn't work: ");
        return EXIT_FAILURE;
    }

    close(fd);

    // rename file
    rename("/home/chris/Desktop/files/file.txt",  "other.txt");

    return EXIT_SUCCESS;
}
