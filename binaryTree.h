//
//  binaryTree.h
//  FirstC
//
//  Created by Yong Jin on 2022/4/19.
//

#ifndef binaryTree_h
#define binaryTree_h

#define SLEN 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char petname[SLEN];
    char petkind[SLEN];
} Item;

typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
}Trnode;

typedef struct tree {
    Trnode * root;
    int size;
} Tree;

typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

void InistializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

bool TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree);

bool DeleteItem(const Item * pi, Tree * ptree);

#endif /* binaryTree_h */
