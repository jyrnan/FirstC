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

#define MAXTITL 41
#define LEN 81

void ToUpper(char *);

int main(int argc, const char * argv[]) {
    
    short int v = -12345;
    unsigned  short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v, uv);
    
    return 0;
}

//test for Git push
