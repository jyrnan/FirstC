//
//  binaryTree.c
//  FirstC
//
//  Created by Yong Jin on 2022/4/19.
//

#include "binaryTree.h"

static Trnode * MakeNode(const Item * pi);
static void AddNode(Trnode * new_node, Trnode * root);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static Pair SeekItem(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);

static void InOrder(const Trnode * root, void(*pfun)(Item item)) ;

static void DeleteNode(Trnode ** ptr);

void InistializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

bool TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree) {
    Trnode * new_node;
    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Tree is full");
        return  false;
    }
    
    if (SeekItem(pi, ptree).child != NULL) {
        fprintf(stderr, "Attemped to add duplicate item\n");
        return false;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't created item\n");
        return false;
    }
    
    ptree->size++;
    if (ptree->root == NULL) {
        ptree->root = new_node;
    } else {
        AddNode(new_node, ptree->root);
    }
    
    return true;
}

bool InTree(const Item * pi, const Tree * ptree) {
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree);


static Trnode * MakeNode(const Item * pi) {
    Trnode * new_node;
    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static void AddNode(Trnode * new_node, Trnode * root) {
    if (ToLeft(&new_node->item, &root->item)) {
        if  (root->left == NULL) {
            root->left = new_node;
        } else {
            AddNode(new_node, root->left);
        }
    } else if (ToRight(&new_node->item, &root->item)) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            AddNode(new_node, root->right);
        }
    } else {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2) {
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2) {
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}

static Pair SeekItem(const Item * pi, const Tree * ptree) {
    Pair look;
    look.parent = NULL;;
    look.child = ptree->root;
    if (look.child == NULL)
        return look;
    while (look.child != NULL) {
        if (ToLeft(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }
    return look;
}

static void DeleteNode(Trnode ** ptr) {
    Trnode * temp;
    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for (temp == (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

bool DeleteItem(const Item * pi, Tree * ptree) {
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return  false;
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;
    
    return true;
}

void Traverse(const Tree * ptree, void(*pfun)(Item item)) {
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

static void InOrder(const Trnode * root, void(*pfun)(Item item)) {
    if (root != NULL) {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}
