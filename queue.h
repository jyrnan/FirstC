//
//  queue.h
//  FirstC
//
//  Created by Yong Jin on 2022/4/19.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node * front;
    Node * rear;
    int items;
} Queue;


void InitializeQueue(Queue * pq);

bool QueueIsFull(const Queue * pq);

bool QueueIsEmpty(const Queue * pq);

int QueueItemCount(const Queue * pq);

bool EnQueue(Item item, Queue * pq);

bool DeQueue(Item *pitem, Queue * qp);

void EmptyTheQueue(Queue * pq);

#endif /* queue_h */

