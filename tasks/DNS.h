#ifndef INC_2SEM8LAB_DNS_H
#define INC_2SEM8LAB_DNS_H

#include "../structures/hashTable.h"
#include "../etc/Input.h"
#include <iostream>
#include <fstream>

void readDataFromFile(struct HashTable* table, char* filepath);
void printTable(struct HashTable* table, char* filepath);
void findIP(struct HashTable* table, char* filepath);
void addRecord(struct HashTable* table, char* filepath);
void deleteRecord(struct HashTable* table, char* filepath);
void deleteByValue(struct HashTable* table, char* filepath);
void saveHashmapToFile(struct HashTable* table, char* filepath);

#endif //INC_2SEM8LAB_DNS_H
