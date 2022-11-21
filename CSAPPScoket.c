//
//  CSAPPScoket.c
//  FirstC
//
//  Created by jyrnan on 2022/11/20.
//

#include "CSAPPScoket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>



void testIP_Addr(void) {
    int result, result2;
    struct in_addr addr;
    struct in_addr addr2;
    result = inet_pton(AF_INET, IP_ADDR_LOCAL, &addr);
    result2 = inet_pton(2, IP_ADDR_MASK, &addr2);
    printf("%d\n", result);
    if (result)
        printf("%x2\n", ntohl(addr.s_addr));
    if (result2)
        printf("%x\n", addr2.s_addr);
    
    char *back;
    back = inet_ntoa(addr);
    printf("%s\n",back);
    
    char *str = "hello world\n";
    printf("%s", str);
    
    struct sockaddr_in addr3;
    
    int clientID;
    clientID = socket(AF_INET, SOCK_STREAM, 0);
    printf("%d\n", clientID);
    
    bind(clientID, &addr3, sizeof(addr3));
   
}

int hostinfo(int arc, char **argv) {
    
//    printf("有%d个参数：\n", arc);
//    for (int i=0; i < arc; i++) {
//
//            printf("%s\n", *(argv+i));
//    }
    
    struct addrinfo *p, *listp, hints;
    char buffer[1024];
    int rc, flags;
    void *none;
    
    if (arc != 2) {
        fprintf(stderr, "Usage: %s <domain name> \n", argv[0]);
    }
    
//    none = memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo erro: %s\n", gai_strerror(rc));
        return -1;
    }
    
    flags = NI_NUMERICHOST;
    for (p = listp; p; p = p->ai_next) {
        getnameinfo(p->ai_addr, p->ai_addrlen, buffer, 1024, NULL, 0, flags);
        printf("%s\n", buffer);
    }
    
    freeaddrinfo(listp);
    
    return 0;
}

int open_clientfd(char *hostname, char *port) {
    int clientfd;
    struct addrinfo hints, *listp, *p;
    
//    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICHOST;
    hints.ai_flags |= AI_ADDRCONFIG;
    getaddrinfo(hostname, port, &hints, &listp);
    
    for (p = listp; p; p = p->ai_next) {
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) continue;
        
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
            break;
//        Close(clientfd);
    }
    
    freeaddrinfo(listp);
    if (!p)
        return -1;
    else
        return clientfd;
}

