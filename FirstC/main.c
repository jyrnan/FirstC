//
//  main.c
//  FirstC
//
//  Created by Yong Jin on 2022/3/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "CSAPPScoket.h"
#include "CSAPPRio_t.h"

#define MAXTITL 41
#define LEN 81

void ToUpper(char *);
int more02(int ac, const char* av[]);
void showtime(long timeval);

int main(int argc, const char * argv[]) {
    showtime(200000000);
    return  0;
}

//test for Git push
