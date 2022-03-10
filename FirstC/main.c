//
//  main.c
//  FirstC
//
//  Created by Yong Jin on 2022/3/10.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define kMaxLineLength 200

void ReadLine( char *buff );
int CountWords( char *line );

int main(int argc, const char * argv[]) {
    
    char line[ kMaxLineLength ];
    int numWords;
    
    ReadLine( line );
    numWords = CountWords( line );
    
    printf("\n---- This line has %d word%s ---\n", numWords, (numWords != 1 ? "s" : ""));
    
    printf("%s\n", line);
    
    return 0;
}

void ReadLine(char *buff) {
    
    int numCharsread = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n' && ++numCharsread <= kMaxLineLength) {
        *buff++ = c; //*buff
    }
    *buff = '\0';
}

int CountWords( char *line ) {
    int numWords, inWord;
    
    numWords = 0;
    inWord =false;
    
    while ( *line != 0){
        
        if (isspace(*line)) {
            inWord = false;
        } else {
            if (! inWord) {
                numWords++;
                inWord = true;
            }
        }
        
        line++;
    }
    return numWords;
}
