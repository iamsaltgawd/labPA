#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#pragma once

typedef struct node_t {
    char type;
    int num;
    struct node_t *left, *right;
} Node;

Node* createNode(char type, int num);
Node* createTree();
void preorder(Node *root);
void displayleaves();
void parcurgere_preordine(Node *current, int pas, char *v);
void parcurgere_preordine_p2(Node *current, int pas, char *v, Node_l **cai);
void displaypaths();