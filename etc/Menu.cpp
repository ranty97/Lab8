#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Menu.h"
#include <iostream>
#include "../structures/hashTable.h"

void startMenu(Menu menu, char* filepath) {
    int size;
    std::cout << "Configure hashtable size: ";
    std::cin >> size;

    struct HashTable* table = createHashTable(size);

	while (1) {
        rewind(stdin);
		system("cls");
		printf("[0] Exit\n");
		for (int i = 0; i < menu.size; i++) {
			printf("[%d] %s\n", i + 1, menu.list[i].desc);
		}

		printf("Choose operation: ");
		int ind, size;

		char* inp = scanString();

		if (sscanf(inp, "%d %1[^\n]", &ind, &ind) != 1) continue;

		if (ind > menu.size || ind < 0) {
			continue;
		}
		else if (ind == 0) {
			break;
		} else {

			system("cls");

			menu.list[ind - 1].func(table, filepath);
			
			printf("\nPress any key to continue");
			system("pause > nil");
		}
	}
}