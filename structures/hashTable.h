//
// Created by dmitr on 03.05.2023.
//

#ifndef INC_2SEM8LAB_HASHTABLE_H
#define INC_2SEM8LAB_HASHTABLE_H

#include <stdio.h>
#include <iostream>
#include "list.h"
#include <string.h>

struct HashTable {
    struct ListNode** nodes;
    int size;
};

struct HashTable* createHashTable(int size);
char* getHashTableValue(struct HashTable* table, char* key);
void removeHashTableValue(struct HashTable* table, char* key);
void pushHashTableValue(struct HashTable* table, char* key, char* value);
void printHashTable(struct HashTable* table);

#endif //INC_2SEM8LAB_HASHTABLE_H
