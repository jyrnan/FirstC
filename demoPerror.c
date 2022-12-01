//
//  demoPerror.c
//  FirstC
//
//  Created by jyrnan on 2022/11/30.
//

#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>

int main(void) {
    int fd;
    fd = open("file", O_RDONLY);
    if (fd == -1) {
        perror("Cannot open file");
        return -2;
    }
    
    return 0;
}
