//
//  CSAPPRio_t.h
//  FirstC
//
//  Created by jyrnan on 2022/11/23.
//

#ifndef CSAPPRio_t_h
#define CSAPPRio_t_h

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#endif /* CSAPPRio_t_h */

#define RIO_BUFSIZE 8192

typedef struct {
    int rio_fd;
    int rio_cnt;
    int *rio_bufptr;
    int rio_buf[RIO_BUFSIZE];
} rio_t;

void rio_readinitb(rio_t *rp, int fd);
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
int demodirop(int argc, char **argv);
