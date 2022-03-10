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
#include <stdlib.h>
#include "dvdTracker.h"

char            GetCommand( void );
struct DVDInfo *ReadStruct( void );
void            AddToList( struct DVDInfo *curPtr );
void            ListDVDs( void );
char            *TrimLine( char *line );

static struct DVDInfo *gHeadPtr, *gTailPtr;

int main(int argc, const char * argv[]) {
    
    char command;
    
    while ( (command = GetCommand()) != 'q' ) {
        
        switch ( command ) {
            case 'n':
                AddToList( ReadStruct() );
                break;
            case 'l':
                ListDVDs();
                break;
        }
        
        printf("\n----------\n");
    }
    
    printf("Goodbye...\n");
    
    return 0;
}

char GetCommand( void ) {
    
    char buffer[ 100 + 1 ];
    printf( "Enter command (q=quit, n=new, l=list): " );
    fgets( buffer, sizeof(buffer), stdin );
    
    return *TrimLine( buffer );
}

struct DVDInfo *ReadStruct( void ) {
    
    struct DVDInfo *infoPtr;
    infoPtr = malloc( sizeof( struct DVDInfo ) );
    
    char buffer[ 500 + 1 ];
    printf( "Enter DVD title: ");
    fgets( buffer, sizeof( buffer ), stdin);
    strlcpy(infoPtr->title, TrimLine(buffer), sizeof(infoPtr->title));
    
    printf( "Enter DVD comment: ");
    fgets( buffer, sizeof( buffer ), stdin);
    strlcpy(infoPtr->comment, TrimLine(buffer), sizeof(infoPtr->comment));
    
    int num;
    do {
        printf( "Enter DVD Rating (1-10): " );
        fgets( buffer, sizeof( buffer ), stdin );
        num = atoi( TrimLine( buffer ) );
    }
    while ( ( num < 1 ) || ( num > 10 ));
    
    infoPtr->rating = num;
    
    return ( infoPtr );
}

void AddToList( struct DVDInfo *curPtr ) {
    
    if ( gHeadPtr == NULL)
        gHeadPtr = curPtr;
    else
        gTailPtr->next = curPtr;
    
    gTailPtr = curPtr;
    curPtr->next = NULL;
}

void ListDVDs( void ) {
    
    struct DVDInfo *curPtr;
    
    if( gHeadPtr == NULL) {
        printf( "No DVDs been entered yet...\n");
    } else {
        for (curPtr = gHeadPtr; curPtr != NULL; curPtr = curPtr->next) {
            if ( curPtr != gHeadPtr )
                printf("---------\n");
            printf( "Title: %s\n", curPtr->title);
            printf( "Comment: %s\n", curPtr->title);
            printf( "Rating: %d\n", curPtr->rating);
        }
    }
}

char *TrimLine( char *line ) {
    
    size_t length = strlen( line );
    
    while ( length > 0 && isspace( line[length - 1])) {
        line[length - 1] = '\0';
        length--;
    }
    
    char *head = line;
    while ( isspace( *head )){
        head++;
    }
    
    return head;
}
