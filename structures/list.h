#ifndef INC_2SEM8LAB_LIST_H
#define INC_2SEM8LAB_LIST_H

#include <stdlib.h>
#include <iostream>

struct ListNode {
    char* key;
    char* value;
    struct ListNode* next;
};

void removeListElement(struct ListNode** list, struct ListNode* element);
void pushListElement(struct ListNode** list, char* key, char* value);

void printList(struct ListNode* list);

#endif //INC_2SEM8LAB_LIST_H
