//
//  who1.c
//  FirstC
//
//  Created by jyrnan on 2022/11/28.
//

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST

void showtime(long timeval) {
    char *cp;
    cp = ctime(&timeval);
    
    printf("%s\n", cp);
}
