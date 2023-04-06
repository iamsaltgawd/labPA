#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#pragma once

typedef struct data{
    char *path;
    int id, pas;
} Data;

typedef struct node {
    Data frunza;
    struct node* next;
} Node_l;

void addAtBeginning(Node_l **head, Data v);

void addAtEnd(Node_l** head, Data v);

void display(Node_l *head);