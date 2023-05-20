#include "hashTable.h"

int hash(char *key) {
    int result = 7;
    for (int i = 0; key[i]; i++) {
        result *= 31;
        result += key[i];
    }

    return result;
}

int getIndex(struct HashTable *table, char *key) {
    return abs(hash(key)) % table->size;
}

struct HashTable *createHashTable(int size) {
    struct HashTable *temp = (struct HashTable *) malloc(sizeof(struct HashTable));
    temp->nodes = (struct ListNode **) calloc(size, sizeof(struct ListNode **));
    temp->size = size;

    return temp;
}

char *getHashTableValue(struct HashTable *table, char *key) {
    struct ListNode *temp = table->nodes[getIndex(table, key)];

    while (temp != NULL && strcmp(temp->key, key) != 0) {
        temp = temp->next;
    }

    return temp ? temp->value : NULL;
}

void removeHashTableValue(struct HashTable *table, char *key) {

    struct ListNode **list = table->nodes + getIndex(table, key);
    struct ListNode *temp = *list;

    while (temp != NULL && strcmp(temp->key, key) != 0) {
        temp = temp->next;
    }

    if (temp)
        removeListElement(list, temp);
}

void pushHashTableValue(struct HashTable *table, char *key, char *value) {
    struct ListNode *temp = table->nodes[getIndex(table, key)];

    while (temp != NULL && strcmp(temp->key, key) != 0) {
        temp = temp->next;
    }

    if (temp != NULL) {
        temp->value = value;
    } else {
        pushListElement(&table->nodes[getIndex(table, key)], key, value);
    }
}

void printHashTable(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        std::cout << i << ": ";
        printList(table->nodes[i]);
        std::cout << std::endl;
    }
}