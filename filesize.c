//
//  filesize.c
//  FirstC
//
//  Created by jyrnan on 2022/12/1.
//

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    
    struct stat infobuf;
    if (stat("/etc/passwd", &infobuf) == -1)
        perror("/etc/passwd");
    else
        printf("The size of /etc/passwd is %d\n", infobuf.st_size);
}
