//
//  main.c
//  FirstC
//
//  Created by Yong Jin on 2022/3/10.
//

#include <stdio.h>

void SayHello( void );

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int i;
    
    for ( i = 1; i < 10; i++ )
        SayHello();
    return 0;
}

void SayHello ( void ) {
    printf("Hello Jinyong.\n");
}
