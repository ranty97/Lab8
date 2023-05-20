#include "benchmark.h"

char *generateRandomString(int size) {
    char *temp = (char *) malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
        temp[i] = ('a' + std::rand() % ('z' - 'a' + 1));
    }

    temp[size] = '\0';

    return temp;
}

struct ListNode *generateRandomKeyArray(int size) {
    struct ListNode *result = NULL;
    for (int i = 0; i < size; i++) {
        pushListElement(&result, generateRandomString(10), generateRandomString(5));
    }

    return result;
}

int getPerformanceTime(void ownFunc(struct ListNode *list, struct HashTable *),
                       void builtInFunc(struct ListNode *list, std::unordered_map<char *, char *> map),
                       struct ListNode *list, struct HashTable *table, std::unordered_map<char *, char *> map) {
    clock_t start, end;
    start = clock();
    ownFunc(list, table);
    end = clock();
    long int ownResult = end - start;
    printf("My implementation: %ld\n", ownResult);
    start = clock();
    builtInFunc(list, std::move(map));
    end = clock();
    long int builtInResult = end - start;
    printf("Built-in implementation: %ld\n", builtInResult);
    printf("K = %f\n\n", (float) ownResult / builtInResult);
    return end - start;
}

void WriteOwn(struct ListNode *list, struct HashTable *table) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        pushHashTableValue(table, temp->key, temp->value);
    }
}

void WriteBuiltIn(struct ListNode *list, std::unordered_map<char *, char *> map) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        map[temp->key] = temp->value;
    }
}

void ReadOwn(struct ListNode *list, struct HashTable *table) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        char *tmp = getHashTableValue(table, temp->key);
    }
}

void ReadBuiltIn(struct ListNode *list, std::unordered_map<char *, char *> map) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        char *tmp = map[temp->key];
    }
}

void EditOwn(struct ListNode *list, struct HashTable *table) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        pushHashTableValue(table, temp->key, "aboba");
    }
}

void EditBuiltIn(struct ListNode *list, std::unordered_map<char *, char *> map) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        map[temp->key] = "aboba";
    }
}

void RemoveOwn(struct ListNode *list, struct HashTable *table) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        removeHashTableValue(table, temp->key);
    }
}

void RemoveBuiltIn(struct ListNode *list, std::unordered_map<char *, char *> map) {
    struct ListNode *temp = list;

    for (; temp != NULL; temp = temp->next) {
        map.erase(temp->key);
    }
}


void checkPerformance(struct HashTable *tbl, char *filepath) {
    int tableSize, dataSetSize;

    std::cout << "Table size: ";
    std::cin >> tableSize;
    std::cout << "Dataset size: ";
    std::cin >> dataSetSize;

    std::srand(time(NULL));

    struct ListNode *list = generateRandomKeyArray(dataSetSize), *temp;

    struct HashTable *table = createHashTable(tableSize);
    std::unordered_map<char *, char *> map;

    printf("==========Write==========\n");
    getPerformanceTime(&WriteOwn, &WriteBuiltIn, list, table, map);

    printf("==========Read==========\n");
    getPerformanceTime(&ReadOwn, &ReadBuiltIn, list, table, map);

    printf("==========Edit==========\n");
    getPerformanceTime(&EditOwn, &EditBuiltIn, list, table, map);

    printf("==========Remove==========\n");
    getPerformanceTime(&RemoveOwn, &RemoveBuiltIn, list, table, map);


    printf("Deleting dataset list...");

    while (list != NULL) {
        free(list->key);
        free(list->value);
        removeListElement(&list, list);
    }
}