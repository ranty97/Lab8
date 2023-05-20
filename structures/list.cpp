#include "list.h"

void removeListElement(struct ListNode **list, struct ListNode *element) {
    if (*list == NULL)
        return;

    struct ListNode *temp = *list;

    if (temp == element) {
        (*list) = temp->next;
        free(temp);
        return;
    }

    while (temp->next != element && temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        temp->next = temp->next->next;
        free(element);
    }
}

void pushListElement(struct ListNode **list, char *key, char *value) {
    struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
    temp->key = key;
    temp->value = value;
    temp->next = *list;

    (*list) = temp;
}

void printList(struct ListNode *list) {
    struct ListNode *temp = list;

    while (temp != NULL) {
        std::cout << "(\"" << temp->key << "\"=\"" << temp->value << "\") ";
        temp = temp->next;
    }
}