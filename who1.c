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

#define SHOWHOST

int who1(void) {
    struct utmp current_record;
}
