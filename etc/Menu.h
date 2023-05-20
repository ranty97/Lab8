#ifndef MenuHeader
#define MenuHeader

typedef struct MenuElement {
    const char* desc;
    void (*func)(struct HashTable* table, char* filepath);
} MenuElement;

typedef struct Menu {
    MenuElement* list;
    int size;
} Menu;


void startMenu(Menu menu, char* filepath);

#endif