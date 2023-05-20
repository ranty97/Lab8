#include "DNS.h"

int lastCur = 0;

void readDataFromFile(struct HashTable *table, char *filepath) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Couldn't open file" << std::endl;
        return;
    }

    file.seekg(lastCur, std::ios::beg);
    int counter;
    std::string domain, ip;

    std::cout << "Amount of lines: ";
    std::cin >> counter;

    while (!file.eof() && counter > 0 && std::getline(file, domain, ':').good()) {
        std::getline(file, ip, '\n');
        ip = ip.substr(0, ip.length() - 1);
        char *dmn = (char *) malloc(domain.size());
        char *addr = (char *) malloc(ip.size());
        strcpy(dmn, domain.c_str());
        strcpy(addr, ip.c_str());
        pushHashTableValue(table, dmn, addr);
        counter--;
    }

    lastCur = (int) file.tellg();

    file.close();
}

void printTable(struct HashTable *table, char *filepath) {
    printHashTable(table);
}

void findIP(struct HashTable *table, char *filepath) {
    char *domain = scanString();

    char *value = getHashTableValue(table, domain);
    if (value) {
        std::cout << value;
    } else {
        std::cout << "Not found";
    }
}

void addRecord(struct HashTable *table, char *filepath) {
    char *domain;
    char *ip;

    std::cout << "Domain: ";
    domain = scanString();
    std::cout << "IP address: ";
    ip = scanString();

    pushHashTableValue(table, domain, ip);
}

void deleteRecord(struct HashTable *table, char *filepath) {
    char *domain;

    std::cout << "Domain: ";
    domain = scanString();

    removeHashTableValue(table, domain);
}


void deleteByValue(struct HashTable *table, char *filepath) {
    std::cout << "Value: ";
    char *value = scanString();
    int counter = 0;
    for (int i = 0; i < table->size; i++) {
        struct ListNode *temp = table->nodes[i];
        while (temp && (unsigned long long int) (temp) != 0xfeeefeeefeeefeee) {
            if (!strcmp(temp->value, value)) {
                removeListElement(&table->nodes[i], temp);
                counter++;
            }
            temp = temp->next;
        }
    }

    std::cout << "Deleted " << counter << " records";
}

void saveHashmapToFile(struct HashTable *table, char *filepath) {
    std::cout << "Filepath: ";

    char *filename = scanString();

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "File error";
        return;
    }

    for (int i = 0; i < table->size; i++) {
        struct ListNode *temp = table->nodes[i];
        while (temp) {
            file << temp->key << ":" << temp->value << std::endl;
            temp = temp->next;
        }
    }

    file.close();
}