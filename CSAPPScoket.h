//
//  CSAPPScoket.h
//  FirstC
//
//  Created by jyrnan on 2022/11/20.
//

#ifndef CSAPPScoket_h
#define CSAPPScoket_h

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IP_ADDR_LOCAL "127.0.0.1"
#define IP_ADDR_MASK "255.255.255.255"


#endif /* CSAPPScoket_h */

void testIP_Addr(void);
int hostinfo(int, char **);
